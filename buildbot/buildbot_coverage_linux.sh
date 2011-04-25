#!/bin/bash
# Copyright (c) 2011 The Native Client Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

# Script assumed to be run in native_client/
if [[ $(pwd) != */native_client ]]; then
  echo "ERROR: must be run in native_client!"
  exit 1
fi

if [ $# -ne 1 ]; then
  echo "USAGE: $0 32/64"
  exit 2
fi

set -x
set -e
set -u

# Pick 32 or 64
BITS=$1


echo @@@BUILD_STEP gclient_runhooks@@@
gclient runhooks --force

echo @@@BUILD_STEP clobber@@@
rm -rf scons-out toolchain compiler ../sconsbuild ../out

echo @@@BUILD_STEP partial_sdk@@@
./scons --verbose --mode=nacl_extra_sdk platform=x86-${BITS} --download \
extra_sdk_update_header install_libpthread extra_sdk_update

echo @@@BUILD_STEP scons_compile@@@
./scons -j 8 DOXYGEN=../third_party/doxygen/linux/doxygen -k --verbose \
    --mode=coverage-linux,nacl,doc platform=x86-${BITS}

echo @@@BUILD_STEP coverage@@@
XVFB_PREFIX="xvfb-run --auto-servernum"

$XVFB_PREFIX \
    ./scons DOXYGEN=../third_party/doxygen/linux/doxygen -k --verbose \
    --mode=coverage-linux,nacl,doc coverage platform=x86-${BITS}
python tools/coverage_linux.py ${BITS}

echo @@@BUILD_STEP archive_coverage@@@
export GSUTIL="/b/build/scripts/slave/gsutil -h Cache-Control:no-cache"
GSD_URL=http://gsdview.appspot.com/nativeclient-coverage2/revs
VARIANT_NAME=coverage-linux-x86-${BITS}
COVERAGE_PATH=${VARIANT_NAME}/html/index.html
BUILDBOT_REVISION=${BUILDBOT_REVISION:-None}
LINK_URL=${GSD_URL}/${BUILDBOT_REVISION}/${COVERAGE_PATH}
GSD_BASE=gs://nativeclient-coverage2/revs
GS_PATH=${GSD_BASE}/${BUILDBOT_REVISION}/${VARIANT_NAME}
/b/build/scripts/slave/gsutil_cp_dir.py \
     scons-out/${VARIANT_NAME}/coverage ${GS_PATH}
echo @@@STEP_LINK@view@${LINK_URL}@@@
