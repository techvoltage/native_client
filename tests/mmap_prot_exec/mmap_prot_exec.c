/*
 * Copyright (c) 2013 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

/* Get macros for NACL_ARCH(NACL_BUILD_ARCH) == NACL_x86 etc. */
#include "native_client/src/include/nacl_base.h"

/* Get UNREFERENCED_PARAMETER definition. */
#include "native_client/src/include/nacl_compiler_annotations.h"

/* Get macro for NACL_ARRAY_SIZE. */
#include "native_client/src/include/nacl_macros.h"

#include "native_client/src/shared/platform/nacl_check.h"

/* Get NACL_HALT_WORD, etc. */
#include "native_client/src/trusted/service_runtime/nacl_config.h"

#define NUM_FILE_BYTES 0x10000  /* one NaCl page */

int g_mach_copy_on_write_behavior = 0;

/*
 * mmap PROT_EXEC test
 *
 * Use a file containing mmappable code.  We don't want to
 * re-implement a dynamic loader here, nor do we want to duplicate a
 * lot of ELF parsing.  Instead, we open and write into a file the
 * machine code that implements a simple function, and then we map
 * that file into the address space and call it.
 */

/*
 * The etext symbol is used to obtain the approximate location where
 * the dynamic code area starts.  Note that we round it to the next
 * higher 64K NaCl page boundary before using it, and since we do not
 * allow munmap of text, each test run uses the next 64K page.  See
 * exec_spec and get_target_addr.
 */
extern char etext;

struct ProtExecSpecifics {
  uintptr_t target_addr;
  int misalign_addr;
  int map_prot;
  int map_flags;
  int expected_errno;  /* if expected mmap to fail */
};

uintptr_t get_target_addr(struct ProtExecSpecifics *spec) {
  uintptr_t addr = spec->target_addr;
  addr = (addr + 0xffff) & ~(uintptr_t) 0xffff;
  if (spec->misalign_addr) {
    addr += 1;
  }
  return addr;
}

/*
 * This is the function the machine instructions for which are below.
 * Instead of making assumptions about taking addresses of functions,
 * we open-code the machine instructions.  Since porting this test now
 * requires a little more effort, here is the procedure: Put in
 * "garbage" data in the test_machine_code for your architecture.
 * Build the Test.  The test will fail -- don't bother to run it.
 * However, you should now be able to use a debugger to disassemble
 * the x_plus_1 function, and update the test_machine_code contents.
 */
int x_plus_1(int x) {
  return x + 1;
}

int prot_exec_test(int d, size_t file_size, void *test_specifics) {
  struct ProtExecSpecifics *spec = (struct ProtExecSpecifics *) test_specifics;
  uintptr_t target_addr;
  void *addr;
  int (*func)(int param);
  int param;
  int value;

  target_addr = get_target_addr(spec);

  /*
   * See NACL_FAULT_INJECTION in nacl.scons -- the first mmap should fail,
   * and the second one should succeed if the file_size is okay.
   */
  errno = 0;
  addr = mmap((void *) target_addr,
              file_size,
              spec->map_prot,
              spec->map_flags,
              d,
              /* offset */ 0);
  if (0 != spec->expected_errno) {
    if (MAP_FAILED != addr) {
      fprintf(stderr,
              "prot_exec_test: expected mmap to failed but did not."
              "  errno %d, but may not be valid.\n", errno);
      return 1;
    }
    if (spec->expected_errno != errno) {
      fprintf(stderr,
              "prot_exec_test: expected mmap to failed with errno %d,"
              " got %d instead\n", spec->expected_errno, errno);
      return 1;
    }
  } else {
    if (MAP_FAILED == addr) {
      fprintf(stderr,
              "prot_exec_test: expected mmap to not fail, but failed with"
              " errno %d\n",
              errno);
      return 1;
    }
    if ((uintptr_t) addr != target_addr) {
      fprintf(stderr,
              "prot_exec_test: expected mmap address 0x%p, got %p\n",
              (void *) target_addr, addr);
      return 1;
    }

    func = (int (*)(int)) (uintptr_t) addr;
    for (param = 0; param < 16; ++param) {
      printf("%d -> ", param);
      fflush(stdout);
      value = (*func)(param);
      printf("%d\n", value);
      CHECK(value == x_plus_1(param));
    }

    CHECK(-1 == munmap(addr, file_size));
    CHECK(EINVAL == errno);
  }

  return 0;
}

int prot_exec_write_test(int d, size_t file_size, void *test_specifics) {
  struct ProtExecSpecifics *spec = (struct ProtExecSpecifics *) test_specifics;
  uintptr_t target_addr;
  void *addr;

  target_addr = get_target_addr(spec);

  addr = mmap((void *) target_addr,
              file_size,
              PROT_READ | PROT_WRITE | PROT_EXEC,
              MAP_SHARED | MAP_FIXED,
              d,
              /* offset */ 0);
  if (MAP_FAILED != addr) {
    fprintf(stderr, "prot_exec_test: expected map failed\n");
    return 1;
  }

  return 0;
}

/*
 * mmap MAP_SHARED test
 *
 * Make sure two views of the same file see the changes made from one
 * view in the other.
 */
int map_shared_test(int d, size_t file_size, void *test_specifics) {
  void *view1;
  void *view2;
  char *v1ptr;
  char *v2ptr;

  UNREFERENCED_PARAMETER(test_specifics);

  if (MAP_FAILED ==
      (view1 = mmap(NULL,
                    file_size,
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED,
                    d,
                    /* offset */ 0))) {
    fprintf(stderr, "map_shared_test: view1 map failed, errno %d\n",
            errno);
    return 1;
  }

  printf("view1 = %p\n", view1);

  if (MAP_FAILED ==
      (view2 = mmap(NULL,
                    file_size,
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED,
                    d,
                    /* offset */ 0))) {
    fprintf(stderr, "map_shared_test: view2 map failed, errno %d\n",
            errno);
    return 1;
  }

  printf("view2 = %p\n", view2);

  v1ptr = (char *) view1;
  v2ptr = (char *) view2;

  CHECK(v1ptr[0] == '\0');
  CHECK(v2ptr[0] == '\0');
  v1ptr[0] = 'x';
  CHECK(v2ptr[0] == 'x');
  v2ptr[0x400] = 'y';
  CHECK(v1ptr[0x400] == 'y');

  CHECK(0 == munmap(view1, file_size));
  CHECK(0 == munmap(view2, file_size));

  return 0;
}

struct MapPrivateSpecifics {
  int shm_not_write;
};

/*
 * mmap MAP_PRIVATE test
 *
 * Make sure that a MAP_PRIVATE view initially sees the changes made
 * in a MAP_SHARED view, but after touching the private view further
 * changes become invisible.
 */
int map_private_test(int d, size_t file_size, void *test_specifics) {
  struct MapPrivateSpecifics *params =
      (struct MapPrivateSpecifics *) test_specifics;
  void *view1;
  void *view2;
  off_t off;
  ssize_t bytes_written;
  char *v1ptr;
  char *v2ptr;

  if (MAP_FAILED ==
      (view1 = mmap(NULL,
                    file_size,
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED,
                    d,
                    /* offset */ 0))) {
    fprintf(stderr, "map_private_test: view1 map failed, errno %d\n",
            errno);
    return 1;
  }

  if (MAP_FAILED ==
      (view2 = mmap(NULL,
                    file_size,
                    PROT_READ | PROT_WRITE,
                    MAP_PRIVATE,
                    d,
                    /* offset */ 0))) {
    fprintf(stderr, "map_private_test: view2 map failed, errno %d\n",
            -(int) view2);
    return 1;
  }

  v1ptr = (char *) view1;
  v2ptr = (char *) view2;

  CHECK(v1ptr[0] == '\0');
  CHECK(v2ptr[0] == '\0');
  if (params->shm_not_write) {
    v1ptr[0] = 'x';  /* write through shared view */
  } else {
    off = lseek(d, 0LL, 0);
    if (off < 0) {
      fprintf(stderr, "Could not seek: NaCl errno %d\n", (int) -off);
      return 1;
    }
    bytes_written = write(d, "x", 1);
    if (1 != bytes_written) {
      fprintf(stderr, "Could not write: NaCl errno %d\n", (int) -bytes_written);
      return 1;
    }
  }
  /*
   * Most OSes have this behavior: a PRIVATE mapping is copy-on-write,
   * but the COW occurs when the fault occurs on that mapping, not
   * other mappings; otherwise, the page tables just point the system
   * to the buffer cache (or, if evicted, a stub entry that permits
   * faulting in the page).  So, a write through a writable file
   * descriptor or a SHARED mapping would modify the buffer cache, and
   * the PRIVATE mapping would see such changes until a fault occurs.
   *
   * This behavior can be surprising, but consistent with the lack of
   * copy-on-write locking subprotocols in distributed file systems
   * like NFS.
   */
  if (g_mach_copy_on_write_behavior) {
    /*
     * On OSX, however, the underlying Mach primitives provide
     * bidirectional COW.  This may fail if the file is on NFS!
     */
    CHECK(v2ptr[0] == '\0');  /* NOT visible! */
  } else {
    CHECK(v2ptr[0] == 'x');  /* visible! */
  }

  v2ptr[0] = 'z';  /* COW fault */
  v1ptr[0] = 'y';
  CHECK(v2ptr[0] == 'z'); /* private! */

  CHECK(v1ptr[0x400] == '\0');
  v2ptr[0x400] = 'y';
  CHECK(v1ptr[0x400] == '\0');

  CHECK(0 == munmap(view1, file_size));
  CHECK(0 == munmap(view2, file_size));

  return 0;
}

/*
 * Write out num_bytes (a multiple of 4) bytes of data.  If
 * !halt_fill, ASCII NUL is used; otherwise NACL_HALT_WORD is used.
 */
int CreateTestData(int d, size_t num_bytes, int halt_fill) {
  static int buffer[1024];
  size_t ix;
  size_t nbytes;
  size_t written = 0;
  ssize_t result;

  printf("num_bytes = %zx\n", num_bytes);
  CHECK((num_bytes & (size_t) 0x3) == 0);
  if (halt_fill) {
    for (ix = 0; ix < NACL_ARRAY_SIZE(buffer); ++ix) {
      buffer[ix] = NACL_HALT_WORD;
    }
  } else {
    memset(buffer, 0, sizeof buffer);
  }

  while (written < num_bytes) {
    nbytes = num_bytes - written;
    if (nbytes > sizeof buffer) {
      nbytes = sizeof buffer;
    }
    result = write(d, buffer, nbytes);
    if (result != nbytes) {
      return -1;
    }
    written += nbytes;
  }
  return 0;
}

struct TestParams {
  char const *test_name;
  int (*test_func)(int fd, size_t file_size, void *test_specifics);
  int open_flags;
  size_t file_size;
  int halt_fill;

  unsigned char const *test_data_start;
  size_t test_data_size;

  void *test_specifics;
};

int CreateTestFile(char const *pathname,
                   struct TestParams *param) {
  int d;
  off_t off;
  size_t desired_write;
  ssize_t bytes_written;

  printf("pathname = %s\n", pathname);
  if (-1 == (d = open(pathname,
                      O_WRONLY | O_CREAT | O_TRUNC,
                      0777))) {
    fprintf(stderr, "Could not open test scratch file: NaCl errno %d\n", errno);
    exit(1);
  }
  if (0 != CreateTestData(d, param->file_size, param->halt_fill)) {
    fprintf(stderr,
            "Could not write test data into test scratch file: NaCl errno %d\n",
            errno);
    exit(1);
  }
  if (NULL != param->test_data_start) {
    off = lseek(d, 0LL, 0);
    if (off < 0) {
      fprintf(stderr,
              "Could not seek to create test data: NaCl errno %d\n",
              errno);
      exit(1);
    }
    desired_write = param->test_data_size;
    bytes_written = write(d,
                          param->test_data_start,
                          desired_write);
    if (bytes_written < 0) {
      fprintf(stderr,
              "Could not write specialized test data: NaCl errno %d\n",
              errno);
      exit(1);
    }
    if ((size_t) bytes_written != desired_write) {
      fprintf(stderr,
              "Error while writing specialized test data:"
              " tried to write %d, actual %d\n",
              (int) desired_write, (int) bytes_written);
      exit(1);
    }
  }
  CHECK(0 == close(d));
  if (-1 == (d = open(pathname,
                      param->open_flags,
                      0777))) {
    fprintf(stderr, "Re-opening of %s failed, NaCl errno %d\n",
            pathname, errno);
    exit(1);
  }
  return d;
}

void CloseTestFile(int d) {
  CHECK(0 == close(d));
}

struct MapPrivateSpecifics test0 = { 0 };
struct MapPrivateSpecifics test1 = { 1 };

struct ProtExecSpecifics exec_spec[] = {
  {
    /* non-functional no NACL_FI */
    (0 * 0x10000 + (uintptr_t) &etext), 0,
    PROT_READ | PROT_EXEC, MAP_SHARED | MAP_FIXED,
    EINVAL,
  },
  {
    /* functional */
    (1 * 0x10000 + (uintptr_t) &etext), 0,
    PROT_READ | PROT_EXEC, MAP_SHARED | MAP_FIXED,
    0,
  },
  {
    /* short_file */
    (2 * 0x10000 + (uintptr_t) &etext), 0,
    PROT_READ | PROT_EXEC, MAP_SHARED | MAP_FIXED,
    EINVAL,
  },
  {
    /* PROT_WRITE|PROT_EXEC */
    (3 * 0x10000 + (uintptr_t) &etext), 0,
    PROT_WRITE | PROT_EXEC, MAP_SHARED | MAP_FIXED,
    EINVAL,
  },
  {
    /* unaligned */
    (4 * 0x10000 + (uintptr_t) &etext), 1,
    PROT_READ | PROT_EXEC, MAP_SHARED | MAP_FIXED,
    EINVAL,
  },
  {
    /* no MAP_FIXED, hint */
    (5 * 0x10000 + (uintptr_t) &etext), 0,
    PROT_READ | PROT_EXEC, MAP_SHARED,
    EINVAL,
  },
  {
    /* no MAP_FIXED, no hint */
    /* 6... */ 0, 0,
    PROT_READ | PROT_EXEC, MAP_SHARED,
    EINVAL,
  },
};

#if NACL_ARCH(NACL_BUILD_ARCH) == NACL_x86
# if NACL_BUILD_SUBARCH == 32
unsigned char const test_machine_code[] = {
  0x8b, 0x44, 0x24, 0x04,  /* mov 0x4(%esp),%eax */
  0x59,                    /* pop %ecx */
  0x83, 0xc0, 0x01,        /* add $01,%eax */
  0x83, 0xe1, 0xe0, 0xff,  /* and $0xffffffe0, %ecx*/
  0xe1,                    /* jmp *%ecx */
};
# elif NACL_BUILD_SUBARCH == 64
unsigned char const test_machine_code[] = {
  0x41, 0x5b,             /* pop %r11 */
  0x8d, 0x47, 0x01,       /* lea 0x1(%rdi), %eax */
  0x41, 0x83, 0xe3, 0xe0, /* and $0xffffffe0, %r11d */
  0x4d, 0x01, 0xfb,       /* add %r15, %r11 */
  0x41, 0xff, 0xe3        /* jmpq *%r11 */
};
# else
#  error "Who leaked the secret x86-128 project?"
# endif
#elif NACL_ARCH(NACL_BUILD_ARCH) == NACL_arm
unsigned char const test_machine_code[] = {
  0x01, 0x00, 0x80, 0xe2,  /* add r0, r0, #1 */
  0x3f, 0xe1, 0xce, 0xe3,  /* bic lr, lr #0xc000000f */
  0x1e, 0xff, 0x2f, 0xe1,  /* bx lr */
};
#elif NACL_ARCH(NACL_BUILD_ARCH) == NACL_mips
/* this is hand assembled and may not yet satisfy MIPS sandboxing rules */
unsigned char const test_machine_code[] = {
  0x01, 0x00, 0x42, 0x20,  /* addi v0, a0, 1 */
  0x24, 0xf8, 0xee, 0x03,  /* and ra, ra, t6 */
  0x08, 0x00, 0xe0, 0x23,  /* jr ra */
};
#else
# error "What architecture?"
#endif

struct TestParams tests[] = {
  {
    "Shared Mapping Test",
    map_shared_test,
    (O_RDWR | O_CREAT),
    NUM_FILE_BYTES,
    0,
    NULL, 0,
    NULL,
  }, {
    "Private Mapping Test, modify by write",
    map_private_test,
    (O_RDWR | O_CREAT),
    NUM_FILE_BYTES,
    0,
    NULL, 0,
    &test0,
  }, {
    "Private Mapping Test, modify by shm",
    map_private_test,
    (O_RDWR | O_CREAT),
    NUM_FILE_BYTES,
    0,
    NULL, 0,
    &test1,
  }, {
    "PROT_EXEC Mapping Test: non-functional (no NACL_FI)",
    prot_exec_test,
    (O_RDWR | O_CREAT),
    NUM_FILE_BYTES,
    1,
    test_machine_code, sizeof test_machine_code,
    &exec_spec[0],
  }, {
    "PROT_EXEC Mapping Test: functional",
    prot_exec_test,
    (O_RDWR | O_CREAT),
    NUM_FILE_BYTES,
    1,
    test_machine_code, sizeof test_machine_code,
    &exec_spec[1],
  }, {
    "PROT_EXEC Mapping Test: short file",
    prot_exec_test,
    (O_RDWR | O_CREAT),
    4096,
    1,
    test_machine_code, sizeof test_machine_code,
    &exec_spec[2],
  }, {
    "PROT_EXEC Mapping Test: PROT_WRITE|PROT_EXEC",
    prot_exec_write_test,
    (O_RDWR | O_CREAT),
    NUM_FILE_BYTES,
    1,
    test_machine_code, sizeof test_machine_code,
    &exec_spec[3],
  }, {
    "PROT_EXEC Mapping Test: unaligned target address",
    prot_exec_test,
    (O_RDWR | O_CREAT),
    NUM_FILE_BYTES,
    1,
    test_machine_code, sizeof test_machine_code,
    &exec_spec[4],
  }, {
    "PROT_EXEC Mapping Test: no MAP_FIXED, hint",
    prot_exec_test,
    (O_RDWR | O_CREAT),
    NUM_FILE_BYTES,
    1,
    test_machine_code, sizeof test_machine_code,
    &exec_spec[5],
  }, {
    "PROT_EXEC Mapping Test: no MAP_FIXED, no hint",
    prot_exec_test,
    (O_RDWR | O_CREAT),
    NUM_FILE_BYTES,
    1,
    test_machine_code, sizeof test_machine_code,
    &exec_spec[6],
  },
};

/*
 * This test is a NaCl module that writes a file containing
 * instructions -- a simple function, f(x) = x+1 -- that is then
 * mmapped in and executed.  Since we write the file at runtime rather
 * than check in architecture-specific test data files, this code must
 * run sel_ldr with -a option.
 *
 * This test was adapted from the trusted code test in
 * src/shared/platform/nacl_host_desc_mmap_test.c
 *
 * It is the responsibility of the invoking environment to delete the
 * file passed as command-line argument.  See the nacl.scons file.
 */
int main(int ac, char **av) {
  char const *test_file_name = "/tmp/nacl_host_desc_test";
  int fd;
  size_t err_count;
  size_t test_errors;
  size_t ix;
  int opt;
  int num_runs = 1;
  int test_run;

  while (EOF != (opt = getopt(ac, av, "c:f:m"))) {
    switch (opt) {
      case 'c':
        num_runs = atoi(optarg);
        break;
      case 'f':
        test_file_name = optarg;
        break;
      case 'm':
        g_mach_copy_on_write_behavior = 1;
        break;
      default:
        fprintf(stderr,
                "Usage: nacl_host_desc_mmap_test [-c run_count]\n"
                "                                [-f test_file]\n");
        exit(1);
    }
  }

  /*
   * This print helps to ensure that the function address escapes, so
   * that a whole program optimizer is less likely to optimize it out
   * and remove the x_plus_1 code completely.
   */
  printf("x_plus_1 addr is %p\n", (void *) (uintptr_t) x_plus_1);

  err_count = 0;
  for (test_run = 0; test_run < num_runs; ++test_run) {
    printf("Test run %d\n\n", test_run);
    for (ix = 0; ix < NACL_ARRAY_SIZE(tests); ++ix) {
      printf("%s\n", tests[ix].test_name);
      fd = CreateTestFile(test_file_name, &tests[ix]);
      test_errors = (*tests[ix].test_func)(fd,
                                           tests[ix].file_size,
                                           tests[ix].test_specifics);
      printf("%s\n", (0 == test_errors) ? "PASS" : "FAIL");
      err_count += test_errors;
      CloseTestFile(fd);
    }
  }

  /* we ignore the 2^32 or 2^64 total errors case */
  return (err_count > 255) ? 255 : err_count;
}
