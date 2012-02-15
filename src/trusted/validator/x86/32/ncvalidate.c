/*
 * Copyright (c) 2012 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Implement the ApplyValidator API for the x86-32 architecture. */

#include "native_client/src/trusted/validator/ncvalidate.h"
#include "native_client/src/trusted/validator/x86/ncval_seg_sfi/ncvalidate.h"
#include "native_client/src/trusted/validator/x86/ncval_seg_sfi/ncvalidate_detailed.h"
#include <assert.h>

/* Be sure the correct compile flags are defined for this. */
#if NACL_ARCH(NACL_TARGET_ARCH) != NACL_x86
# error("Can't compile, target is for x86-32")
#else
# if NACL_TARGET_SUBARCH != 32
#  error("Can't compile, target is for x86-32")
# endif
#endif

static NaClValidationStatus NCApplyValidatorSilently_x86_32(
    uintptr_t guest_addr,
    uint8_t *data,
    size_t size,
    int bundle_size,
    NaClCPUFeaturesX86 *cpu_features) {
  struct NCValidatorState *vstate;
  int validator_result = 0;

  vstate = NCValidateInit(guest_addr, size, bundle_size, cpu_features);
  if (vstate == NULL) return NaClValidationFailedOutOfMemory;
  NCValidateSegment(data, guest_addr, size, vstate);
  validator_result = NCValidateFinish(vstate);
  NCValidateFreeState(&vstate);
  return (validator_result == 0)
      ? NaClValidationSucceeded : NaClValidationFailed;
}

NaClValidationStatus NCApplyValidatorStubout_x86_32(
    uintptr_t guest_addr,
    uint8_t *data,
    size_t size,
    int bundle_size,
    NaClCPUFeaturesX86 *cpu_features) {
  struct NCValidatorState *vstate;

  vstate = NCValidateInitDetailed(guest_addr, size, bundle_size, cpu_features);
  if (vstate == NULL) return NaClValidationFailedOutOfMemory;
  NCValidateSetStubOutMode(vstate, 1);
  NCValidateSegment(data, guest_addr, size, vstate);
  NCValidateFinish(vstate);
  NCValidateFreeState(&vstate);
  return NaClValidationSucceeded;
}

NaClValidationStatus NACL_SUBARCH_NAME(ApplyValidator, NACL_TARGET_ARCH, 32) (
    enum NaClSBKind sb_kind,
    NaClApplyValidationKind kind,
    uintptr_t guest_addr,
    uint8_t *data,
    size_t size,
    int bundle_size,
    NaClCPUFeaturesX86 *cpu_features) {
  NaClValidationStatus status = NaClValidationFailedNotImplemented;
  assert(NACL_SB_DEFAULT == sb_kind);
  if (bundle_size == 16 || bundle_size == 32) {
    if (!NaClArchSupported(cpu_features))
      return NaClValidationFailedCpuNotSupported;
    switch (kind) {
      case NaClApplyCodeValidation:
        status = NCApplyValidatorSilently_x86_32(
            guest_addr, data, size, bundle_size, cpu_features);
        break;
      case NaClApplyValidationDoStubout:
        status = NCApplyValidatorStubout_x86_32(
            guest_addr, data, size, bundle_size, cpu_features);
        break;
      default:
        /* If reached, it isn't implemented (yet). */
        break;
    }
  }
  return status;
}

NaClValidationStatus NACL_SUBARCH_NAME(ApplyValidatorCodeReplacement, x86, 32)
    (enum NaClSBKind sb_kind,
     uintptr_t guest_addr,
     uint8_t *data_old,
     uint8_t *data_new,
     size_t size,
     int bundle_size,
     NaClCPUFeaturesX86 *cpu_features) {
  NaClValidationStatus status = NaClValidationFailedNotImplemented;
  assert(NACL_SB_DEFAULT == sb_kind);
  if (bundle_size == 16 || bundle_size == 32) {
    if (!NaClArchSupported(cpu_features)) {
      status = NaClValidationFailedCpuNotSupported;
    } else {
      status = NCValidateSegmentPair(data_old, data_new, guest_addr,
                                     size, bundle_size, cpu_features)
        ? NaClValidationSucceeded : NaClValidationFailed;
    }
  }
  return status;
}
