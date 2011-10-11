# Copyright 2008, Google Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#     * Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above
# copyright notice, this list of conditions and the following disclaimer
# in the documentation and/or other materials provided with the
# distribution.
#     * Neither the name of Google Inc. nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

{
  ######################################################################
  'variables': {
    'COMMAND_TESTER': '<(DEPTH)/native_client/tools/command_tester.py',
    'common_sources': [
      'nacl_imc_c.cc',
      'nacl_imc_common.cc',
      'nacl_imc.h',
      'nacl_imc_c.h',
    ],
    'conditions': [
      ['OS=="linux"', {
        'common_sources': [
          'nacl_imc_unistd.cc',
          'linux/nacl_imc.cc',
        ],
      }],
      ['OS=="mac"', {
        'common_sources': [
          'nacl_imc_unistd.cc',
          'osx/nacl_imc.cc',
        ],
      }],
      ['OS=="win"', {
        'common_sources': [
          'win/nacl_imc.cc',
          'win/nacl_shm.cc',
        ],
        'msvs_settings': {
          'VCCLCompilerTool': {
            'ExceptionHandling': '2',  # /EHsc
          },
        },
      }],
    ],
  },
  ######################################################################
  'includes': [
    '../../../build/common.gypi',
  ],
  ######################################################################
  'target_defaults': {
  },
  'targets': [
    # ----------------------------------------------------------------------
    {
      'target_name': 'imc',
      'type': 'static_library',
      'sources': [
        '<@(common_sources)',
      ],
    },
    # ----------------------------------------------------------------------
    # ----------------------------------------------------------------------
    {
      'target_name': 'sigpipe_test',
      'type': 'executable',
      'sources': [
        'sigpipe_test.cc',
      ],
      'dependencies': [
        '<(DEPTH)/native_client/src/shared/imc/imc.gyp:imc',
        '<(DEPTH)/native_client/src/shared/platform/platform.gyp:platform',
        '<(DEPTH)/native_client/src/shared/gio/gio.gyp:gio',
      ],
    },
  ],
  'conditions': [
    ['disable_untrusted==0 and OS!="mac" and target_arch!="arm"', {
      'targets' : [
        {
          'target_name': 'imc_lib',
          'type': 'none',
          'variables': {
            'nlib_target': 'libimc.a',
            'build_glibc': 1,
            'build_newlib': 0,
            'sources': ['nacl_imc_c.cc', 'nacl_imc_common.cc', 'nacl/nacl_imc.cc'],
          },
          'dependencies': [
            '<(DEPTH)/native_client/tools.gyp:prep_toolchain',
          ],
        },
      ]
    }],
    ['target_arch!="arm"', {
      'targets': [
        # NOTE: we cannot run this on ARM since we are using a cross compiler
        {
          'target_name': 'run_sigpipe_test',
          'message': 'running test run_imc_tests',
          'type': 'none',
          'dependencies': [
            'sigpipe_test',
          ],
          'actions': [
          {
            'action_name': 'run_sigpipe_test',
            'msvs_cygwin_shell': 0,
            'inputs': [
              '<(COMMAND_TESTER)',
              '<(PRODUCT_DIR)/sigpipe_test',
            ],
            'outputs': [
              '<(PRODUCT_DIR)/test-output/sigpipe_test.out',
            ],
            'action': [
              '<@(python_exe)',
              '<(COMMAND_TESTER)',
              '<(PRODUCT_DIR)/sigpipe_test',
              '>',
              '<@(_outputs)',
            ],
          },
          ]
        },
      ],
    }],
    ['OS=="win"', {
      'targets': [
        # ---------------------------------------------------------------------
        {
          'target_name': 'imc64',
          'type': 'static_library',
          'variables': {
            'win_target': 'x64',
          },
          'sources': [
            '<@(common_sources)',
          ],
        },
        # ---------------------------------------------------------------------
        {
          'target_name': 'sigpipe_test64',
          'type': 'executable',
          'variables': {
            'win_target': 'x64',
          },
          'sources': [
            'sigpipe_test.cc',
          ],
          'dependencies': [
            '<(DEPTH)/native_client/src/shared/imc/imc.gyp:imc64',
            '<(DEPTH)/native_client/src/shared/platform/platform.gyp:platform64',
            '<(DEPTH)/native_client/src/shared/gio/gio.gyp:gio64',
          ],
        },
      ],
    }],
  ],
}

# TODO: some tests missing, c.f. build.scons

