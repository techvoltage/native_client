/*
 * Copyright (c) 2012 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <errno.h>
#include <linux/futex.h>
#include <signal.h>
#include <sys/syscall.h>

#include "native_client/src/shared/platform/nacl_check.h"
#include "native_client/src/shared/platform/nacl_exit.h"
#include "native_client/src/shared/platform/nacl_sync_checked.h"
#include "native_client/src/trusted/service_runtime/nacl_app_thread.h"
#include "native_client/src/trusted/service_runtime/nacl_globals.h"
#include "native_client/src/trusted/service_runtime/nacl_tls.h"
#include "native_client/src/trusted/service_runtime/sel_ldr.h"


/*
 * If |*addr| still contains |value|, this waits to be woken up by a
 * FutexWake(addr,...) call from another thread; otherwise, it returns
 * immediately.
 *
 * Note that if this is interrupted by a signal, the system call will
 * get restarted, but it will recheck whether |*addr| still contains
 * |value|.
 *
 * We use the *_PRIVATE variant to use process-local futexes which are
 * slightly faster than shared futexes.  (Private futexes are
 * well-known but are not covered by the Linux man page for futex(),
 * which is very out-of-date.)
 */
static void FutexWait(Atomic32 *addr, Atomic32 value) {
  if (syscall(SYS_futex, addr, FUTEX_WAIT_PRIVATE, value, 0, 0, 0) != 0) {
    /*
     * We get EWOULDBLOCK if *addr != value (EAGAIN is a synonym).
     * We get EINTR if interrupted by a signal.
     */
    if (errno != EINTR && errno != EWOULDBLOCK) {
      NaClLog(LOG_FATAL, "FutexWait: futex() failed with error %d\n", errno);
    }
  }
}

/*
 * This wakes up threads that are waiting on |addr| using FutexWait().
 * |waiters| is the maximum number of threads that will be woken up.
 */
static void FutexWake(Atomic32 *addr, int waiters) {
  if (syscall(SYS_futex, addr, FUTEX_WAKE_PRIVATE, waiters, 0, 0, 0) < 0) {
    NaClLog(LOG_FATAL, "FutexWake: futex() failed with error %d\n", errno);
  }
}

void NaClAppThreadSetSuspendState(struct NaClAppThread *natp,
                                  enum NaClSuspendState old_state,
                                  enum NaClSuspendState new_state) {
  while (1) {
    Atomic32 state = natp->suspend_state;
    if ((state & NACL_APP_THREAD_SUSPENDING) != 0) {
      /* We have been asked to suspend, so wait. */
      FutexWait(&natp->suspend_state, state);
      continue;  /* Retry */
    }

    CHECK(state == (Atomic32) old_state);
    if (CompareAndSwap(&natp->suspend_state, old_state, new_state)
        != (Atomic32) old_state) {
      continue;  /* Retry */
    }
    break;
  }
}

void NaClSuspendSignalHandler(void) {
  uint32_t tls_idx = NaClTlsGetIdx();
  struct NaClAppThread *natp = nacl_thread[tls_idx];

  /*
   * Indicate that we have suspended by setting
   * NACL_APP_THREAD_SUSPENDED.  We should not need an atomic
   * operation for this since the calling thread will not be trying to
   * change suspend_state.
   */
  if (natp->suspend_state != (NACL_APP_THREAD_UNTRUSTED |
                              NACL_APP_THREAD_SUSPENDING)) {
    NaClSignalErrorMessage("NaClSuspendSignalHandler: "
                           "Unexpected suspend_state\n");
    NaClAbort();
  }
  natp->suspend_state |= NACL_APP_THREAD_SUSPENDED;
  FutexWake(&natp->suspend_state, 1);

  /* Wait until we are asked to resume. */
  while (1) {
    Atomic32 state = natp->suspend_state;
    if ((state & NACL_APP_THREAD_SUSPENDED) != 0) {
      FutexWait(&natp->suspend_state, state);
      continue;  /* Retry */
    }
    break;
  }
}

/* Wait for the thread to indicate that it has suspended. */
static void WaitForUntrustedThreadToSuspend(struct NaClAppThread *natp) {
  const Atomic32 kBaseState = (NACL_APP_THREAD_UNTRUSTED |
                               NACL_APP_THREAD_SUSPENDING);
  while (1) {
    Atomic32 state = natp->suspend_state;
    if (state == kBaseState) {
      FutexWait(&natp->suspend_state, state);
      continue;  /* Retry */
    }
    if (state != (kBaseState | NACL_APP_THREAD_SUSPENDED)) {
      NaClLog(LOG_FATAL, "Unexpected state: %d\n", state);
    }
    break;
  }
}

void NaClUntrustedThreadSuspend(struct NaClAppThread *natp) {
  Atomic32 old_state;
  Atomic32 suspending_state;

  /*
   * Note that if we are being called from a NaCl syscall (which is
   * likely), natp could be the thread we are running in.  That is
   * fine, because this thread will be in the NACL_APP_THREAD_TRUSTED
   * state, and so we will not try to interrupt it.
   */

  /*
   * We do not want the thread to enter a NaCl syscall and start
   * taking locks when pthread_kill() takes effect, so we ask the
   * thread to suspend even if it is currently running untrusted code.
   */
  while (1) {
    old_state = natp->suspend_state;
    DCHECK((old_state & NACL_APP_THREAD_SUSPENDING) == 0);
    suspending_state = old_state | NACL_APP_THREAD_SUSPENDING;
    if (CompareAndSwap(&natp->suspend_state, old_state, suspending_state)
        != old_state) {
      continue;  /* Retry */
    }
    break;
  }
  /*
   * Once the thread has NACL_APP_THREAD_SUSPENDING set, it may not
   * change state itself, so there should be no race condition in this
   * check.
   */
  DCHECK(natp->suspend_state == suspending_state);

  if (old_state == NACL_APP_THREAD_UNTRUSTED) {
    if (pthread_kill(natp->thread.tid, NACL_THREAD_SUSPEND_SIGNAL) != 0) {
      NaClLog(LOG_FATAL, "NaClUntrustedThreadsSuspend: "
              "pthread_kill() call failed\n");
    }
    WaitForUntrustedThreadToSuspend(natp);
  }
}

void NaClUntrustedThreadResume(struct NaClAppThread *natp) {
  Atomic32 old_state;
  Atomic32 new_state;
  while (1) {
    old_state = natp->suspend_state;
    new_state = old_state & ~(NACL_APP_THREAD_SUSPENDING |
                              NACL_APP_THREAD_SUSPENDED);
    DCHECK((old_state & NACL_APP_THREAD_SUSPENDING) != 0);
    if (CompareAndSwap(&natp->suspend_state, old_state, new_state)
        != old_state) {
      continue;  /* Retry */
    }
    break;
  }

  /*
   * TODO(mseaborn): A refinement would be to wake up the thread only
   * if it actually suspended during the context switch.
   */
  FutexWake(&natp->suspend_state, 1);
}

/*
 * NaClUntrustedThreadsSuspend() ensures that any untrusted code is
 * temporarily suspended.
 *
 * If a thread is currently executing a NaCl syscall, we tell the
 * thread not to return to untrusted code yet.  If a thread is
 * currently executing untrusted code, we suspend it.
 *
 * This returns with the lock threads_mu held, because we need to pin
 * the list of threads.  NaClUntrustedThreadsResume() must be called
 * to undo this.
 */
void NaClUntrustedThreadsSuspendAll(struct NaClApp *nap) {
  size_t index;

  NaClXMutexLock(&nap->threads_mu);

  for (index = 0; index < nap->threads.num_entries; index++) {
    struct NaClAppThread *natp = NaClGetThreadMu(nap, (int) index);
    if (natp != NULL) {
      NaClUntrustedThreadSuspend(natp);
    }
  }
}

void NaClUntrustedThreadsResumeAll(struct NaClApp *nap) {
  size_t index;
  for (index = 0; index < nap->threads.num_entries; index++) {
    struct NaClAppThread *natp = NaClGetThreadMu(nap, (int) index);
    if (natp != NULL) {
      NaClUntrustedThreadResume(natp);
    }
  }

  NaClXMutexUnlock(&nap->threads_mu);
}