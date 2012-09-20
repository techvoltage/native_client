/*
 * Copyright (c) 2012 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "native_client/tests/thread_capture/thread_capture_test_injection.h"

#include "native_client/src/include/portability.h"
#include "native_client/src/shared/platform/nacl_log.h"
#include "native_client/src/trusted/service_runtime/include/bits/nacl_syscalls.h"
#include "native_client/src/trusted/service_runtime/sel_ldr.h"
#include "native_client/tests/thread_capture/arch/arm/nacl_test_capture_arm.h"

void NaClInjectThreadCaptureTrampoline(struct NaClApp *nap) {
  uintptr_t target_addr;

  NaClLog(LOG_WARNING, "Installing ThreadCapture test trampoline\n");

  UNREFERENCED_PARAMETER(nap);

  target_addr = nap->mem_start + NACL_SYSCALL_START_ADDR +
      NACL_sys_test_syscall_1 * NACL_SYSCALL_BLOCK_SIZE;
  NaClLog(4,
          ("NaClInjectThreadCaptureTrampoline: installing test_capture"
           " from %"NACL_PRIxPTR" to %"NACL_PRIxPTR"\n"),
          (uintptr_t) NaClTestCapture, target_addr);
  NaClPatchOneTrampolineCall((uintptr_t) NaClTestCapture,
                             target_addr);
}
