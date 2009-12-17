/* Copyright (c) 2009 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * ncval_iter.c - command line validator for NaCl.
 */

#include <string.h>
#include <errno.h>

#include "native_client/src/include/nacl_macros.h"
#include "native_client/src/shared/platform/nacl_log.h"
#include "native_client/src/shared/utils/flags.h"
#include "native_client/src/trusted/validator_x86/nc_jumps.h"
#include "native_client/src/trusted/validator_x86/nc_protect_base.h"
#include "native_client/src/trusted/validator_x86/ncfileutil.h"
#include "native_client/src/trusted/validator_x86/ncval_driver.h"
#include "native_client/src/trusted/validator_x86/ncvalidate_iter.h"

/* Analyze each section in the given elf file, using the given validator
 * state.
 */
static void AnalyzeSections(ncfile *ncf, struct NcValidatorState *vstate) {
  int ii;
  const Elf_Phdr* phdr = ncf->pheaders;

  for (ii = 0; ii < ncf->phnum; ii++) {
    /* TODO(karl) fix types for this? */
    NcValidatorMessage(
        LOG_INFO, vstate,
        "segment[%d] p_type %d p_offset %"PRIxElf_Off
        " vaddr %"PRIxElf_Addr
        " paddr %"PRIxElf_Addr
        " align %"PRIuElf_Xword"\n",
        ii, phdr[ii].p_type, phdr[ii].p_offset,
        phdr[ii].p_vaddr, phdr[ii].p_paddr,
        phdr[ii].p_align);
    NcValidatorMessage(
        LOG_INFO, vstate,
        "    filesz %"PRIxElf_Xword
        " memsz %"PRIxElf_Xword
        " flags %"PRIxElf_Word"\n",
        phdr[ii].p_filesz, phdr[ii].p_memsz,
        phdr[ii].p_flags);
    if ((PT_LOAD != phdr[ii].p_type) ||
        (0 == (phdr[ii].p_flags & PF_X)))
      continue;
    NcValidatorMessage(LOG_INFO, vstate, "parsing segment %d\n", ii);
    NcValidateSegment(ncf->data + (phdr[ii].p_vaddr - ncf->vbase),
                    phdr[ii].p_vaddr, phdr[ii].p_memsz, vstate);
  }
}

static void AnalyzeSegments(ncfile* ncf, NcValidatorState* state) {
  int ii;
  const Elf_Shdr* shdr = ncf->sheaders;

  for (ii = 0; ii < ncf->shnum; ii++) {
    NcValidatorMessage(
        LOG_INFO, state,
        "section %d sh_addr %"PRIxElf_Addr" offset %"PRIxElf_Off
        " flags %"PRIxElf_Xword"\n",
         ii, shdr[ii].sh_addr, shdr[ii].sh_offset, shdr[ii].sh_flags);
    if ((shdr[ii].sh_flags & SHF_EXECINSTR) != SHF_EXECINSTR)
      continue;
    NcValidatorMessage(LOG_INFO, state, "parsing section %d\n", ii);
    NcValidateSegment(ncf->data + (shdr[ii].sh_addr - ncf->vbase),
                      shdr[ii].sh_addr, shdr[ii].sh_size, state);
  }
}

/* Define if we should process segments (rather than sections). */
static Bool FLAGS_analyze_segments = FALSE;

/* Define if we should print all validator error messages (rather
 * than quit after the first error).
 */
static Bool FLAGS_quit_on_error = FALSE;

/* Define the value for the base register. */
static OperandKind base_register =
    (64 == NACL_TARGET_SUBARCH ? RegR15 : RegUnknown);

/* Analyze each code segment in the given elf file, stored in the
 * file with the given path fname.
 */
static void AnalyzeCodeSegments(ncfile *ncf, const char *fname) {
  /* TODO(karl) convert these to be PcAddress and MemorySize */
  PcAddress vbase, vlimit;
  NcValidatorState *vstate;

  GetVBaseAndLimit(ncf, &vbase, &vlimit);
  vstate = NcValidatorStateCreate(vbase, vlimit - vbase,
                                  ncf->ncalign, base_register,
                                  FLAGS_quit_on_error,
                                  stderr);
  if (vstate == NULL) {
    NcValidatorMessage(LOG_FATAL, vstate, "Unable to create validator state");
  }
  if (FLAGS_analyze_segments) {
    AnalyzeSegments(ncf, vstate);
  } else {
    AnalyzeSections(ncf, vstate);
  }
  NcValidatorStatePrintStats(stdout, vstate);
  if (NcValidatesOk(vstate)) {
    NcValidatorMessage(LOG_INFO, vstate, "***module %s is safe***\n", fname);
  } else {
    NcValidatorMessage(LOG_INFO, vstate, "***MODULE %s IS UNSAFE***\n", fname);
  }
  NcValidatorMessage(LOG_INFO, vstate, "Validated %s\n", fname);
  NcValidatorStateDestroy(vstate);
}

/* Generates NaclErrorMapping for error level suffix. */
#define NaclError(s) { #s , LOG_## s}

/* Recognizes flags in argv, processes them, and then removes them.
 * Returns the updated value for argc.
 */
static int GrokFlags(int argc, const char* argv[]) {
  int i;
  int new_argc;
  char* error_level = NULL;
  if (argc == 0) return 0;
  new_argc = 1;
  for (i = 1; i < argc; ++i) {
    const char* arg = argv[i];
    if (GrokBoolFlag("-segments", arg, &FLAGS_analyze_segments)) {
      continue;
    } else if (GrokCstringFlag("-error_level", arg, &error_level)) {
      int i;
      static struct {
        const char* name;
        int level;
      } map[] = {
        NaclError(INFO),
        NaclError(WARNING),
        NaclError(ERROR),
        NaclError(FATAL)
      };
      for (i = 0; i < NACL_ARRAY_SIZE(map); ++i) {
        if (0 == strcmp(error_level, map[i].name)) {
          NaClLogSetVerbosity(map[i].level);
          break;
        }
      }
      if (i == NACL_ARRAY_SIZE(map)) {
        NcValidatorMessage(LOG_FATAL, NULL,
                           "-error_level=%s not defined!\n", error_level);
      }
    } else if (GrokBoolFlag("--quit-on-error", arg, &FLAGS_quit_on_error) ||
               GrokBoolFlag("--identity_mask", arg, &FLAGS_identity_mask)) {
      continue;
    } else {
      argv[new_argc++] = argv[i];
    }
  }
  return new_argc;
}

/* Local data to validator run. */
typedef struct ValidateData {
  /* The name of the elf file to validate. */
  const char* fname;
  /* The elf file to validate. */
  ncfile* ncf;
} ValidateData;

/* Prints out appropriate error message during call to ValidateLoad. */
static void ValidateLoadPrintError(const char* format,
                                   ...) ATTRIBUTE_FORMAT_PRINTF(1,2);

static void ValidateLoadPrintError(const char* format, ...) {
  va_list ap;
  va_start(ap, format);
  NcValidatorVarargMessage(LOG_ERROR, NULL, format, ap);
  va_end(ap);
}

/* Loads the elf file defined by fname. For use within ValidateLoad. */
static ncfile* ValidateLoadFile(const char* fname) {
  nc_loadfile_error_fn old_print_error;
  ncfile* file;
  old_print_error = NcLoadFileRegisterErrorFn(ValidateLoadPrintError);
  file = nc_loadfile(fname);
  NcLoadFileRegisterErrorFn(old_print_error);
  return file;
}

/* Load the elf file and return the loaded elf file. */
static ValidateData* ValidateLoad(int argc, const char* argv[]) {
  ValidateData* data;
  argc = GrokFlags(argc, argv);
  if (argc != 2) {
    NcValidatorMessage(LOG_FATAL, NULL, "expected: %s file\n", argv[0]);
  }
  data = (ValidateData*) malloc(sizeof(ValidateData));
  if (NULL == data) {
    NcValidatorMessage(LOG_FATAL, NULL, "Unsufficient memory to run");
  }
  data->fname = argv[1];

  /* TODO(karl): Once we fix elf values put in by compiler, so that
   * we no longer get load errors from ncfilutil.c, find a way to
   * terminate early if errors occur during loading.
   */
  data->ncf = ValidateLoadFile(data->fname);

  if (NULL == data->ncf) {
    NcValidatorMessage(LOG_FATAL, NULL, "nc_loadfile(%s): %s\n",
                       data->fname, strerror(errno));
  }
  return data;
}

/* Analyze the code segments of the elf file. */
static int ValidateAnalyze(ValidateData* data) {
  AnalyzeCodeSegments(data->ncf, data->fname);
  nc_freefile(data->ncf);
  free(data);
  return 0;
}

int main(int argc, const char *argv[]) {
  return NcRunValidator(argc, argv,
                        (NcValidateLoad) ValidateLoad,
                        (NcValidateAnalyze) ValidateAnalyze);
}
