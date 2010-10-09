/*
 * Copyright 2010 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can
 * be found in the LICENSE file.
 */

#ifndef NATIVE_CLIENT_SERVICE_RUNTIME_NACL_SIGNAL_H__
#define NATIVE_CLIENT_SERVICE_RUNTIME_NACL_SIGNAL_H__ 1

/*
 * The nacl_signal module is provides a platform independent mechanism for
 * trapping signals encountered while running a Native Client executable.
 */

#include "native_client/src/include/nacl_base.h"
#include "native_client/src/trusted/service_runtime/sel_ldr.h"

EXTERN_C_BEGIN

extern struct NaClApp *g_SignalNAP;

enum NaClSignalResult {
  NACL_SIGNAL_SEARCH,   /* Try the our handler or OS */
  NACL_SIGNAL_SKIP,     /* Skip our handlers and try OS */
  NACL_SIGNAL_RETURN    /* Skip all other handlers and return */
};

typedef enum NaClSignalResult (*NaClSignalHandler)(int untrusted,
                                                   int signal_number,
                                                   void *ctx);
/*
 * Allocates a stack suitable for passing to
 * NaClSignalStackRegister(), for use as a stack for signal handlers.
 * This can be called in any thread.
 * Stores the result in *result; returns 1 on success, 0 on failure.
 */
int NaClSignalStackAllocate(void **result);

/*
 * Deallocates a stack allocated by NaClSignalStackAllocate().
 * This can be called in any thread.
 */
void NaClSignalStackFree(void *stack);

/*
 * Registers a signal stack for use in the current thread.
 */
void NaClSignalStackRegister(void *stack);

/*
 * Undoes the effect of NaClSignalStackRegister().
 */
void NaClSignalStackUnregister(void);

/*
 * Register process-wide signal handlers.
 */
void NaClSignalHandlerInit(void);

/*
 * Undoes the effect of NaClSignalHandlerInit().
 */
void NaClSignalHandlerFini(void);

/*
 * Provides a signal safe method to write to stderr.
 */
ssize_t NaClSignalErrorMessage(const char *str);

/*
 * Register NaClApp for use in the signal handler.
 */
void NaClSignalRegisterApp(struct NaClApp *nap);

/*
 * Add a signal handler to the front of the list.
 * Returns an id for the handler or return 0 on failure.
 * This function is not thread-safe and should only be
 * called at startup.
 */
int NaClSignalHandlerAdd(NaClSignalHandler func);


/*
 * A basic hanlder which will exit with -signal_number when
 * a signal is encountered.
 */
enum NaClSignalResult NaClSignalHandleAll(int untrusted,
                                          int signal_number,
                                          void *ctx);
/*
 * A basic hanlder which will exit with -signal_number when
 * a signal is encountered in the untrusted code, otherwise
 * the signal is passed to the next handler.
 */
enum NaClSignalResult NaClSignalHandleUntrusted(int untrusted,
                                                int signal_number,
                                                void *ctx);


/*
 * Traverse handler list, until a handler returns
 * NACL_SIGNAL_RETURN, or the list is exhausted, in which case
 * the signal is passed to the OS.
 */
enum NaClSignalResult NaClSignalHandlerFind(int untrusted,
                                            int signal_number,
                                            void *ctx);

/*
 * Platform specific code. Do not call directly.
 */
void NaClSignalHandlerInitPlatform(void);
void NaClSignalHandlerFiniPlatform(void);

EXTERN_C_END

#endif  /* NATIVE_CLIENT_SERVICE_RUNTIME_NACL_SIGNAL_H__ */
