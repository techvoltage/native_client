/*
 * Copyright 2010 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can
 * be found in the LICENSE file.
 */

#include "native_client/src/shared/ppapi_proxy/plugin_audio_config.h"

#include <stdio.h>
#include <string.h>
#include "gen/native_client/src/shared/ppapi_proxy/ppb_rpc.h"
#include "native_client/src/include/portability.h"
#include "native_client/src/shared/ppapi_proxy/plugin_globals.h"
#include "native_client/src/shared/ppapi_proxy/utility.h"
#include "native_client/src/shared/srpc/nacl_srpc.h"
#include "ppapi/c/dev/ppb_audio_config_dev.h"

namespace ppapi_proxy {

namespace {
PP_Resource CreateStereo16Bit(PP_Module module,
                              PP_AudioSampleRate_Dev sample_rate,
                              uint32_t sample_frame_count,
                              uint32_t* obtained_sample_frame_count) {
  UNREFERENCED_PARAMETER(module);
  UNREFERENCED_PARAMETER(sample_rate);
  UNREFERENCED_PARAMETER(sample_frame_count);
  UNREFERENCED_PARAMETER(obtained_sample_frame_count);
  return kInvalidResourceId;
}

PP_AudioSampleRate_Dev GetSampleRate(PP_Resource config) {
  UNREFERENCED_PARAMETER(config);
  return PP_AUDIOSAMPLERATE_NONE;
}

uint32_t GetSampleFrameCount(PP_Resource config) {
  UNREFERENCED_PARAMETER(config);
  return PP_AUDIOMINSAMPLEFRAMECOUNT;
}
}  // namespace

const PPB_AudioConfig_Dev* PluginAudioConfig::GetInterface() {
  static const PPB_AudioConfig_Dev intf = {
    CreateStereo16Bit,
    GetSampleRate,
    GetSampleFrameCount,
  };
  return &intf;
}

}  // namespace ppapi_proxy
