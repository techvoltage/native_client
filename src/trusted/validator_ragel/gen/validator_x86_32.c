/* native_client/src/trusted/validator_ragel/gen/validator_x86_32.c
 * THIS FILE IS AUTO-GENERATED. DO NOT EDIT.
 * Compiled for ia32 mode.
 */

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "native_client/src/trusted/validator_ragel/unreviewed/validator_internal.h"

/* Ignore this information: it's not used by security model in IA32 mode.  */
#undef GET_VEX_PREFIX3
#define GET_VEX_PREFIX3 0
#undef SET_VEX_PREFIX3
#define SET_VEX_PREFIX3(P)





static const int x86_64_decoder_start = 246;
static const int x86_64_decoder_first_final = 246;
static const int x86_64_decoder_error = 0;

static const int x86_64_decoder_en_main = 246;




int ValidateChunkIA32(const uint8_t *data, size_t size,
                      const NaClCPUFeaturesX86 *cpu_features,
                      process_validation_error_func process_error,
                      void *userdata) {
  uint8_t *valid_targets = BitmapAllocate(size);
  uint8_t *jump_dests = BitmapAllocate(size);

  const uint8_t *p = data;
  const uint8_t *begin = p;  /* Start of the instruction being processed.  */

  int result = 0;

  size_t i;

  uint32_t errors_detected;

  assert(size % kBundleSize == 0);

  while (p < data + size) {
    const uint8_t *pe = p + kBundleSize;
    const uint8_t *eof = pe;
    int cs;

    
	{
	cs = x86_64_decoder_start;
	}

    
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr9:
	{
    SET_DISP_TYPE(DISP32);
    SET_DISP_PTR(p - 3);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr10:
	{
    SET_DISP_TYPE(DISP8);
    SET_DISP_PTR(p);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr11:
	{ }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr15:
	{ }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr21:
	{
    SET_CPU_FEATURE(CPUFeature_3DNOW);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr29:
	{
    SET_CPU_FEATURE(CPUFeature_TSC);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr36:
	{
    SET_CPU_FEATURE(CPUFeature_MMX);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr48:
	{
    SET_CPU_FEATURE(CPUFeature_MON);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr49:
	{
    SET_CPU_FEATURE(CPUFeature_FXSR);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr50:
	{
    SET_CPU_FEATURE(CPUFeature_3DPRFTCH);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr62:
	{
    SET_CPU_FEATURE(CPUFeature_E3DNOW);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr68:
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr89:
	{
    rel32_operand(p + 1, data, jump_dests, size, &errors_detected);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr92:
	{
    SET_CPU_FEATURE(CPUFeature_CLFLUSH);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr101:
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr102:
	{
    SET_CPU_FEATURE(CPUFeature_EMMXSSE);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr103:
	{
    SET_CPU_FEATURE(CPUFeature_CX8);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr111:
	{
    rel8_operand(p + 1, data, jump_dests, size, &errors_detected);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr132:
	{ }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr179:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr253:
	{
    SET_CPU_FEATURE(CPUFeature_TBM);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr260:
	{
    SET_CPU_FEATURE(CPUFeature_LWP);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr294:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr321:
	{
    SET_CPU_FEATURE(CPUFeature_BMI1);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr347:
	{ }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr373:
	{
    SET_CPU_FEATURE(CPUFeature_x87);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr379:
	{
    SET_CPU_FEATURE(CPUFeature_CMOVx87);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr399:
	{
    SET_REPZ_PREFIX(FALSE);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr407:
	{
      BitmapClearBit(valid_targets, (p - data) - 1);
    }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr421:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
tr430:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	{
    SET_CPU_FEATURE(CPUFeature_x87);
  }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st246;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	switch( (*p) ) {
		case 4u: goto tr416;
		case 5u: goto tr417;
		case 12u: goto tr416;
		case 13u: goto tr417;
		case 14u: goto tr19;
		case 15u: goto tr418;
		case 20u: goto tr416;
		case 21u: goto tr417;
		case 28u: goto tr416;
		case 29u: goto tr417;
		case 36u: goto tr416;
		case 37u: goto tr417;
		case 44u: goto tr416;
		case 45u: goto tr417;
		case 46u: goto tr419;
		case 47u: goto tr19;
		case 52u: goto tr416;
		case 53u: goto tr417;
		case 60u: goto tr416;
		case 61u: goto tr417;
		case 62u: goto tr420;
		case 63u: goto tr19;
		case 101u: goto tr422;
		case 102u: goto tr423;
		case 104u: goto tr417;
		case 105u: goto tr424;
		case 106u: goto tr416;
		case 107u: goto tr425;
		case 128u: goto tr425;
		case 129u: goto tr424;
		case 130u: goto tr19;
		case 131u: goto tr427;
		case 141u: goto tr428;
		case 143u: goto tr429;
		case 155u: goto tr430;
		case 168u: goto tr416;
		case 169u: goto tr417;
		case 196u: goto tr433;
		case 197u: goto tr434;
		case 198u: goto tr435;
		case 199u: goto tr436;
		case 200u: goto tr437;
		case 202u: goto tr438;
		case 216u: goto tr440;
		case 217u: goto tr441;
		case 218u: goto tr442;
		case 219u: goto tr443;
		case 220u: goto tr444;
		case 221u: goto tr445;
		case 222u: goto tr446;
		case 223u: goto tr447;
		case 235u: goto tr426;
		case 240u: goto tr449;
		case 242u: goto tr450;
		case 243u: goto tr451;
		case 246u: goto tr452;
		case 247u: goto tr453;
		case 254u: goto tr454;
		case 255u: goto tr455;
	}
	if ( (*p) < 132u ) {
		if ( (*p) < 32u ) {
			if ( (*p) < 8u ) {
				if ( (*p) > 3u ) {
					if ( 6u <= (*p) && (*p) <= 7u )
						goto tr19;
				} else
					goto tr415;
			} else if ( (*p) > 19u ) {
				if ( (*p) < 24u ) {
					if ( 22u <= (*p) && (*p) <= 23u )
						goto tr19;
				} else if ( (*p) > 27u ) {
					if ( 30u <= (*p) && (*p) <= 31u )
						goto tr19;
				} else
					goto tr415;
			} else
				goto tr415;
		} else if ( (*p) > 35u ) {
			if ( (*p) < 54u ) {
				if ( (*p) > 39u ) {
					if ( 40u <= (*p) && (*p) <= 51u )
						goto tr415;
				} else if ( (*p) >= 38u )
					goto tr19;
			} else if ( (*p) > 55u ) {
				if ( (*p) < 96u ) {
					if ( 56u <= (*p) && (*p) <= 59u )
						goto tr415;
				} else if ( (*p) > 111u ) {
					if ( 112u <= (*p) && (*p) <= 127u )
						goto tr426;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr415;
	} else if ( (*p) > 139u ) {
		if ( (*p) < 194u ) {
			if ( (*p) < 160u ) {
				if ( (*p) > 142u ) {
					if ( 154u <= (*p) && (*p) <= 157u )
						goto tr19;
				} else if ( (*p) >= 140u )
					goto tr19;
			} else if ( (*p) > 163u ) {
				if ( (*p) < 184u ) {
					if ( 176u <= (*p) && (*p) <= 183u )
						goto tr416;
				} else if ( (*p) > 191u ) {
					if ( 192u <= (*p) && (*p) <= 193u )
						goto tr432;
				} else
					goto tr417;
			} else
				goto tr431;
		} else if ( (*p) > 195u ) {
			if ( (*p) < 212u ) {
				if ( (*p) > 207u ) {
					if ( 208u <= (*p) && (*p) <= 211u )
						goto tr439;
				} else if ( (*p) >= 204u )
					goto tr19;
			} else if ( (*p) > 231u ) {
				if ( (*p) < 234u ) {
					if ( 232u <= (*p) && (*p) <= 233u )
						goto tr448;
				} else if ( (*p) > 241u ) {
					if ( 250u <= (*p) && (*p) <= 251u )
						goto tr19;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr19;
	} else
		goto tr415;
	goto tr421;
tr23:
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st1;
tr28:
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st1;
tr30:
	{
    SET_CPU_FEATURE(CPUFeature_CMOV);
  }
	goto st1;
tr32:
	{
    SET_CPU_FEATURE(CPUFeature_MMX);
  }
	goto st1;
tr45:
	{
    SET_CPU_FEATURE(CPUFeature_EMMXSSE);
  }
	goto st1;
tr135:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st1;
tr144:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE3);
  }
	goto st1;
tr147:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSSE3);
  }
	goto st1;
tr148:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE41);
  }
	goto st1;
tr150:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE42);
  }
	goto st1;
tr151:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_AES);
  }
	goto st1;
tr201:
	{
    SET_REPNZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE42);
  }
	goto st1;
tr203:
	{
    SET_REPZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_POPCNT);
  }
	goto st1;
tr204:
	{
    SET_REPZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_TZCNT);
  }
	goto st1;
tr205:
	{
    SET_REPZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_LZCNT);
  }
	goto st1;
tr252:
	{
    SET_CPU_FEATURE(CPUFeature_XOP);
  }
	goto st1;
tr319:
	{
    SET_CPU_FEATURE(CPUFeature_BMI1);
  }
	goto st1;
tr291:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st1;
tr327:
	{
    SET_CPU_FEATURE(CPUFeature_FMA);
  }
	goto st1;
tr328:
	{
    SET_CPU_FEATURE(CPUFeature_AESAVX);
  }
	goto st1;
tr329:
	{
    SET_CPU_FEATURE(CPUFeature_F16C);
  }
	goto st1;
tr385:
	{
    SET_REPNZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st1;
tr386:
	{
    SET_REPNZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE3);
  }
	goto st1;
tr392:
	{
    SET_REPNZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st1;
tr400:
	{
    SET_REPZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st1;
tr401:
	{
    SET_REPZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE3);
  }
	goto st1;
tr403:
	{
    SET_REPZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st1;
tr415:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 20u: goto st2;
		case 21u: goto st3;
		case 28u: goto st2;
		case 29u: goto st3;
		case 36u: goto st2;
		case 37u: goto st3;
		case 44u: goto st2;
		case 45u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 60u: goto st2;
		case 61u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 84u: goto st8;
		case 92u: goto st8;
		case 100u: goto st8;
		case 108u: goto st8;
		case 116u: goto st8;
		case 124u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
		case 148u: goto st9;
		case 156u: goto st9;
		case 164u: goto st9;
		case 172u: goto st9;
		case 180u: goto st9;
		case 188u: goto st9;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto st3;
	} else if ( (*p) >= 64u )
		goto st7;
	goto tr0;
tr69:
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st2;
tr51:
	{
    SET_CPU_FEATURE(CPUFeature_3DPRFTCH);
  }
	goto st2;
tr90:
	{
    SET_CPU_FEATURE(CPUFeature_FXSR);
  }
	goto st2;
tr93:
	{
    SET_CPU_FEATURE(CPUFeature_CLFLUSH);
  }
	goto st2;
tr104:
	{
    SET_CPU_FEATURE(CPUFeature_CX8);
  }
	goto st2;
tr254:
	{
    SET_CPU_FEATURE(CPUFeature_TBM);
  }
	goto st2;
tr322:
	{
    SET_CPU_FEATURE(CPUFeature_BMI1);
  }
	goto st2;
tr295:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st2;
tr374:
	{
    SET_CPU_FEATURE(CPUFeature_x87);
  }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	switch( (*p) ) {
		case 5u: goto st3;
		case 13u: goto st3;
		case 21u: goto st3;
		case 29u: goto st3;
		case 37u: goto st3;
		case 45u: goto st3;
		case 53u: goto st3;
		case 61u: goto st3;
		case 69u: goto st3;
		case 77u: goto st3;
		case 85u: goto st3;
		case 93u: goto st3;
		case 101u: goto st3;
		case 109u: goto st3;
		case 117u: goto st3;
		case 125u: goto st3;
		case 133u: goto st3;
		case 141u: goto st3;
		case 149u: goto st3;
		case 157u: goto st3;
		case 165u: goto st3;
		case 173u: goto st3;
		case 181u: goto st3;
		case 189u: goto st3;
		case 197u: goto st3;
		case 205u: goto st3;
		case 213u: goto st3;
		case 221u: goto st3;
		case 229u: goto st3;
		case 237u: goto st3;
		case 245u: goto st3;
		case 253u: goto st3;
	}
	goto tr0;
tr70:
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st3;
tr52:
	{
    SET_CPU_FEATURE(CPUFeature_3DPRFTCH);
  }
	goto st3;
tr91:
	{
    SET_CPU_FEATURE(CPUFeature_FXSR);
  }
	goto st3;
tr94:
	{
    SET_CPU_FEATURE(CPUFeature_CLFLUSH);
  }
	goto st3;
tr105:
	{
    SET_CPU_FEATURE(CPUFeature_CX8);
  }
	goto st3;
tr255:
	{
    SET_CPU_FEATURE(CPUFeature_TBM);
  }
	goto st3;
tr323:
	{
    SET_CPU_FEATURE(CPUFeature_BMI1);
  }
	goto st3;
tr296:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st3;
tr375:
	{
    SET_CPU_FEATURE(CPUFeature_x87);
  }
	goto st3;
tr431:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	goto tr9;
tr71:
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st7;
tr53:
	{
    SET_CPU_FEATURE(CPUFeature_3DPRFTCH);
  }
	goto st7;
tr95:
	{
    SET_CPU_FEATURE(CPUFeature_FXSR);
  }
	goto st7;
tr97:
	{
    SET_CPU_FEATURE(CPUFeature_CLFLUSH);
  }
	goto st7;
tr106:
	{
    SET_CPU_FEATURE(CPUFeature_CX8);
  }
	goto st7;
tr256:
	{
    SET_CPU_FEATURE(CPUFeature_TBM);
  }
	goto st7;
tr324:
	{
    SET_CPU_FEATURE(CPUFeature_BMI1);
  }
	goto st7;
tr297:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st7;
tr376:
	{
    SET_CPU_FEATURE(CPUFeature_x87);
  }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	goto tr10;
tr72:
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st8;
tr54:
	{
    SET_CPU_FEATURE(CPUFeature_3DPRFTCH);
  }
	goto st8;
tr96:
	{
    SET_CPU_FEATURE(CPUFeature_FXSR);
  }
	goto st8;
tr98:
	{
    SET_CPU_FEATURE(CPUFeature_CLFLUSH);
  }
	goto st8;
tr107:
	{
    SET_CPU_FEATURE(CPUFeature_CX8);
  }
	goto st8;
tr257:
	{
    SET_CPU_FEATURE(CPUFeature_TBM);
  }
	goto st8;
tr325:
	{
    SET_CPU_FEATURE(CPUFeature_BMI1);
  }
	goto st8;
tr298:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st8;
tr377:
	{
    SET_CPU_FEATURE(CPUFeature_x87);
  }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	goto st7;
tr73:
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st9;
tr55:
	{
    SET_CPU_FEATURE(CPUFeature_3DPRFTCH);
  }
	goto st9;
tr99:
	{
    SET_CPU_FEATURE(CPUFeature_FXSR);
  }
	goto st9;
tr100:
	{
    SET_CPU_FEATURE(CPUFeature_CLFLUSH);
  }
	goto st9;
tr108:
	{
    SET_CPU_FEATURE(CPUFeature_CX8);
  }
	goto st9;
tr258:
	{
    SET_CPU_FEATURE(CPUFeature_TBM);
  }
	goto st9;
tr326:
	{
    SET_CPU_FEATURE(CPUFeature_BMI1);
  }
	goto st9;
tr299:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st9;
tr378:
	{
    SET_CPU_FEATURE(CPUFeature_x87);
  }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	goto st3;
tr85:
	{
    SET_CPU_FEATURE(CPUFeature_MMX);
  }
	goto st10;
tr83:
	{
    SET_DISP_TYPE(DISP32);
    SET_DISP_PTR(p - 3);
  }
	goto st10;
tr84:
	{
    SET_DISP_TYPE(DISP8);
    SET_DISP_PTR(p);
  }
	goto st10;
tr165:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st10;
tr159:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE41);
  }
	goto st10;
tr166:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st10;
tr302:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st10;
tr372:
	{ }
	goto st10;
tr396:
	{ }
	goto st10;
tr416:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	goto tr11;
tr215:
	{
    SET_DISP_TYPE(DISP32);
    SET_DISP_PTR(p - 3);
  }
	goto st11;
tr216:
	{
    SET_DISP_TYPE(DISP8);
    SET_DISP_PTR(p);
  }
	goto st11;
tr264:
	{
    SET_CPU_FEATURE(CPUFeature_LWP);
  }
	goto st11;
tr417:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	goto tr15;
tr19:
	{
        process_error(begin, UNRECOGNIZED_INSTRUCTION, userdata);
        result = 1;
        goto error_detected;
    }
	goto st0;
st0:
cs = 0;
	goto _out;
tr418:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	switch( (*p) ) {
		case 0u: goto st16;
		case 1u: goto st17;
		case 11u: goto tr0;
		case 13u: goto st18;
		case 14u: goto tr21;
		case 15u: goto st19;
		case 18u: goto st29;
		case 19u: goto tr25;
		case 22u: goto st29;
		case 23u: goto tr25;
		case 24u: goto st31;
		case 31u: goto st32;
		case 43u: goto tr25;
		case 49u: goto tr29;
		case 80u: goto tr31;
		case 112u: goto tr33;
		case 115u: goto st44;
		case 119u: goto tr36;
		case 162u: goto tr0;
		case 164u: goto st34;
		case 165u: goto st1;
		case 172u: goto st34;
		case 174u: goto st49;
		case 195u: goto tr41;
		case 196u: goto tr33;
		case 197u: goto tr42;
		case 199u: goto st51;
		case 212u: goto tr28;
		case 215u: goto tr44;
		case 218u: goto tr45;
		case 222u: goto tr45;
		case 224u: goto tr45;
		case 229u: goto tr32;
		case 231u: goto tr46;
		case 234u: goto tr45;
		case 238u: goto tr45;
		case 244u: goto tr28;
		case 246u: goto tr45;
		case 247u: goto tr47;
		case 251u: goto tr28;
	}
	if ( (*p) < 116u ) {
		if ( (*p) < 64u ) {
			if ( (*p) < 40u ) {
				if ( (*p) > 3u ) {
					if ( 16u <= (*p) && (*p) <= 21u )
						goto tr23;
				} else if ( (*p) >= 2u )
					goto st1;
			} else if ( (*p) > 41u ) {
				if ( (*p) > 45u ) {
					if ( 46u <= (*p) && (*p) <= 47u )
						goto tr23;
				} else if ( (*p) >= 42u )
					goto tr28;
			} else
				goto tr23;
		} else if ( (*p) > 79u ) {
			if ( (*p) < 92u ) {
				if ( (*p) > 89u ) {
					if ( 90u <= (*p) && (*p) <= 91u )
						goto tr28;
				} else if ( (*p) >= 81u )
					goto tr23;
			} else if ( (*p) > 95u ) {
				if ( (*p) < 110u ) {
					if ( 96u <= (*p) && (*p) <= 107u )
						goto tr32;
				} else if ( (*p) > 111u ) {
					if ( 113u <= (*p) && (*p) <= 114u )
						goto st43;
				} else
					goto tr32;
			} else
				goto tr23;
		} else
			goto tr30;
	} else if ( (*p) > 118u ) {
		if ( (*p) < 194u ) {
			if ( (*p) < 144u ) {
				if ( (*p) > 127u ) {
					if ( 128u <= (*p) && (*p) <= 143u )
						goto st45;
				} else if ( (*p) >= 126u )
					goto tr32;
			} else if ( (*p) > 159u ) {
				if ( (*p) < 182u ) {
					if ( 173u <= (*p) && (*p) <= 177u )
						goto st1;
				} else if ( (*p) > 183u ) {
					if ( 188u <= (*p) && (*p) <= 193u )
						goto st1;
				} else
					goto st1;
			} else
				goto tr30;
		} else if ( (*p) > 198u ) {
			if ( (*p) < 216u ) {
				if ( (*p) > 207u ) {
					if ( 209u <= (*p) && (*p) <= 213u )
						goto tr32;
				} else if ( (*p) >= 200u )
					goto tr0;
			} else if ( (*p) > 226u ) {
				if ( (*p) < 232u ) {
					if ( 227u <= (*p) && (*p) <= 228u )
						goto tr45;
				} else if ( (*p) > 239u ) {
					if ( 241u <= (*p) && (*p) <= 254u )
						goto tr32;
				} else
					goto tr32;
			} else
				goto tr32;
		} else
			goto tr40;
	} else
		goto tr32;
	goto tr19;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	switch( (*p) ) {
		case 12u: goto st2;
		case 13u: goto st3;
		case 28u: goto st2;
		case 29u: goto st3;
		case 36u: goto st2;
		case 37u: goto st3;
		case 44u: goto st2;
		case 45u: goto st3;
		case 76u: goto st8;
		case 92u: goto st8;
		case 100u: goto st8;
		case 108u: goto st8;
		case 140u: goto st9;
		case 156u: goto st9;
		case 164u: goto st9;
		case 172u: goto st9;
	}
	if ( (*p) < 88u ) {
		if ( (*p) < 24u ) {
			if ( 8u <= (*p) && (*p) <= 15u )
				goto tr0;
		} else if ( (*p) > 47u ) {
			if ( 72u <= (*p) && (*p) <= 79u )
				goto st7;
		} else
			goto tr0;
	} else if ( (*p) > 111u ) {
		if ( (*p) < 152u ) {
			if ( 136u <= (*p) && (*p) <= 143u )
				goto st3;
		} else if ( (*p) > 175u ) {
			if ( (*p) > 207u ) {
				if ( 216u <= (*p) && (*p) <= 239u )
					goto tr0;
			} else if ( (*p) >= 200u )
				goto tr0;
		} else
			goto st3;
	} else
		goto st7;
	goto tr19;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	switch( (*p) ) {
		case 36u: goto st2;
		case 37u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 60u: goto st2;
		case 61u: goto st3;
		case 100u: goto st8;
		case 116u: goto st8;
		case 124u: goto st8;
		case 164u: goto st9;
		case 180u: goto st9;
		case 188u: goto st9;
		case 208u: goto tr49;
	}
	if ( (*p) < 160u ) {
		if ( (*p) < 48u ) {
			if ( 32u <= (*p) && (*p) <= 39u )
				goto tr0;
		} else if ( (*p) > 63u ) {
			if ( (*p) > 103u ) {
				if ( 112u <= (*p) && (*p) <= 127u )
					goto st7;
			} else if ( (*p) >= 96u )
				goto st7;
		} else
			goto tr0;
	} else if ( (*p) > 167u ) {
		if ( (*p) < 200u ) {
			if ( 176u <= (*p) && (*p) <= 191u )
				goto st3;
		} else if ( (*p) > 201u ) {
			if ( (*p) > 231u ) {
				if ( 240u <= (*p) && (*p) <= 247u )
					goto tr0;
			} else if ( (*p) >= 224u )
				goto tr0;
		} else
			goto tr48;
	} else
		goto st3;
	goto tr19;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 4u: goto tr51;
		case 5u: goto tr52;
		case 12u: goto tr51;
		case 13u: goto tr52;
		case 68u: goto tr54;
		case 76u: goto tr54;
		case 132u: goto tr55;
		case 140u: goto tr55;
	}
	if ( (*p) < 64u ) {
		if ( (*p) <= 15u )
			goto tr50;
	} else if ( (*p) > 79u ) {
		if ( 128u <= (*p) && (*p) <= 143u )
			goto tr52;
	} else
		goto tr53;
	goto tr19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	switch( (*p) ) {
		case 4u: goto st21;
		case 5u: goto st22;
		case 12u: goto st21;
		case 13u: goto st22;
		case 20u: goto st21;
		case 21u: goto st22;
		case 28u: goto st21;
		case 29u: goto st22;
		case 36u: goto st21;
		case 37u: goto st22;
		case 44u: goto st21;
		case 45u: goto st22;
		case 52u: goto st21;
		case 53u: goto st22;
		case 60u: goto st21;
		case 61u: goto st22;
		case 68u: goto st27;
		case 76u: goto st27;
		case 84u: goto st27;
		case 92u: goto st27;
		case 100u: goto st27;
		case 108u: goto st27;
		case 116u: goto st27;
		case 124u: goto st27;
		case 132u: goto st28;
		case 140u: goto st28;
		case 148u: goto st28;
		case 156u: goto st28;
		case 164u: goto st28;
		case 172u: goto st28;
		case 180u: goto st28;
		case 188u: goto st28;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto st22;
	} else if ( (*p) >= 64u )
		goto st26;
	goto st20;
tr66:
	{
    SET_DISP_TYPE(DISP32);
    SET_DISP_PTR(p - 3);
  }
	goto st20;
tr67:
	{
    SET_DISP_TYPE(DISP8);
    SET_DISP_PTR(p);
  }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 12u: goto tr62;
		case 13u: goto tr21;
		case 28u: goto tr62;
		case 29u: goto tr21;
		case 138u: goto tr62;
		case 142u: goto tr62;
		case 144u: goto tr21;
		case 148u: goto tr21;
		case 154u: goto tr21;
		case 158u: goto tr21;
		case 160u: goto tr21;
		case 164u: goto tr21;
		case 170u: goto tr21;
		case 174u: goto tr21;
		case 176u: goto tr21;
		case 180u: goto tr21;
		case 187u: goto tr62;
		case 191u: goto tr21;
	}
	if ( (*p) < 166u ) {
		if ( 150u <= (*p) && (*p) <= 151u )
			goto tr21;
	} else if ( (*p) > 167u ) {
		if ( 182u <= (*p) && (*p) <= 183u )
			goto tr21;
	} else
		goto tr21;
	goto tr19;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	switch( (*p) ) {
		case 5u: goto st22;
		case 13u: goto st22;
		case 21u: goto st22;
		case 29u: goto st22;
		case 37u: goto st22;
		case 45u: goto st22;
		case 53u: goto st22;
		case 61u: goto st22;
		case 69u: goto st22;
		case 77u: goto st22;
		case 85u: goto st22;
		case 93u: goto st22;
		case 101u: goto st22;
		case 109u: goto st22;
		case 117u: goto st22;
		case 125u: goto st22;
		case 133u: goto st22;
		case 141u: goto st22;
		case 149u: goto st22;
		case 157u: goto st22;
		case 165u: goto st22;
		case 173u: goto st22;
		case 181u: goto st22;
		case 189u: goto st22;
		case 197u: goto st22;
		case 205u: goto st22;
		case 213u: goto st22;
		case 221u: goto st22;
		case 229u: goto st22;
		case 237u: goto st22;
		case 245u: goto st22;
		case 253u: goto st22;
	}
	goto st20;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	goto tr66;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	goto tr67;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	goto st26;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	goto st22;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	switch( (*p) ) {
		case 4u: goto tr69;
		case 5u: goto tr70;
		case 12u: goto tr69;
		case 13u: goto tr70;
		case 20u: goto tr69;
		case 21u: goto tr70;
		case 28u: goto tr69;
		case 29u: goto tr70;
		case 36u: goto tr69;
		case 37u: goto tr70;
		case 44u: goto tr69;
		case 45u: goto tr70;
		case 52u: goto tr69;
		case 53u: goto tr70;
		case 60u: goto tr69;
		case 61u: goto tr70;
		case 68u: goto tr72;
		case 76u: goto tr72;
		case 84u: goto tr72;
		case 92u: goto tr72;
		case 100u: goto tr72;
		case 108u: goto tr72;
		case 116u: goto tr72;
		case 124u: goto tr72;
		case 132u: goto tr73;
		case 140u: goto tr73;
		case 148u: goto tr73;
		case 156u: goto tr73;
		case 164u: goto tr73;
		case 172u: goto tr73;
		case 180u: goto tr73;
		case 188u: goto tr73;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto tr70;
	} else if ( (*p) >= 64u )
		goto tr71;
	goto tr68;
tr25:
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st30;
tr41:
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st30;
tr46:
	{
    SET_CPU_FEATURE(CPUFeature_EMMXSSE);
  }
	goto st30;
tr136:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st30;
tr149:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE41);
  }
	goto st30;
tr292:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st30;
tr394:
	{
    SET_REPNZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE3);
  }
	goto st30;
tr387:
	{
    SET_REPNZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE4A);
  }
	goto st30;
tr402:
	{
    SET_REPZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE4A);
  }
	goto st30;
tr428:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	switch( (*p) ) {
		case 4u: goto st2;
		case 12u: goto st2;
		case 20u: goto st2;
		case 28u: goto st2;
		case 36u: goto st2;
		case 44u: goto st2;
		case 52u: goto st2;
		case 60u: goto st2;
		case 68u: goto st8;
		case 76u: goto st8;
		case 84u: goto st8;
		case 92u: goto st8;
		case 100u: goto st8;
		case 108u: goto st8;
		case 116u: goto st8;
		case 124u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
		case 148u: goto st9;
		case 156u: goto st9;
		case 164u: goto st9;
		case 172u: goto st9;
		case 180u: goto st9;
		case 188u: goto st9;
	}
	if ( (*p) < 38u ) {
		if ( (*p) < 14u ) {
			if ( (*p) > 3u ) {
				if ( 6u <= (*p) && (*p) <= 11u )
					goto tr0;
			} else
				goto tr0;
		} else if ( (*p) > 19u ) {
			if ( (*p) > 27u ) {
				if ( 30u <= (*p) && (*p) <= 35u )
					goto tr0;
			} else if ( (*p) >= 22u )
				goto tr0;
		} else
			goto tr0;
	} else if ( (*p) > 43u ) {
		if ( (*p) < 62u ) {
			if ( (*p) > 51u ) {
				if ( 54u <= (*p) && (*p) <= 59u )
					goto tr0;
			} else if ( (*p) >= 46u )
				goto tr0;
		} else if ( (*p) > 63u ) {
			if ( (*p) > 127u ) {
				if ( 192u <= (*p) )
					goto tr19;
			} else if ( (*p) >= 64u )
				goto st7;
		} else
			goto tr0;
	} else
		goto tr0;
	goto st3;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 20u: goto st2;
		case 21u: goto st3;
		case 28u: goto st2;
		case 29u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 84u: goto st8;
		case 92u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
		case 148u: goto st9;
		case 156u: goto st9;
	}
	if ( (*p) < 64u ) {
		if ( (*p) <= 31u )
			goto tr0;
	} else if ( (*p) > 95u ) {
		if ( 128u <= (*p) && (*p) <= 159u )
			goto st3;
	} else
		goto st7;
	goto tr19;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 68u: goto st8;
		case 132u: goto st9;
	}
	if ( (*p) < 64u ) {
		if ( (*p) <= 7u )
			goto tr0;
	} else if ( (*p) > 71u ) {
		if ( (*p) > 135u ) {
			if ( 192u <= (*p) && (*p) <= 199u )
				goto tr0;
		} else if ( (*p) >= 128u )
			goto st3;
	} else
		goto st7;
	goto tr19;
tr31:
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st33;
tr44:
	{
    SET_CPU_FEATURE(CPUFeature_EMMXSSE);
  }
	goto st33;
tr47:
	{
    SET_CPU_FEATURE(CPUFeature_EMMX);
  }
	goto st33;
tr139:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st33;
tr143:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE4A);
  }
	goto st33;
tr303:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st33;
tr393:
	{
    SET_REPNZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st33;
tr391:
	{
    SET_REPNZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE4A);
  }
	goto st33;
tr406:
	{
    SET_REPZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( 192u <= (*p) )
		goto tr0;
	goto tr19;
tr40:
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st34;
tr33:
	{
    SET_CPU_FEATURE(CPUFeature_EMMXSSE);
  }
	goto st34;
tr140:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st34;
tr153:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSSE3);
  }
	goto st34;
tr152:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE41);
  }
	goto st34;
tr157:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE42);
  }
	goto st34;
tr158:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_AES);
  }
	goto st34;
tr156:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_CLMUL);
  }
	goto st34;
tr234:
	{
    SET_CPU_FEATURE(CPUFeature_XOP);
  }
	goto st34;
tr293:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st34;
tr340:
	{
    SET_CPU_FEATURE(CPUFeature_AESAVX);
  }
	goto st34;
tr354:
	{
    SET_CPU_FEATURE(CPUFeature_F16C);
  }
	goto st34;
tr336:
	{
    SET_CPU_FEATURE(CPUFeature_CLMULAVX);
  }
	goto st34;
tr389:
	{
    SET_REPNZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st34;
tr405:
	{
    SET_REPZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st34;
tr404:
	{
    SET_REPZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st34;
tr425:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 4u: goto st35;
		case 5u: goto st36;
		case 12u: goto st35;
		case 13u: goto st36;
		case 20u: goto st35;
		case 21u: goto st36;
		case 28u: goto st35;
		case 29u: goto st36;
		case 36u: goto st35;
		case 37u: goto st36;
		case 44u: goto st35;
		case 45u: goto st36;
		case 52u: goto st35;
		case 53u: goto st36;
		case 60u: goto st35;
		case 61u: goto st36;
		case 68u: goto st41;
		case 76u: goto st41;
		case 84u: goto st41;
		case 92u: goto st41;
		case 100u: goto st41;
		case 108u: goto st41;
		case 116u: goto st41;
		case 124u: goto st41;
		case 132u: goto st42;
		case 140u: goto st42;
		case 148u: goto st42;
		case 156u: goto st42;
		case 164u: goto st42;
		case 172u: goto st42;
		case 180u: goto st42;
		case 188u: goto st42;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto st36;
	} else if ( (*p) >= 64u )
		goto st40;
	goto st10;
tr160:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE41);
  }
	goto st35;
tr167:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st35;
tr307:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 5u: goto st36;
		case 13u: goto st36;
		case 21u: goto st36;
		case 29u: goto st36;
		case 37u: goto st36;
		case 45u: goto st36;
		case 53u: goto st36;
		case 61u: goto st36;
		case 69u: goto st36;
		case 77u: goto st36;
		case 85u: goto st36;
		case 93u: goto st36;
		case 101u: goto st36;
		case 109u: goto st36;
		case 117u: goto st36;
		case 125u: goto st36;
		case 133u: goto st36;
		case 141u: goto st36;
		case 149u: goto st36;
		case 157u: goto st36;
		case 165u: goto st36;
		case 173u: goto st36;
		case 181u: goto st36;
		case 189u: goto st36;
		case 197u: goto st36;
		case 205u: goto st36;
		case 213u: goto st36;
		case 221u: goto st36;
		case 229u: goto st36;
		case 237u: goto st36;
		case 245u: goto st36;
		case 253u: goto st36;
	}
	goto st10;
tr161:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE41);
  }
	goto st36;
tr168:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st36;
tr308:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	goto tr83;
tr162:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE41);
  }
	goto st40;
tr169:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st40;
tr309:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	goto tr84;
tr163:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE41);
  }
	goto st41;
tr170:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st41;
tr310:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	goto st40;
tr164:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE41);
  }
	goto st42;
tr171:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE);
  }
	goto st42;
tr311:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	goto st36;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) < 224u ) {
		if ( 208u <= (*p) && (*p) <= 215u )
			goto tr85;
	} else if ( (*p) > 231u ) {
		if ( 240u <= (*p) && (*p) <= 247u )
			goto tr85;
	} else
		goto tr85;
	goto tr19;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) > 215u ) {
		if ( 240u <= (*p) && (*p) <= 247u )
			goto tr85;
	} else if ( (*p) >= 208u )
		goto tr85;
	goto tr19;
tr448:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	goto tr89;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 20u: goto tr69;
		case 21u: goto tr70;
		case 28u: goto tr69;
		case 29u: goto tr70;
		case 36u: goto tr90;
		case 37u: goto tr91;
		case 44u: goto tr90;
		case 45u: goto tr91;
		case 52u: goto tr90;
		case 53u: goto tr91;
		case 60u: goto tr93;
		case 61u: goto tr94;
		case 84u: goto tr72;
		case 92u: goto tr72;
		case 100u: goto tr96;
		case 108u: goto tr96;
		case 116u: goto tr96;
		case 124u: goto tr98;
		case 148u: goto tr73;
		case 156u: goto tr73;
		case 164u: goto tr99;
		case 172u: goto tr99;
		case 180u: goto tr99;
		case 188u: goto tr100;
		case 232u: goto tr101;
		case 240u: goto tr101;
		case 248u: goto tr102;
	}
	if ( (*p) < 96u ) {
		if ( (*p) < 32u ) {
			if ( 16u <= (*p) && (*p) <= 31u )
				goto tr68;
		} else if ( (*p) > 55u ) {
			if ( (*p) > 63u ) {
				if ( 80u <= (*p) && (*p) <= 95u )
					goto tr71;
			} else if ( (*p) >= 56u )
				goto tr92;
		} else
			goto tr49;
	} else if ( (*p) > 119u ) {
		if ( (*p) < 144u ) {
			if ( 120u <= (*p) && (*p) <= 127u )
				goto tr97;
		} else if ( (*p) > 159u ) {
			if ( (*p) > 183u ) {
				if ( 184u <= (*p) && (*p) <= 191u )
					goto tr94;
			} else if ( (*p) >= 160u )
				goto tr91;
		} else
			goto tr70;
	} else
		goto tr95;
	goto tr19;
tr42:
	{
    SET_CPU_FEATURE(CPUFeature_EMMXSSE);
  }
	goto st50;
tr146:
	{
    SET_DATA16_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE2);
  }
	goto st50;
tr306:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( 192u <= (*p) )
		goto st10;
	goto tr19;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	switch( (*p) ) {
		case 12u: goto tr104;
		case 13u: goto tr105;
		case 76u: goto tr107;
		case 140u: goto tr108;
	}
	if ( (*p) < 72u ) {
		if ( 8u <= (*p) && (*p) <= 15u )
			goto tr103;
	} else if ( (*p) > 79u ) {
		if ( 136u <= (*p) && (*p) <= 143u )
			goto tr105;
	} else
		goto tr106;
	goto tr19;
tr419:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	{
    SET_BRANCH_NOT_TAKEN(TRUE);
  }
	goto st52;
tr420:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	{
    SET_BRANCH_TAKEN(TRUE);
  }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	if ( (*p) == 15u )
		goto st53;
	if ( 112u <= (*p) && (*p) <= 127u )
		goto st54;
	goto tr19;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( 128u <= (*p) && (*p) <= 143u )
		goto st45;
	goto tr19;
tr426:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	goto tr111;
tr422:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	switch( (*p) ) {
		case 139u: goto st56;
		case 161u: goto st57;
	}
	goto tr19;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 5u: goto st57;
		case 13u: goto st57;
		case 21u: goto st57;
		case 29u: goto st57;
		case 37u: goto st57;
		case 45u: goto st57;
		case 53u: goto st57;
		case 61u: goto st57;
	}
	goto tr19;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 0u: goto st58;
		case 4u: goto st58;
	}
	goto tr19;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	if ( (*p) == 0u )
		goto st59;
	goto tr19;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	if ( (*p) == 0u )
		goto st60;
	goto tr19;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	if ( (*p) == 0u )
		goto tr0;
	goto tr19;
tr423:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	{
    SET_DATA16_PREFIX(TRUE);
  }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 1u: goto st1;
		case 3u: goto st1;
		case 5u: goto st62;
		case 9u: goto st1;
		case 11u: goto st1;
		case 13u: goto st62;
		case 15u: goto st64;
		case 17u: goto st1;
		case 19u: goto st1;
		case 21u: goto st62;
		case 25u: goto st1;
		case 27u: goto st1;
		case 29u: goto st62;
		case 33u: goto st1;
		case 35u: goto st1;
		case 37u: goto st62;
		case 41u: goto st1;
		case 43u: goto st1;
		case 45u: goto st62;
		case 46u: goto st74;
		case 49u: goto st1;
		case 51u: goto st1;
		case 53u: goto st62;
		case 57u: goto st1;
		case 59u: goto st1;
		case 61u: goto st62;
		case 102u: goto st82;
		case 104u: goto st62;
		case 105u: goto st87;
		case 107u: goto st34;
		case 129u: goto st87;
		case 131u: goto st34;
		case 133u: goto st1;
		case 135u: goto st1;
		case 137u: goto st1;
		case 139u: goto st1;
		case 141u: goto st30;
		case 143u: goto st32;
		case 161u: goto st3;
		case 163u: goto st3;
		case 165u: goto tr0;
		case 167u: goto tr0;
		case 169u: goto st62;
		case 171u: goto tr0;
		case 173u: goto tr0;
		case 175u: goto tr0;
		case 193u: goto st96;
		case 199u: goto st97;
		case 209u: goto st98;
		case 211u: goto st98;
		case 240u: goto tr126;
		case 242u: goto tr127;
		case 243u: goto tr128;
		case 247u: goto st110;
		case 255u: goto st111;
	}
	if ( (*p) < 144u ) {
		if ( 64u <= (*p) && (*p) <= 95u )
			goto tr0;
	} else if ( (*p) > 153u ) {
		if ( (*p) > 157u ) {
			if ( 184u <= (*p) && (*p) <= 191u )
				goto st62;
		} else if ( (*p) >= 156u )
			goto tr0;
	} else
		goto tr0;
	goto tr19;
tr192:
	{
    SET_DISP_TYPE(DISP32);
    SET_DISP_PTR(p - 3);
  }
	goto st62;
tr193:
	{
    SET_DISP_TYPE(DISP8);
    SET_DISP_PTR(p);
  }
	goto st62;
tr438:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	goto tr132;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 0u: goto st65;
		case 1u: goto st66;
		case 31u: goto st32;
		case 43u: goto tr136;
		case 56u: goto st67;
		case 58u: goto st68;
		case 80u: goto tr139;
		case 81u: goto tr135;
		case 112u: goto tr140;
		case 115u: goto st72;
		case 121u: goto tr143;
		case 164u: goto st34;
		case 165u: goto st1;
		case 172u: goto st34;
		case 173u: goto st1;
		case 175u: goto st1;
		case 177u: goto st1;
		case 182u: goto st1;
		case 193u: goto st1;
		case 194u: goto tr140;
		case 196u: goto st73;
		case 197u: goto tr146;
		case 198u: goto tr140;
		case 215u: goto tr139;
		case 231u: goto tr136;
		case 247u: goto tr139;
	}
	if ( (*p) < 84u ) {
		if ( (*p) < 20u ) {
			if ( (*p) < 16u ) {
				if ( 2u <= (*p) && (*p) <= 3u )
					goto st1;
			} else if ( (*p) > 17u ) {
				if ( 18u <= (*p) && (*p) <= 19u )
					goto tr136;
			} else
				goto tr135;
		} else if ( (*p) > 21u ) {
			if ( (*p) < 40u ) {
				if ( 22u <= (*p) && (*p) <= 23u )
					goto tr136;
			} else if ( (*p) > 47u ) {
				if ( 64u <= (*p) && (*p) <= 79u )
					goto tr30;
			} else
				goto tr135;
		} else
			goto tr135;
	} else if ( (*p) > 111u ) {
		if ( (*p) < 126u ) {
			if ( (*p) < 116u ) {
				if ( 113u <= (*p) && (*p) <= 114u )
					goto st71;
			} else if ( (*p) > 118u ) {
				if ( 124u <= (*p) && (*p) <= 125u )
					goto tr144;
			} else
				goto tr135;
		} else if ( (*p) > 127u ) {
			if ( (*p) < 208u ) {
				if ( 188u <= (*p) && (*p) <= 190u )
					goto st1;
			} else if ( (*p) > 239u ) {
				if ( 241u <= (*p) && (*p) <= 254u )
					goto tr135;
			} else
				goto tr135;
		} else
			goto tr135;
	} else
		goto tr135;
	goto tr19;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	if ( 200u <= (*p) && (*p) <= 207u )
		goto tr0;
	goto tr19;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	if ( 224u <= (*p) && (*p) <= 231u )
		goto tr0;
	goto tr19;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	switch( (*p) ) {
		case 16u: goto tr148;
		case 23u: goto tr148;
		case 42u: goto tr149;
		case 55u: goto tr150;
	}
	if ( (*p) < 32u ) {
		if ( (*p) < 20u ) {
			if ( (*p) <= 11u )
				goto tr147;
		} else if ( (*p) > 21u ) {
			if ( 28u <= (*p) && (*p) <= 30u )
				goto tr147;
		} else
			goto tr148;
	} else if ( (*p) > 37u ) {
		if ( (*p) < 48u ) {
			if ( 40u <= (*p) && (*p) <= 43u )
				goto tr148;
		} else if ( (*p) > 53u ) {
			if ( (*p) > 65u ) {
				if ( 219u <= (*p) && (*p) <= 223u )
					goto tr151;
			} else if ( (*p) >= 56u )
				goto tr148;
		} else
			goto tr148;
	} else
		goto tr148;
	goto tr19;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 15u: goto tr153;
		case 22u: goto st70;
		case 23u: goto tr152;
		case 32u: goto st69;
		case 68u: goto tr156;
		case 223u: goto tr158;
	}
	if ( (*p) < 33u ) {
		if ( (*p) > 14u ) {
			if ( 20u <= (*p) && (*p) <= 21u )
				goto st69;
		} else if ( (*p) >= 8u )
			goto tr152;
	} else if ( (*p) > 34u ) {
		if ( (*p) > 66u ) {
			if ( 96u <= (*p) && (*p) <= 99u )
				goto tr157;
		} else if ( (*p) >= 64u )
			goto tr152;
	} else
		goto tr152;
	goto tr19;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 4u: goto tr160;
		case 5u: goto tr161;
		case 12u: goto tr160;
		case 13u: goto tr161;
		case 20u: goto tr160;
		case 21u: goto tr161;
		case 28u: goto tr160;
		case 29u: goto tr161;
		case 36u: goto tr160;
		case 37u: goto tr161;
		case 44u: goto tr160;
		case 45u: goto tr161;
		case 52u: goto tr160;
		case 53u: goto tr161;
		case 60u: goto tr160;
		case 61u: goto tr161;
		case 68u: goto tr163;
		case 76u: goto tr163;
		case 84u: goto tr163;
		case 92u: goto tr163;
		case 100u: goto tr163;
		case 108u: goto tr163;
		case 116u: goto tr163;
		case 124u: goto tr163;
		case 132u: goto tr164;
		case 140u: goto tr164;
		case 148u: goto tr164;
		case 156u: goto tr164;
		case 164u: goto tr164;
		case 172u: goto tr164;
		case 180u: goto tr164;
		case 188u: goto tr164;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto tr161;
	} else if ( (*p) >= 64u )
		goto tr162;
	goto tr159;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( 192u <= (*p) )
		goto tr159;
	goto tr19;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) < 224u ) {
		if ( 208u <= (*p) && (*p) <= 215u )
			goto tr165;
	} else if ( (*p) > 231u ) {
		if ( 240u <= (*p) && (*p) <= 247u )
			goto tr165;
	} else
		goto tr165;
	goto tr19;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( (*p) > 223u ) {
		if ( 240u <= (*p) )
			goto tr165;
	} else if ( (*p) >= 208u )
		goto tr165;
	goto tr19;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 4u: goto tr167;
		case 5u: goto tr168;
		case 12u: goto tr167;
		case 13u: goto tr168;
		case 20u: goto tr167;
		case 21u: goto tr168;
		case 28u: goto tr167;
		case 29u: goto tr168;
		case 36u: goto tr167;
		case 37u: goto tr168;
		case 44u: goto tr167;
		case 45u: goto tr168;
		case 52u: goto tr167;
		case 53u: goto tr168;
		case 60u: goto tr167;
		case 61u: goto tr168;
		case 68u: goto tr170;
		case 76u: goto tr170;
		case 84u: goto tr170;
		case 92u: goto tr170;
		case 100u: goto tr170;
		case 108u: goto tr170;
		case 116u: goto tr170;
		case 124u: goto tr170;
		case 132u: goto tr171;
		case 140u: goto tr171;
		case 148u: goto tr171;
		case 156u: goto tr171;
		case 164u: goto tr171;
		case 172u: goto tr171;
		case 180u: goto tr171;
		case 188u: goto tr171;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto tr168;
	} else if ( (*p) >= 64u )
		goto tr169;
	goto tr166;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	if ( (*p) == 15u )
		goto st75;
	goto tr19;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( (*p) == 31u )
		goto st76;
	goto tr19;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( (*p) == 132u )
		goto st77;
	goto tr19;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( (*p) == 0u )
		goto st78;
	goto tr19;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 0u )
		goto st79;
	goto tr19;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	if ( (*p) == 0u )
		goto st80;
	goto tr19;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 0u )
		goto st81;
	goto tr19;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( (*p) == 0u )
		goto tr179;
	goto tr19;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 46u: goto st74;
		case 102u: goto st83;
	}
	goto tr19;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	switch( (*p) ) {
		case 46u: goto st74;
		case 102u: goto st84;
	}
	goto tr19;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	switch( (*p) ) {
		case 46u: goto st74;
		case 102u: goto st85;
	}
	goto tr19;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 46u: goto st74;
		case 102u: goto st86;
	}
	goto tr19;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 46u )
		goto st74;
	goto tr19;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 4u: goto st88;
		case 5u: goto st89;
		case 12u: goto st88;
		case 13u: goto st89;
		case 20u: goto st88;
		case 21u: goto st89;
		case 28u: goto st88;
		case 29u: goto st89;
		case 36u: goto st88;
		case 37u: goto st89;
		case 44u: goto st88;
		case 45u: goto st89;
		case 52u: goto st88;
		case 53u: goto st89;
		case 60u: goto st88;
		case 61u: goto st89;
		case 68u: goto st94;
		case 76u: goto st94;
		case 84u: goto st94;
		case 92u: goto st94;
		case 100u: goto st94;
		case 108u: goto st94;
		case 116u: goto st94;
		case 124u: goto st94;
		case 132u: goto st95;
		case 140u: goto st95;
		case 148u: goto st95;
		case 156u: goto st95;
		case 164u: goto st95;
		case 172u: goto st95;
		case 180u: goto st95;
		case 188u: goto st95;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto st89;
	} else if ( (*p) >= 64u )
		goto st93;
	goto st62;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 5u: goto st89;
		case 13u: goto st89;
		case 21u: goto st89;
		case 29u: goto st89;
		case 37u: goto st89;
		case 45u: goto st89;
		case 53u: goto st89;
		case 61u: goto st89;
		case 69u: goto st89;
		case 77u: goto st89;
		case 85u: goto st89;
		case 93u: goto st89;
		case 101u: goto st89;
		case 109u: goto st89;
		case 117u: goto st89;
		case 125u: goto st89;
		case 133u: goto st89;
		case 141u: goto st89;
		case 149u: goto st89;
		case 157u: goto st89;
		case 165u: goto st89;
		case 173u: goto st89;
		case 181u: goto st89;
		case 189u: goto st89;
		case 197u: goto st89;
		case 205u: goto st89;
		case 213u: goto st89;
		case 221u: goto st89;
		case 229u: goto st89;
		case 237u: goto st89;
		case 245u: goto st89;
		case 253u: goto st89;
	}
	goto st62;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	goto st92;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	goto tr192;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	goto tr193;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	goto st93;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	goto st89;
tr432:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 4u: goto st35;
		case 5u: goto st36;
		case 12u: goto st35;
		case 13u: goto st36;
		case 20u: goto st35;
		case 21u: goto st36;
		case 28u: goto st35;
		case 29u: goto st36;
		case 36u: goto st35;
		case 37u: goto st36;
		case 44u: goto st35;
		case 45u: goto st36;
		case 60u: goto st35;
		case 61u: goto st36;
		case 68u: goto st41;
		case 76u: goto st41;
		case 84u: goto st41;
		case 92u: goto st41;
		case 100u: goto st41;
		case 108u: goto st41;
		case 124u: goto st41;
		case 132u: goto st42;
		case 140u: goto st42;
		case 148u: goto st42;
		case 156u: goto st42;
		case 164u: goto st42;
		case 172u: goto st42;
		case 188u: goto st42;
	}
	if ( (*p) < 120u ) {
		if ( (*p) < 64u ) {
			if ( 48u <= (*p) && (*p) <= 55u )
				goto tr19;
		} else if ( (*p) > 111u ) {
			if ( 112u <= (*p) && (*p) <= 119u )
				goto tr19;
		} else
			goto st40;
	} else if ( (*p) > 127u ) {
		if ( (*p) < 176u ) {
			if ( 128u <= (*p) && (*p) <= 175u )
				goto st36;
		} else if ( (*p) > 183u ) {
			if ( (*p) > 191u ) {
				if ( 240u <= (*p) && (*p) <= 247u )
					goto tr19;
			} else if ( (*p) >= 184u )
				goto st36;
		} else
			goto tr19;
	} else
		goto st40;
	goto st10;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	switch( (*p) ) {
		case 4u: goto st88;
		case 5u: goto st89;
		case 68u: goto st94;
		case 132u: goto st95;
	}
	if ( (*p) < 64u ) {
		if ( (*p) <= 7u )
			goto st62;
	} else if ( (*p) > 71u ) {
		if ( (*p) > 135u ) {
			if ( 192u <= (*p) && (*p) <= 199u )
				goto st62;
		} else if ( (*p) >= 128u )
			goto st89;
	} else
		goto st93;
	goto tr19;
tr439:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 20u: goto st2;
		case 21u: goto st3;
		case 28u: goto st2;
		case 29u: goto st3;
		case 36u: goto st2;
		case 37u: goto st3;
		case 44u: goto st2;
		case 45u: goto st3;
		case 60u: goto st2;
		case 61u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 84u: goto st8;
		case 92u: goto st8;
		case 100u: goto st8;
		case 108u: goto st8;
		case 124u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
		case 148u: goto st9;
		case 156u: goto st9;
		case 164u: goto st9;
		case 172u: goto st9;
		case 188u: goto st9;
	}
	if ( (*p) < 120u ) {
		if ( (*p) < 64u ) {
			if ( 48u <= (*p) && (*p) <= 55u )
				goto tr19;
		} else if ( (*p) > 111u ) {
			if ( 112u <= (*p) && (*p) <= 119u )
				goto tr19;
		} else
			goto st7;
	} else if ( (*p) > 127u ) {
		if ( (*p) < 176u ) {
			if ( 128u <= (*p) && (*p) <= 175u )
				goto st3;
		} else if ( (*p) > 183u ) {
			if ( (*p) > 191u ) {
				if ( 240u <= (*p) && (*p) <= 247u )
					goto tr19;
			} else if ( (*p) >= 184u )
				goto st3;
		} else
			goto tr19;
	} else
		goto st7;
	goto tr0;
tr126:
	{
    SET_LOCK_PREFIX(TRUE);
  }
	goto st99;
tr381:
	{
    SET_DATA16_PREFIX(TRUE);
  }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 1u: goto st30;
		case 9u: goto st30;
		case 15u: goto st100;
		case 17u: goto st30;
		case 25u: goto st30;
		case 33u: goto st30;
		case 41u: goto st30;
		case 49u: goto st30;
		case 129u: goto st101;
		case 131u: goto st102;
		case 135u: goto st30;
		case 247u: goto st103;
		case 255u: goto st104;
	}
	goto tr19;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	switch( (*p) ) {
		case 177u: goto st30;
		case 193u: goto st30;
	}
	goto tr19;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	switch( (*p) ) {
		case 4u: goto st88;
		case 5u: goto st89;
		case 12u: goto st88;
		case 13u: goto st89;
		case 20u: goto st88;
		case 21u: goto st89;
		case 28u: goto st88;
		case 29u: goto st89;
		case 36u: goto st88;
		case 37u: goto st89;
		case 44u: goto st88;
		case 45u: goto st89;
		case 52u: goto st88;
		case 53u: goto st89;
		case 68u: goto st94;
		case 76u: goto st94;
		case 84u: goto st94;
		case 92u: goto st94;
		case 100u: goto st94;
		case 108u: goto st94;
		case 116u: goto st94;
		case 132u: goto st95;
		case 140u: goto st95;
		case 148u: goto st95;
		case 156u: goto st95;
		case 164u: goto st95;
		case 172u: goto st95;
		case 180u: goto st95;
	}
	if ( (*p) < 64u ) {
		if ( (*p) <= 55u )
			goto st62;
	} else if ( (*p) > 119u ) {
		if ( 128u <= (*p) && (*p) <= 183u )
			goto st89;
	} else
		goto st93;
	goto tr19;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 4u: goto st35;
		case 5u: goto st36;
		case 12u: goto st35;
		case 13u: goto st36;
		case 20u: goto st35;
		case 21u: goto st36;
		case 28u: goto st35;
		case 29u: goto st36;
		case 36u: goto st35;
		case 37u: goto st36;
		case 44u: goto st35;
		case 45u: goto st36;
		case 52u: goto st35;
		case 53u: goto st36;
		case 68u: goto st41;
		case 76u: goto st41;
		case 84u: goto st41;
		case 92u: goto st41;
		case 100u: goto st41;
		case 108u: goto st41;
		case 116u: goto st41;
		case 132u: goto st42;
		case 140u: goto st42;
		case 148u: goto st42;
		case 156u: goto st42;
		case 164u: goto st42;
		case 172u: goto st42;
		case 180u: goto st42;
	}
	if ( (*p) < 64u ) {
		if ( (*p) <= 55u )
			goto st10;
	} else if ( (*p) > 119u ) {
		if ( 128u <= (*p) && (*p) <= 183u )
			goto st36;
	} else
		goto st40;
	goto tr19;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 20u: goto st2;
		case 21u: goto st3;
		case 28u: goto st2;
		case 29u: goto st3;
		case 84u: goto st8;
		case 92u: goto st8;
		case 148u: goto st9;
		case 156u: goto st9;
	}
	if ( (*p) < 80u ) {
		if ( 16u <= (*p) && (*p) <= 31u )
			goto tr0;
	} else if ( (*p) > 95u ) {
		if ( 144u <= (*p) && (*p) <= 159u )
			goto st3;
	} else
		goto st7;
	goto tr19;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
	}
	if ( (*p) < 64u ) {
		if ( (*p) <= 15u )
			goto tr0;
	} else if ( (*p) > 79u ) {
		if ( 128u <= (*p) && (*p) <= 143u )
			goto st3;
	} else
		goto st7;
	goto tr19;
tr127:
	{
    SET_REPNZ_PREFIX(TRUE);
  }
	goto st105;
tr384:
	{
    SET_DATA16_PREFIX(TRUE);
  }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	switch( (*p) ) {
		case 15u: goto st106;
		case 167u: goto tr0;
		case 175u: goto tr0;
	}
	goto tr19;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( (*p) == 56u )
		goto st107;
	goto tr19;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	if ( (*p) == 241u )
		goto tr201;
	goto tr19;
tr128:
	{
    SET_REPZ_PREFIX(TRUE);
  }
	{
    SET_REPZ_PREFIX(TRUE);
  }
	goto st108;
tr398:
	{
    SET_DATA16_PREFIX(TRUE);
  }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	switch( (*p) ) {
		case 15u: goto st109;
		case 165u: goto tr0;
		case 167u: goto tr0;
		case 171u: goto tr0;
		case 173u: goto tr0;
		case 175u: goto tr0;
	}
	goto tr19;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	switch( (*p) ) {
		case 184u: goto tr203;
		case 188u: goto tr204;
		case 189u: goto tr205;
	}
	goto tr19;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	switch( (*p) ) {
		case 4u: goto st88;
		case 5u: goto st89;
		case 20u: goto st2;
		case 21u: goto st3;
		case 28u: goto st2;
		case 29u: goto st3;
		case 36u: goto st2;
		case 37u: goto st3;
		case 44u: goto st2;
		case 45u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 60u: goto st2;
		case 61u: goto st3;
		case 68u: goto st94;
		case 84u: goto st8;
		case 92u: goto st8;
		case 100u: goto st8;
		case 108u: goto st8;
		case 116u: goto st8;
		case 124u: goto st8;
		case 132u: goto st95;
		case 148u: goto st9;
		case 156u: goto st9;
		case 164u: goto st9;
		case 172u: goto st9;
		case 180u: goto st9;
		case 188u: goto st9;
	}
	if ( (*p) < 80u ) {
		if ( (*p) < 8u ) {
			if ( (*p) <= 7u )
				goto st62;
		} else if ( (*p) > 15u ) {
			if ( (*p) > 71u ) {
				if ( 72u <= (*p) && (*p) <= 79u )
					goto tr19;
			} else if ( (*p) >= 64u )
				goto st93;
		} else
			goto tr19;
	} else if ( (*p) > 127u ) {
		if ( (*p) < 144u ) {
			if ( (*p) > 135u ) {
				if ( 136u <= (*p) && (*p) <= 143u )
					goto tr19;
			} else if ( (*p) >= 128u )
				goto st89;
		} else if ( (*p) > 191u ) {
			if ( (*p) > 199u ) {
				if ( 200u <= (*p) && (*p) <= 207u )
					goto tr19;
			} else if ( (*p) >= 192u )
				goto st62;
		} else
			goto st3;
	} else
		goto st7;
	goto tr0;
tr455:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 116u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
		case 180u: goto st9;
	}
	if ( (*p) < 112u ) {
		if ( (*p) < 48u ) {
			if ( (*p) <= 15u )
				goto tr0;
		} else if ( (*p) > 55u ) {
			if ( 64u <= (*p) && (*p) <= 79u )
				goto st7;
		} else
			goto tr0;
	} else if ( (*p) > 119u ) {
		if ( (*p) < 176u ) {
			if ( 128u <= (*p) && (*p) <= 143u )
				goto st3;
		} else if ( (*p) > 183u ) {
			if ( (*p) > 207u ) {
				if ( 240u <= (*p) && (*p) <= 247u )
					goto tr0;
			} else if ( (*p) >= 192u )
				goto tr0;
		} else
			goto st3;
	} else
		goto st7;
	goto tr19;
tr270:
	{
    SET_CPU_FEATURE(CPUFeature_BMI1);
  }
	goto st112;
tr424:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	switch( (*p) ) {
		case 4u: goto st113;
		case 5u: goto st114;
		case 12u: goto st113;
		case 13u: goto st114;
		case 20u: goto st113;
		case 21u: goto st114;
		case 28u: goto st113;
		case 29u: goto st114;
		case 36u: goto st113;
		case 37u: goto st114;
		case 44u: goto st113;
		case 45u: goto st114;
		case 52u: goto st113;
		case 53u: goto st114;
		case 60u: goto st113;
		case 61u: goto st114;
		case 68u: goto st119;
		case 76u: goto st119;
		case 84u: goto st119;
		case 92u: goto st119;
		case 100u: goto st119;
		case 108u: goto st119;
		case 116u: goto st119;
		case 124u: goto st119;
		case 132u: goto st120;
		case 140u: goto st120;
		case 148u: goto st120;
		case 156u: goto st120;
		case 164u: goto st120;
		case 172u: goto st120;
		case 180u: goto st120;
		case 188u: goto st120;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto st114;
	} else if ( (*p) >= 64u )
		goto st118;
	goto st11;
tr265:
	{
    SET_CPU_FEATURE(CPUFeature_LWP);
  }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	switch( (*p) ) {
		case 5u: goto st114;
		case 13u: goto st114;
		case 21u: goto st114;
		case 29u: goto st114;
		case 37u: goto st114;
		case 45u: goto st114;
		case 53u: goto st114;
		case 61u: goto st114;
		case 69u: goto st114;
		case 77u: goto st114;
		case 85u: goto st114;
		case 93u: goto st114;
		case 101u: goto st114;
		case 109u: goto st114;
		case 117u: goto st114;
		case 125u: goto st114;
		case 133u: goto st114;
		case 141u: goto st114;
		case 149u: goto st114;
		case 157u: goto st114;
		case 165u: goto st114;
		case 173u: goto st114;
		case 181u: goto st114;
		case 189u: goto st114;
		case 197u: goto st114;
		case 205u: goto st114;
		case 213u: goto st114;
		case 221u: goto st114;
		case 229u: goto st114;
		case 237u: goto st114;
		case 245u: goto st114;
		case 253u: goto st114;
	}
	goto st11;
tr266:
	{
    SET_CPU_FEATURE(CPUFeature_LWP);
  }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	goto tr215;
tr267:
	{
    SET_CPU_FEATURE(CPUFeature_LWP);
  }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	goto tr216;
tr268:
	{
    SET_CPU_FEATURE(CPUFeature_LWP);
  }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	goto st118;
tr269:
	{
    SET_CPU_FEATURE(CPUFeature_LWP);
  }
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	goto st114;
tr427:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	switch( (*p) ) {
		case 4u: goto st35;
		case 5u: goto st36;
		case 12u: goto st35;
		case 13u: goto st36;
		case 20u: goto st35;
		case 21u: goto st36;
		case 28u: goto st35;
		case 29u: goto st36;
		case 36u: goto st35;
		case 37u: goto st36;
		case 44u: goto st35;
		case 45u: goto st36;
		case 52u: goto st35;
		case 53u: goto st36;
		case 60u: goto st35;
		case 61u: goto st36;
		case 68u: goto st41;
		case 76u: goto st41;
		case 84u: goto st41;
		case 92u: goto st41;
		case 100u: goto st41;
		case 108u: goto st41;
		case 116u: goto st41;
		case 124u: goto st41;
		case 132u: goto st42;
		case 140u: goto st42;
		case 148u: goto st42;
		case 156u: goto st42;
		case 164u: goto st42;
		case 172u: goto st42;
		case 180u: goto st42;
		case 188u: goto st42;
		case 224u: goto st122;
		case 225u: goto st232;
		case 226u: goto st234;
		case 227u: goto st236;
		case 228u: goto st238;
		case 229u: goto st240;
		case 230u: goto st242;
		case 231u: goto st244;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto st36;
	} else if ( (*p) >= 64u )
		goto st40;
	goto st10;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 224u )
		goto tr225;
	goto tr11;
tr225:
	{ }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st247;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	switch( (*p) ) {
		case 4u: goto tr416;
		case 5u: goto tr417;
		case 12u: goto tr416;
		case 13u: goto tr417;
		case 14u: goto tr19;
		case 15u: goto tr418;
		case 20u: goto tr416;
		case 21u: goto tr417;
		case 28u: goto tr416;
		case 29u: goto tr417;
		case 36u: goto tr416;
		case 37u: goto tr417;
		case 44u: goto tr416;
		case 45u: goto tr417;
		case 46u: goto tr419;
		case 47u: goto tr19;
		case 52u: goto tr416;
		case 53u: goto tr417;
		case 60u: goto tr416;
		case 61u: goto tr417;
		case 62u: goto tr420;
		case 63u: goto tr19;
		case 101u: goto tr422;
		case 102u: goto tr423;
		case 104u: goto tr417;
		case 105u: goto tr424;
		case 106u: goto tr416;
		case 107u: goto tr425;
		case 128u: goto tr425;
		case 129u: goto tr424;
		case 130u: goto tr19;
		case 131u: goto tr427;
		case 141u: goto tr428;
		case 143u: goto tr429;
		case 155u: goto tr430;
		case 168u: goto tr416;
		case 169u: goto tr417;
		case 196u: goto tr433;
		case 197u: goto tr434;
		case 198u: goto tr435;
		case 199u: goto tr436;
		case 200u: goto tr437;
		case 202u: goto tr438;
		case 216u: goto tr440;
		case 217u: goto tr441;
		case 218u: goto tr442;
		case 219u: goto tr443;
		case 220u: goto tr444;
		case 221u: goto tr445;
		case 222u: goto tr446;
		case 223u: goto tr447;
		case 235u: goto tr426;
		case 240u: goto tr449;
		case 242u: goto tr450;
		case 243u: goto tr451;
		case 246u: goto tr452;
		case 247u: goto tr453;
		case 254u: goto tr454;
		case 255u: goto tr456;
	}
	if ( (*p) < 132u ) {
		if ( (*p) < 32u ) {
			if ( (*p) < 8u ) {
				if ( (*p) > 3u ) {
					if ( 6u <= (*p) && (*p) <= 7u )
						goto tr19;
				} else
					goto tr415;
			} else if ( (*p) > 19u ) {
				if ( (*p) < 24u ) {
					if ( 22u <= (*p) && (*p) <= 23u )
						goto tr19;
				} else if ( (*p) > 27u ) {
					if ( 30u <= (*p) && (*p) <= 31u )
						goto tr19;
				} else
					goto tr415;
			} else
				goto tr415;
		} else if ( (*p) > 35u ) {
			if ( (*p) < 54u ) {
				if ( (*p) > 39u ) {
					if ( 40u <= (*p) && (*p) <= 51u )
						goto tr415;
				} else if ( (*p) >= 38u )
					goto tr19;
			} else if ( (*p) > 55u ) {
				if ( (*p) < 96u ) {
					if ( 56u <= (*p) && (*p) <= 59u )
						goto tr415;
				} else if ( (*p) > 111u ) {
					if ( 112u <= (*p) && (*p) <= 127u )
						goto tr426;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr415;
	} else if ( (*p) > 139u ) {
		if ( (*p) < 194u ) {
			if ( (*p) < 160u ) {
				if ( (*p) > 142u ) {
					if ( 154u <= (*p) && (*p) <= 157u )
						goto tr19;
				} else if ( (*p) >= 140u )
					goto tr19;
			} else if ( (*p) > 163u ) {
				if ( (*p) < 184u ) {
					if ( 176u <= (*p) && (*p) <= 183u )
						goto tr416;
				} else if ( (*p) > 191u ) {
					if ( 192u <= (*p) && (*p) <= 193u )
						goto tr432;
				} else
					goto tr417;
			} else
				goto tr431;
		} else if ( (*p) > 195u ) {
			if ( (*p) < 212u ) {
				if ( (*p) > 207u ) {
					if ( 208u <= (*p) && (*p) <= 211u )
						goto tr439;
				} else if ( (*p) >= 204u )
					goto tr19;
			} else if ( (*p) > 231u ) {
				if ( (*p) < 234u ) {
					if ( 232u <= (*p) && (*p) <= 233u )
						goto tr448;
				} else if ( (*p) > 241u ) {
					if ( 250u <= (*p) && (*p) <= 251u )
						goto tr19;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr19;
	} else
		goto tr415;
	goto tr421;
tr429:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 68u: goto st8;
		case 132u: goto st9;
		case 232u: goto st124;
		case 233u: goto st139;
		case 234u: goto st147;
	}
	if ( (*p) < 64u ) {
		if ( (*p) <= 7u )
			goto tr0;
	} else if ( (*p) > 71u ) {
		if ( (*p) > 135u ) {
			if ( 192u <= (*p) && (*p) <= 199u )
				goto tr0;
		} else if ( (*p) >= 128u )
			goto st3;
	} else
		goto st7;
	goto tr19;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	switch( (*p) ) {
		case 64u: goto tr229;
		case 68u: goto tr230;
		case 72u: goto tr229;
		case 76u: goto tr230;
		case 80u: goto tr229;
		case 84u: goto tr230;
		case 88u: goto tr229;
		case 92u: goto tr230;
		case 96u: goto tr229;
		case 100u: goto tr230;
		case 104u: goto tr229;
		case 108u: goto tr230;
		case 112u: goto tr229;
		case 116u: goto tr230;
		case 120u: goto tr231;
		case 124u: goto tr230;
		case 192u: goto tr232;
		case 196u: goto tr230;
		case 200u: goto tr232;
		case 204u: goto tr230;
		case 208u: goto tr232;
		case 212u: goto tr230;
		case 216u: goto tr232;
		case 220u: goto tr230;
		case 224u: goto tr232;
		case 228u: goto tr230;
		case 232u: goto tr232;
		case 236u: goto tr230;
		case 240u: goto tr232;
		case 244u: goto tr230;
		case 248u: goto tr232;
		case 252u: goto tr230;
	}
	goto tr19;
tr229:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	switch( (*p) ) {
		case 166u: goto tr233;
		case 182u: goto tr233;
	}
	if ( (*p) < 158u ) {
		if ( (*p) < 142u ) {
			if ( 133u <= (*p) && (*p) <= 135u )
				goto tr233;
		} else if ( (*p) > 143u ) {
			if ( 149u <= (*p) && (*p) <= 151u )
				goto tr233;
		} else
			goto tr233;
	} else if ( (*p) > 159u ) {
		if ( (*p) < 204u ) {
			if ( 162u <= (*p) && (*p) <= 163u )
				goto tr233;
		} else if ( (*p) > 207u ) {
			if ( 236u <= (*p) && (*p) <= 239u )
				goto tr234;
		} else
			goto tr234;
	} else
		goto tr233;
	goto tr19;
tr233:
	{
    SET_CPU_FEATURE(CPUFeature_XOP);
  }
	goto st126;
tr338:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st126;
tr339:
	{
    SET_CPU_FEATURE(CPUFeature_FMA4);
  }
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	switch( (*p) ) {
		case 4u: goto st128;
		case 5u: goto st129;
		case 12u: goto st128;
		case 13u: goto st129;
		case 20u: goto st128;
		case 21u: goto st129;
		case 28u: goto st128;
		case 29u: goto st129;
		case 36u: goto st128;
		case 37u: goto st129;
		case 44u: goto st128;
		case 45u: goto st129;
		case 52u: goto st128;
		case 53u: goto st129;
		case 60u: goto st128;
		case 61u: goto st129;
		case 68u: goto st134;
		case 76u: goto st134;
		case 84u: goto st134;
		case 92u: goto st134;
		case 100u: goto st134;
		case 108u: goto st134;
		case 116u: goto st134;
		case 124u: goto st134;
		case 132u: goto st135;
		case 140u: goto st135;
		case 148u: goto st135;
		case 156u: goto st135;
		case 164u: goto st135;
		case 172u: goto st135;
		case 180u: goto st135;
		case 188u: goto st135;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto st129;
	} else if ( (*p) >= 64u )
		goto st133;
	goto st127;
tr244:
	{
    SET_DISP_TYPE(DISP32);
    SET_DISP_PTR(p - 3);
  }
	goto st127;
tr245:
	{
    SET_DISP_TYPE(DISP8);
    SET_DISP_PTR(p);
  }
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	switch( (*p) ) {
		case 0u: goto tr0;
		case 16u: goto tr0;
		case 32u: goto tr0;
		case 48u: goto tr0;
		case 64u: goto tr0;
		case 80u: goto tr0;
		case 96u: goto tr0;
		case 112u: goto tr0;
	}
	goto tr19;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	switch( (*p) ) {
		case 5u: goto st129;
		case 13u: goto st129;
		case 21u: goto st129;
		case 29u: goto st129;
		case 37u: goto st129;
		case 45u: goto st129;
		case 53u: goto st129;
		case 61u: goto st129;
		case 69u: goto st129;
		case 77u: goto st129;
		case 85u: goto st129;
		case 93u: goto st129;
		case 101u: goto st129;
		case 109u: goto st129;
		case 117u: goto st129;
		case 125u: goto st129;
		case 133u: goto st129;
		case 141u: goto st129;
		case 149u: goto st129;
		case 157u: goto st129;
		case 165u: goto st129;
		case 173u: goto st129;
		case 181u: goto st129;
		case 189u: goto st129;
		case 197u: goto st129;
		case 205u: goto st129;
		case 213u: goto st129;
		case 221u: goto st129;
		case 229u: goto st129;
		case 237u: goto st129;
		case 245u: goto st129;
		case 253u: goto st129;
	}
	goto st127;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	goto tr244;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	goto tr245;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	goto st133;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	goto st129;
tr230:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 162u )
		goto tr233;
	goto tr19;
tr231:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 166u: goto tr233;
		case 182u: goto tr233;
	}
	if ( (*p) < 158u ) {
		if ( (*p) < 142u ) {
			if ( 133u <= (*p) && (*p) <= 135u )
				goto tr233;
		} else if ( (*p) > 143u ) {
			if ( 149u <= (*p) && (*p) <= 151u )
				goto tr233;
		} else
			goto tr233;
	} else if ( (*p) > 159u ) {
		if ( (*p) < 192u ) {
			if ( 162u <= (*p) && (*p) <= 163u )
				goto tr233;
		} else if ( (*p) > 195u ) {
			if ( (*p) > 207u ) {
				if ( 236u <= (*p) && (*p) <= 239u )
					goto tr234;
			} else if ( (*p) >= 204u )
				goto tr234;
		} else
			goto tr234;
	} else
		goto tr233;
	goto tr19;
tr232:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( 162u <= (*p) && (*p) <= 163u )
		goto tr233;
	goto tr19;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 64u: goto tr246;
		case 72u: goto tr246;
		case 80u: goto tr246;
		case 88u: goto tr246;
		case 96u: goto tr246;
		case 104u: goto tr246;
		case 112u: goto tr246;
		case 120u: goto tr247;
		case 124u: goto tr248;
		case 192u: goto tr249;
		case 200u: goto tr249;
		case 208u: goto tr249;
		case 216u: goto tr249;
		case 224u: goto tr249;
		case 232u: goto tr249;
		case 240u: goto tr249;
		case 248u: goto tr249;
	}
	goto tr19;
tr246:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	switch( (*p) ) {
		case 1u: goto st141;
		case 2u: goto st142;
	}
	if ( 144u <= (*p) && (*p) <= 155u )
		goto tr252;
	goto tr19;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	switch( (*p) ) {
		case 12u: goto tr254;
		case 13u: goto tr255;
		case 20u: goto tr254;
		case 21u: goto tr255;
		case 28u: goto tr254;
		case 29u: goto tr255;
		case 36u: goto tr254;
		case 37u: goto tr255;
		case 44u: goto tr254;
		case 45u: goto tr255;
		case 52u: goto tr254;
		case 53u: goto tr255;
		case 60u: goto tr254;
		case 61u: goto tr255;
		case 76u: goto tr257;
		case 84u: goto tr257;
		case 92u: goto tr257;
		case 100u: goto tr257;
		case 108u: goto tr257;
		case 116u: goto tr257;
		case 124u: goto tr257;
		case 140u: goto tr258;
		case 148u: goto tr258;
		case 156u: goto tr258;
		case 164u: goto tr258;
		case 172u: goto tr258;
		case 180u: goto tr258;
		case 188u: goto tr258;
	}
	if ( (*p) < 72u ) {
		if ( (*p) > 7u ) {
			if ( 64u <= (*p) && (*p) <= 71u )
				goto tr19;
		} else
			goto tr19;
	} else if ( (*p) > 127u ) {
		if ( (*p) < 136u ) {
			if ( 128u <= (*p) && (*p) <= 135u )
				goto tr19;
		} else if ( (*p) > 191u ) {
			if ( 192u <= (*p) && (*p) <= 199u )
				goto tr19;
		} else
			goto tr255;
	} else
		goto tr256;
	goto tr253;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	switch( (*p) ) {
		case 12u: goto tr254;
		case 13u: goto tr255;
		case 52u: goto tr254;
		case 53u: goto tr255;
		case 76u: goto tr257;
		case 116u: goto tr257;
		case 140u: goto tr258;
		case 180u: goto tr258;
	}
	if ( (*p) < 112u ) {
		if ( (*p) < 48u ) {
			if ( 8u <= (*p) && (*p) <= 15u )
				goto tr253;
		} else if ( (*p) > 55u ) {
			if ( 72u <= (*p) && (*p) <= 79u )
				goto tr256;
		} else
			goto tr253;
	} else if ( (*p) > 119u ) {
		if ( (*p) < 176u ) {
			if ( 136u <= (*p) && (*p) <= 143u )
				goto tr255;
		} else if ( (*p) > 183u ) {
			if ( (*p) > 207u ) {
				if ( 240u <= (*p) && (*p) <= 247u )
					goto tr253;
			} else if ( (*p) >= 200u )
				goto tr253;
		} else
			goto tr255;
	} else
		goto tr256;
	goto tr19;
tr247:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	switch( (*p) ) {
		case 1u: goto st141;
		case 2u: goto st142;
		case 18u: goto st144;
		case 203u: goto tr252;
		case 219u: goto tr252;
	}
	if ( (*p) < 198u ) {
		if ( (*p) < 144u ) {
			if ( 128u <= (*p) && (*p) <= 131u )
				goto tr252;
		} else if ( (*p) > 155u ) {
			if ( 193u <= (*p) && (*p) <= 195u )
				goto tr252;
		} else
			goto tr252;
	} else if ( (*p) > 199u ) {
		if ( (*p) < 214u ) {
			if ( 209u <= (*p) && (*p) <= 211u )
				goto tr252;
		} else if ( (*p) > 215u ) {
			if ( 225u <= (*p) && (*p) <= 227u )
				goto tr252;
		} else
			goto tr252;
	} else
		goto tr252;
	goto tr19;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( 192u <= (*p) && (*p) <= 207u )
		goto tr260;
	goto tr19;
tr248:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( 128u <= (*p) && (*p) <= 129u )
		goto tr252;
	goto tr19;
tr249:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( 144u <= (*p) && (*p) <= 155u )
		goto tr252;
	goto tr19;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	switch( (*p) ) {
		case 64u: goto tr261;
		case 72u: goto tr261;
		case 80u: goto tr261;
		case 88u: goto tr261;
		case 96u: goto tr261;
		case 104u: goto tr261;
		case 112u: goto tr261;
		case 120u: goto tr262;
	}
	goto tr19;
tr261:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	if ( (*p) == 18u )
		goto st149;
	goto tr19;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	switch( (*p) ) {
		case 4u: goto tr265;
		case 5u: goto tr266;
		case 12u: goto tr265;
		case 13u: goto tr266;
		case 68u: goto tr268;
		case 76u: goto tr268;
		case 132u: goto tr269;
		case 140u: goto tr269;
	}
	if ( (*p) < 64u ) {
		if ( (*p) <= 15u )
			goto tr264;
	} else if ( (*p) > 79u ) {
		if ( (*p) > 143u ) {
			if ( 192u <= (*p) && (*p) <= 207u )
				goto tr264;
		} else if ( (*p) >= 128u )
			goto tr266;
	} else
		goto tr267;
	goto tr19;
tr262:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	switch( (*p) ) {
		case 16u: goto tr270;
		case 18u: goto st149;
	}
	goto tr19;
tr433:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	switch( (*p) ) {
		case 225u: goto st152;
		case 226u: goto st174;
		case 227u: goto st183;
	}
	goto tr19;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	switch( (*p) ) {
		case 65u: goto tr275;
		case 66u: goto tr276;
		case 67u: goto tr277;
		case 68u: goto tr278;
		case 69u: goto tr279;
		case 70u: goto tr280;
		case 71u: goto tr281;
		case 73u: goto tr275;
		case 74u: goto tr276;
		case 75u: goto tr277;
		case 76u: goto tr278;
		case 77u: goto tr279;
		case 78u: goto tr280;
		case 79u: goto tr281;
		case 81u: goto tr275;
		case 82u: goto tr276;
		case 83u: goto tr277;
		case 84u: goto tr278;
		case 85u: goto tr279;
		case 86u: goto tr280;
		case 87u: goto tr281;
		case 89u: goto tr275;
		case 90u: goto tr276;
		case 91u: goto tr277;
		case 92u: goto tr278;
		case 93u: goto tr279;
		case 94u: goto tr280;
		case 95u: goto tr281;
		case 97u: goto tr275;
		case 98u: goto tr276;
		case 99u: goto tr277;
		case 100u: goto tr278;
		case 101u: goto tr279;
		case 102u: goto tr280;
		case 103u: goto tr281;
		case 105u: goto tr275;
		case 106u: goto tr276;
		case 107u: goto tr277;
		case 108u: goto tr278;
		case 109u: goto tr279;
		case 110u: goto tr280;
		case 111u: goto tr281;
		case 113u: goto tr275;
		case 114u: goto tr276;
		case 115u: goto tr277;
		case 116u: goto tr278;
		case 117u: goto tr279;
		case 118u: goto tr280;
		case 119u: goto tr281;
		case 120u: goto tr282;
		case 121u: goto tr283;
		case 122u: goto tr284;
		case 123u: goto tr285;
		case 124u: goto tr286;
		case 125u: goto tr287;
		case 126u: goto tr288;
		case 127u: goto tr289;
	}
	if ( 64u <= (*p) && (*p) <= 112u )
		goto tr274;
	goto tr19;
tr274:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st153;
tr355:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 18u: goto st154;
		case 22u: goto st154;
		case 23u: goto tr292;
		case 81u: goto tr291;
		case 194u: goto tr293;
		case 198u: goto tr293;
	}
	if ( (*p) < 46u ) {
		if ( 20u <= (*p) && (*p) <= 21u )
			goto tr291;
	} else if ( (*p) > 47u ) {
		if ( (*p) > 89u ) {
			if ( 92u <= (*p) && (*p) <= 95u )
				goto tr291;
		} else if ( (*p) >= 84u )
			goto tr291;
	} else
		goto tr291;
	goto tr19;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	switch( (*p) ) {
		case 4u: goto tr295;
		case 5u: goto tr296;
		case 12u: goto tr295;
		case 13u: goto tr296;
		case 20u: goto tr295;
		case 21u: goto tr296;
		case 28u: goto tr295;
		case 29u: goto tr296;
		case 36u: goto tr295;
		case 37u: goto tr296;
		case 44u: goto tr295;
		case 45u: goto tr296;
		case 52u: goto tr295;
		case 53u: goto tr296;
		case 60u: goto tr295;
		case 61u: goto tr296;
		case 68u: goto tr298;
		case 76u: goto tr298;
		case 84u: goto tr298;
		case 92u: goto tr298;
		case 100u: goto tr298;
		case 108u: goto tr298;
		case 116u: goto tr298;
		case 124u: goto tr298;
		case 132u: goto tr299;
		case 140u: goto tr299;
		case 148u: goto tr299;
		case 156u: goto tr299;
		case 164u: goto tr299;
		case 172u: goto tr299;
		case 180u: goto tr299;
		case 188u: goto tr299;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto tr296;
	} else if ( (*p) >= 64u )
		goto tr297;
	goto tr294;
tr275:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st155;
tr356:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st155;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 18u: goto tr292;
		case 81u: goto tr291;
		case 115u: goto st157;
		case 194u: goto tr293;
		case 198u: goto tr293;
	}
	if ( (*p) < 116u ) {
		if ( (*p) < 46u ) {
			if ( (*p) > 21u ) {
				if ( 22u <= (*p) && (*p) <= 23u )
					goto tr292;
			} else if ( (*p) >= 20u )
				goto tr291;
		} else if ( (*p) > 47u ) {
			if ( (*p) < 92u ) {
				if ( 84u <= (*p) && (*p) <= 89u )
					goto tr291;
			} else if ( (*p) > 109u ) {
				if ( 113u <= (*p) && (*p) <= 114u )
					goto st156;
			} else
				goto tr291;
		} else
			goto tr291;
	} else if ( (*p) > 118u ) {
		if ( (*p) < 216u ) {
			if ( (*p) > 125u ) {
				if ( 208u <= (*p) && (*p) <= 213u )
					goto tr291;
			} else if ( (*p) >= 124u )
				goto tr291;
		} else if ( (*p) > 229u ) {
			if ( (*p) < 241u ) {
				if ( 232u <= (*p) && (*p) <= 239u )
					goto tr291;
			} else if ( (*p) > 246u ) {
				if ( 248u <= (*p) && (*p) <= 254u )
					goto tr291;
			} else
				goto tr291;
		} else
			goto tr291;
	} else
		goto tr291;
	goto tr19;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	if ( (*p) < 224u ) {
		if ( 208u <= (*p) && (*p) <= 215u )
			goto tr302;
	} else if ( (*p) > 231u ) {
		if ( 240u <= (*p) && (*p) <= 247u )
			goto tr302;
	} else
		goto tr302;
	goto tr19;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	if ( (*p) > 223u ) {
		if ( 240u <= (*p) )
			goto tr302;
	} else if ( (*p) >= 208u )
		goto tr302;
	goto tr19;
tr276:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	switch( (*p) ) {
		case 42u: goto tr291;
		case 81u: goto tr291;
		case 83u: goto tr291;
		case 194u: goto tr293;
	}
	if ( (*p) > 90u ) {
		if ( 92u <= (*p) && (*p) <= 95u )
			goto tr291;
	} else if ( (*p) >= 88u )
		goto tr291;
	goto tr19;
tr277:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 42u: goto tr291;
		case 81u: goto tr291;
		case 194u: goto tr293;
		case 208u: goto tr291;
	}
	if ( (*p) < 92u ) {
		if ( 88u <= (*p) && (*p) <= 90u )
			goto tr291;
	} else if ( (*p) > 95u ) {
		if ( 124u <= (*p) && (*p) <= 125u )
			goto tr291;
	} else
		goto tr291;
	goto tr19;
tr278:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st160;
tr359:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	switch( (*p) ) {
		case 81u: goto tr291;
		case 194u: goto tr293;
		case 198u: goto tr293;
	}
	if ( (*p) < 84u ) {
		if ( 20u <= (*p) && (*p) <= 21u )
			goto tr291;
	} else if ( (*p) > 89u ) {
		if ( 92u <= (*p) && (*p) <= 95u )
			goto tr291;
	} else
		goto tr291;
	goto tr19;
tr279:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st161;
tr360:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	switch( (*p) ) {
		case 81u: goto tr291;
		case 194u: goto tr293;
		case 198u: goto tr293;
		case 208u: goto tr291;
	}
	if ( (*p) < 84u ) {
		if ( 20u <= (*p) && (*p) <= 21u )
			goto tr291;
	} else if ( (*p) > 89u ) {
		if ( (*p) > 95u ) {
			if ( 124u <= (*p) && (*p) <= 125u )
				goto tr291;
		} else if ( (*p) >= 92u )
			goto tr291;
	} else
		goto tr291;
	goto tr19;
tr280:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st162;
tr361:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	if ( 16u <= (*p) && (*p) <= 17u )
		goto tr303;
	goto tr19;
tr281:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st163;
tr362:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	if ( (*p) == 208u )
		goto tr291;
	if ( (*p) > 17u ) {
		if ( 124u <= (*p) && (*p) <= 125u )
			goto tr291;
	} else if ( (*p) >= 16u )
		goto tr303;
	goto tr19;
tr282:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st164;
tr363:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 18u: goto st154;
		case 19u: goto tr292;
		case 22u: goto st154;
		case 23u: goto tr292;
		case 43u: goto tr292;
		case 80u: goto tr303;
		case 119u: goto tr294;
		case 174u: goto st165;
		case 194u: goto tr293;
		case 198u: goto tr293;
	}
	if ( (*p) < 40u ) {
		if ( 16u <= (*p) && (*p) <= 21u )
			goto tr291;
	} else if ( (*p) > 41u ) {
		if ( (*p) > 47u ) {
			if ( 81u <= (*p) && (*p) <= 95u )
				goto tr291;
		} else if ( (*p) >= 46u )
			goto tr291;
	} else
		goto tr291;
	goto tr19;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 20u: goto tr295;
		case 21u: goto tr296;
		case 28u: goto tr295;
		case 29u: goto tr296;
		case 84u: goto tr298;
		case 92u: goto tr298;
		case 148u: goto tr299;
		case 156u: goto tr299;
	}
	if ( (*p) < 80u ) {
		if ( 16u <= (*p) && (*p) <= 31u )
			goto tr294;
	} else if ( (*p) > 95u ) {
		if ( 144u <= (*p) && (*p) <= 159u )
			goto tr296;
	} else
		goto tr297;
	goto tr19;
tr283:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st166;
tr364:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	switch( (*p) ) {
		case 43u: goto tr292;
		case 80u: goto tr303;
		case 81u: goto tr291;
		case 112u: goto tr293;
		case 115u: goto st157;
		case 127u: goto tr291;
		case 194u: goto tr293;
		case 196u: goto st167;
		case 197u: goto tr306;
		case 198u: goto tr293;
		case 215u: goto tr303;
		case 231u: goto tr292;
		case 247u: goto tr303;
	}
	if ( (*p) < 84u ) {
		if ( (*p) < 20u ) {
			if ( (*p) > 17u ) {
				if ( 18u <= (*p) && (*p) <= 19u )
					goto tr292;
			} else if ( (*p) >= 16u )
				goto tr291;
		} else if ( (*p) > 21u ) {
			if ( (*p) < 40u ) {
				if ( 22u <= (*p) && (*p) <= 23u )
					goto tr292;
			} else if ( (*p) > 41u ) {
				if ( 46u <= (*p) && (*p) <= 47u )
					goto tr291;
			} else
				goto tr291;
		} else
			goto tr291;
	} else if ( (*p) > 111u ) {
		if ( (*p) < 124u ) {
			if ( (*p) > 114u ) {
				if ( 116u <= (*p) && (*p) <= 118u )
					goto tr291;
			} else if ( (*p) >= 113u )
				goto st156;
		} else if ( (*p) > 125u ) {
			if ( (*p) < 216u ) {
				if ( 208u <= (*p) && (*p) <= 213u )
					goto tr291;
			} else if ( (*p) > 239u ) {
				if ( 241u <= (*p) && (*p) <= 254u )
					goto tr291;
			} else
				goto tr291;
		} else
			goto tr291;
	} else
		goto tr291;
	goto tr19;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	switch( (*p) ) {
		case 4u: goto tr307;
		case 5u: goto tr308;
		case 12u: goto tr307;
		case 13u: goto tr308;
		case 20u: goto tr307;
		case 21u: goto tr308;
		case 28u: goto tr307;
		case 29u: goto tr308;
		case 36u: goto tr307;
		case 37u: goto tr308;
		case 44u: goto tr307;
		case 45u: goto tr308;
		case 52u: goto tr307;
		case 53u: goto tr308;
		case 60u: goto tr307;
		case 61u: goto tr308;
		case 68u: goto tr310;
		case 76u: goto tr310;
		case 84u: goto tr310;
		case 92u: goto tr310;
		case 100u: goto tr310;
		case 108u: goto tr310;
		case 116u: goto tr310;
		case 124u: goto tr310;
		case 132u: goto tr311;
		case 140u: goto tr311;
		case 148u: goto tr311;
		case 156u: goto tr311;
		case 164u: goto tr311;
		case 172u: goto tr311;
		case 180u: goto tr311;
		case 188u: goto tr311;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto tr308;
	} else if ( (*p) >= 64u )
		goto tr309;
	goto tr302;
tr284:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	switch( (*p) ) {
		case 18u: goto tr291;
		case 22u: goto tr291;
		case 42u: goto tr291;
		case 111u: goto tr291;
		case 112u: goto tr293;
		case 194u: goto tr293;
		case 230u: goto tr291;
	}
	if ( (*p) < 81u ) {
		if ( (*p) > 17u ) {
			if ( 44u <= (*p) && (*p) <= 45u )
				goto tr291;
		} else if ( (*p) >= 16u )
			goto tr292;
	} else if ( (*p) > 83u ) {
		if ( (*p) > 95u ) {
			if ( 126u <= (*p) && (*p) <= 127u )
				goto tr291;
		} else if ( (*p) >= 88u )
			goto tr291;
	} else
		goto tr291;
	goto tr19;
tr285:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	switch( (*p) ) {
		case 18u: goto tr291;
		case 42u: goto tr291;
		case 81u: goto tr291;
		case 112u: goto tr293;
		case 194u: goto tr293;
		case 208u: goto tr291;
		case 230u: goto tr291;
		case 240u: goto tr292;
	}
	if ( (*p) < 88u ) {
		if ( (*p) > 17u ) {
			if ( 44u <= (*p) && (*p) <= 45u )
				goto tr291;
		} else if ( (*p) >= 16u )
			goto tr292;
	} else if ( (*p) > 90u ) {
		if ( (*p) > 95u ) {
			if ( 124u <= (*p) && (*p) <= 125u )
				goto tr291;
		} else if ( (*p) >= 92u )
			goto tr291;
	} else
		goto tr291;
	goto tr19;
tr286:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st170;
tr367:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	switch( (*p) ) {
		case 43u: goto tr292;
		case 80u: goto tr303;
		case 119u: goto tr294;
		case 194u: goto tr293;
		case 198u: goto tr293;
	}
	if ( (*p) < 20u ) {
		if ( 16u <= (*p) && (*p) <= 17u )
			goto tr291;
	} else if ( (*p) > 21u ) {
		if ( (*p) > 41u ) {
			if ( 81u <= (*p) && (*p) <= 95u )
				goto tr291;
		} else if ( (*p) >= 40u )
			goto tr291;
	} else
		goto tr291;
	goto tr19;
tr287:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st171;
tr368:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	switch( (*p) ) {
		case 43u: goto tr292;
		case 80u: goto tr303;
		case 81u: goto tr291;
		case 194u: goto tr293;
		case 198u: goto tr293;
		case 208u: goto tr291;
		case 214u: goto tr291;
		case 230u: goto tr291;
		case 231u: goto tr292;
	}
	if ( (*p) < 40u ) {
		if ( (*p) > 17u ) {
			if ( 20u <= (*p) && (*p) <= 21u )
				goto tr291;
		} else if ( (*p) >= 16u )
			goto tr291;
	} else if ( (*p) > 41u ) {
		if ( (*p) > 95u ) {
			if ( 124u <= (*p) && (*p) <= 127u )
				goto tr291;
		} else if ( (*p) >= 84u )
			goto tr291;
	} else
		goto tr291;
	goto tr19;
tr288:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st172;
tr369:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 18u: goto tr291;
		case 22u: goto tr291;
		case 91u: goto tr291;
		case 127u: goto tr291;
		case 230u: goto tr291;
	}
	if ( 16u <= (*p) && (*p) <= 17u )
		goto tr303;
	goto tr19;
tr289:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st173;
tr370:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	switch( (*p) ) {
		case 18u: goto tr291;
		case 208u: goto tr291;
		case 230u: goto tr291;
		case 240u: goto tr292;
	}
	if ( (*p) > 17u ) {
		if ( 124u <= (*p) && (*p) <= 125u )
			goto tr291;
	} else if ( (*p) >= 16u )
		goto tr303;
	goto tr19;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	switch( (*p) ) {
		case 64u: goto tr312;
		case 65u: goto tr313;
		case 69u: goto tr314;
		case 72u: goto tr312;
		case 73u: goto tr313;
		case 77u: goto tr314;
		case 80u: goto tr312;
		case 81u: goto tr313;
		case 85u: goto tr314;
		case 88u: goto tr312;
		case 89u: goto tr313;
		case 93u: goto tr314;
		case 96u: goto tr312;
		case 97u: goto tr313;
		case 101u: goto tr314;
		case 104u: goto tr312;
		case 105u: goto tr313;
		case 109u: goto tr314;
		case 112u: goto tr312;
		case 113u: goto tr313;
		case 117u: goto tr314;
		case 120u: goto tr312;
		case 121u: goto tr315;
		case 125u: goto tr316;
		case 193u: goto tr317;
		case 197u: goto tr318;
		case 201u: goto tr317;
		case 205u: goto tr318;
		case 209u: goto tr317;
		case 213u: goto tr318;
		case 217u: goto tr317;
		case 221u: goto tr318;
		case 225u: goto tr317;
		case 229u: goto tr318;
		case 233u: goto tr317;
		case 237u: goto tr318;
		case 241u: goto tr317;
		case 245u: goto tr318;
		case 249u: goto tr317;
		case 253u: goto tr318;
	}
	goto tr19;
tr312:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	switch( (*p) ) {
		case 242u: goto tr319;
		case 243u: goto st176;
		case 247u: goto tr319;
	}
	goto tr19;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	switch( (*p) ) {
		case 12u: goto tr322;
		case 13u: goto tr323;
		case 20u: goto tr322;
		case 21u: goto tr323;
		case 28u: goto tr322;
		case 29u: goto tr323;
		case 76u: goto tr325;
		case 84u: goto tr325;
		case 92u: goto tr325;
		case 140u: goto tr326;
		case 148u: goto tr326;
		case 156u: goto tr326;
	}
	if ( (*p) < 72u ) {
		if ( 8u <= (*p) && (*p) <= 31u )
			goto tr321;
	} else if ( (*p) > 95u ) {
		if ( (*p) > 159u ) {
			if ( 200u <= (*p) && (*p) <= 223u )
				goto tr321;
		} else if ( (*p) >= 136u )
			goto tr323;
	} else
		goto tr324;
	goto tr19;
tr313:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	if ( (*p) == 43u )
		goto tr291;
	if ( (*p) < 55u ) {
		if ( (*p) < 40u ) {
			if ( (*p) <= 13u )
				goto tr291;
		} else if ( (*p) > 41u ) {
			if ( 44u <= (*p) && (*p) <= 47u )
				goto tr292;
		} else
			goto tr291;
	} else if ( (*p) > 64u ) {
		if ( (*p) < 166u ) {
			if ( 150u <= (*p) && (*p) <= 159u )
				goto tr327;
		} else if ( (*p) > 175u ) {
			if ( (*p) > 191u ) {
				if ( 219u <= (*p) && (*p) <= 223u )
					goto tr328;
			} else if ( (*p) >= 182u )
				goto tr327;
		} else
			goto tr327;
	} else
		goto tr291;
	goto tr19;
tr314:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 154u: goto tr327;
		case 156u: goto tr327;
		case 158u: goto tr327;
		case 170u: goto tr327;
		case 172u: goto tr327;
		case 174u: goto tr327;
		case 186u: goto tr327;
		case 188u: goto tr327;
		case 190u: goto tr327;
	}
	if ( (*p) < 150u ) {
		if ( (*p) > 13u ) {
			if ( 44u <= (*p) && (*p) <= 47u )
				goto tr292;
		} else if ( (*p) >= 12u )
			goto tr291;
	} else if ( (*p) > 152u ) {
		if ( (*p) > 168u ) {
			if ( 182u <= (*p) && (*p) <= 184u )
				goto tr327;
		} else if ( (*p) >= 166u )
			goto tr327;
	} else
		goto tr327;
	goto tr19;
tr315:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st179;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	switch( (*p) ) {
		case 19u: goto tr329;
		case 23u: goto tr291;
		case 24u: goto tr292;
		case 42u: goto tr292;
	}
	if ( (*p) < 48u ) {
		if ( (*p) < 32u ) {
			if ( (*p) > 15u ) {
				if ( 28u <= (*p) && (*p) <= 30u )
					goto tr291;
			} else
				goto tr291;
		} else if ( (*p) > 37u ) {
			if ( (*p) > 43u ) {
				if ( 44u <= (*p) && (*p) <= 47u )
					goto tr292;
			} else if ( (*p) >= 40u )
				goto tr291;
		} else
			goto tr291;
	} else if ( (*p) > 53u ) {
		if ( (*p) < 166u ) {
			if ( (*p) > 65u ) {
				if ( 150u <= (*p) && (*p) <= 159u )
					goto tr327;
			} else if ( (*p) >= 55u )
				goto tr291;
		} else if ( (*p) > 175u ) {
			if ( (*p) > 191u ) {
				if ( 219u <= (*p) && (*p) <= 223u )
					goto tr328;
			} else if ( (*p) >= 182u )
				goto tr327;
		} else
			goto tr327;
	} else
		goto tr291;
	goto tr19;
tr316:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	switch( (*p) ) {
		case 19u: goto tr329;
		case 23u: goto tr291;
		case 154u: goto tr327;
		case 156u: goto tr327;
		case 158u: goto tr327;
		case 170u: goto tr327;
		case 172u: goto tr327;
		case 174u: goto tr327;
		case 186u: goto tr327;
		case 188u: goto tr327;
		case 190u: goto tr327;
	}
	if ( (*p) < 44u ) {
		if ( (*p) > 15u ) {
			if ( 24u <= (*p) && (*p) <= 26u )
				goto tr292;
		} else if ( (*p) >= 12u )
			goto tr291;
	} else if ( (*p) > 47u ) {
		if ( (*p) < 166u ) {
			if ( 150u <= (*p) && (*p) <= 152u )
				goto tr327;
		} else if ( (*p) > 168u ) {
			if ( 182u <= (*p) && (*p) <= 184u )
				goto tr327;
		} else
			goto tr327;
	} else
		goto tr292;
	goto tr19;
tr317:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	if ( (*p) < 166u ) {
		if ( 150u <= (*p) && (*p) <= 159u )
			goto tr327;
	} else if ( (*p) > 175u ) {
		if ( 182u <= (*p) && (*p) <= 191u )
			goto tr327;
	} else
		goto tr327;
	goto tr19;
tr318:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	switch( (*p) ) {
		case 154u: goto tr327;
		case 156u: goto tr327;
		case 158u: goto tr327;
		case 170u: goto tr327;
		case 172u: goto tr327;
		case 174u: goto tr327;
		case 186u: goto tr327;
		case 188u: goto tr327;
		case 190u: goto tr327;
	}
	if ( (*p) < 166u ) {
		if ( 150u <= (*p) && (*p) <= 152u )
			goto tr327;
	} else if ( (*p) > 168u ) {
		if ( 182u <= (*p) && (*p) <= 184u )
			goto tr327;
	} else
		goto tr327;
	goto tr19;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	switch( (*p) ) {
		case 65u: goto tr330;
		case 69u: goto tr331;
		case 73u: goto tr330;
		case 77u: goto tr331;
		case 81u: goto tr330;
		case 85u: goto tr331;
		case 89u: goto tr330;
		case 93u: goto tr331;
		case 97u: goto tr330;
		case 101u: goto tr331;
		case 105u: goto tr330;
		case 109u: goto tr331;
		case 113u: goto tr330;
		case 117u: goto tr331;
		case 121u: goto tr332;
		case 125u: goto tr333;
		case 193u: goto tr334;
		case 197u: goto tr335;
		case 201u: goto tr334;
		case 205u: goto tr335;
		case 209u: goto tr334;
		case 213u: goto tr335;
		case 217u: goto tr334;
		case 221u: goto tr335;
		case 225u: goto tr334;
		case 229u: goto tr335;
		case 233u: goto tr334;
		case 237u: goto tr335;
		case 241u: goto tr334;
		case 245u: goto tr335;
		case 249u: goto tr334;
		case 253u: goto tr335;
	}
	goto tr19;
tr330:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	switch( (*p) ) {
		case 33u: goto tr293;
		case 68u: goto tr336;
		case 223u: goto tr340;
	}
	if ( (*p) < 74u ) {
		if ( (*p) < 64u ) {
			if ( 8u <= (*p) && (*p) <= 15u )
				goto tr293;
		} else if ( (*p) > 66u ) {
			if ( 72u <= (*p) && (*p) <= 73u )
				goto tr337;
		} else
			goto tr293;
	} else if ( (*p) > 76u ) {
		if ( (*p) < 104u ) {
			if ( 92u <= (*p) && (*p) <= 95u )
				goto tr339;
		} else if ( (*p) > 111u ) {
			if ( 120u <= (*p) && (*p) <= 127u )
				goto tr339;
		} else
			goto tr339;
	} else
		goto tr338;
	goto tr19;
tr337:
	{
    SET_CPU_FEATURE(CPUFeature_XOP);
  }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	switch( (*p) ) {
		case 4u: goto st187;
		case 5u: goto st188;
		case 12u: goto st187;
		case 13u: goto st188;
		case 20u: goto st187;
		case 21u: goto st188;
		case 28u: goto st187;
		case 29u: goto st188;
		case 36u: goto st187;
		case 37u: goto st188;
		case 44u: goto st187;
		case 45u: goto st188;
		case 52u: goto st187;
		case 53u: goto st188;
		case 60u: goto st187;
		case 61u: goto st188;
		case 68u: goto st193;
		case 76u: goto st193;
		case 84u: goto st193;
		case 92u: goto st193;
		case 100u: goto st193;
		case 108u: goto st193;
		case 116u: goto st193;
		case 124u: goto st193;
		case 132u: goto st194;
		case 140u: goto st194;
		case 148u: goto st194;
		case 156u: goto st194;
		case 164u: goto st194;
		case 172u: goto st194;
		case 180u: goto st194;
		case 188u: goto st194;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto st188;
	} else if ( (*p) >= 64u )
		goto st192;
	goto st186;
tr351:
	{
    SET_DISP_TYPE(DISP32);
    SET_DISP_PTR(p - 3);
  }
	goto st186;
tr352:
	{
    SET_DISP_TYPE(DISP8);
    SET_DISP_PTR(p);
  }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	if ( (*p) < 48u ) {
		if ( (*p) < 16u ) {
			if ( (*p) <= 3u )
				goto tr347;
		} else if ( (*p) > 19u ) {
			if ( 32u <= (*p) && (*p) <= 35u )
				goto tr347;
		} else
			goto tr347;
	} else if ( (*p) > 51u ) {
		if ( (*p) < 80u ) {
			if ( 64u <= (*p) && (*p) <= 67u )
				goto tr347;
		} else if ( (*p) > 83u ) {
			if ( (*p) > 99u ) {
				if ( 112u <= (*p) && (*p) <= 115u )
					goto tr347;
			} else if ( (*p) >= 96u )
				goto tr347;
		} else
			goto tr347;
	} else
		goto tr347;
	goto tr19;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	switch( (*p) ) {
		case 5u: goto st188;
		case 13u: goto st188;
		case 21u: goto st188;
		case 29u: goto st188;
		case 37u: goto st188;
		case 45u: goto st188;
		case 53u: goto st188;
		case 61u: goto st188;
		case 69u: goto st188;
		case 77u: goto st188;
		case 85u: goto st188;
		case 93u: goto st188;
		case 101u: goto st188;
		case 109u: goto st188;
		case 117u: goto st188;
		case 125u: goto st188;
		case 133u: goto st188;
		case 141u: goto st188;
		case 149u: goto st188;
		case 157u: goto st188;
		case 165u: goto st188;
		case 173u: goto st188;
		case 181u: goto st188;
		case 189u: goto st188;
		case 197u: goto st188;
		case 205u: goto st188;
		case 213u: goto st188;
		case 221u: goto st188;
		case 229u: goto st188;
		case 237u: goto st188;
		case 245u: goto st188;
		case 253u: goto st188;
	}
	goto st186;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	goto tr351;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	goto tr352;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	goto st192;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	goto st188;
tr331:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	switch( (*p) ) {
		case 6u: goto tr293;
		case 64u: goto tr293;
	}
	if ( (*p) < 92u ) {
		if ( (*p) < 12u ) {
			if ( 8u <= (*p) && (*p) <= 9u )
				goto tr293;
		} else if ( (*p) > 13u ) {
			if ( (*p) > 73u ) {
				if ( 74u <= (*p) && (*p) <= 75u )
					goto tr338;
			} else if ( (*p) >= 72u )
				goto tr337;
		} else
			goto tr293;
	} else if ( (*p) > 95u ) {
		if ( (*p) < 108u ) {
			if ( 104u <= (*p) && (*p) <= 105u )
				goto tr339;
		} else if ( (*p) > 109u ) {
			if ( (*p) > 121u ) {
				if ( 124u <= (*p) && (*p) <= 125u )
					goto tr339;
			} else if ( (*p) >= 120u )
				goto tr339;
		} else
			goto tr339;
	} else
		goto tr339;
	goto tr19;
tr332:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	switch( (*p) ) {
		case 22u: goto tr293;
		case 23u: goto tr353;
		case 29u: goto tr354;
		case 32u: goto st167;
		case 68u: goto tr336;
		case 223u: goto tr340;
	}
	if ( (*p) < 72u ) {
		if ( (*p) < 20u ) {
			if ( (*p) > 5u ) {
				if ( 8u <= (*p) && (*p) <= 15u )
					goto tr293;
			} else if ( (*p) >= 4u )
				goto tr293;
		} else if ( (*p) > 21u ) {
			if ( (*p) > 34u ) {
				if ( 64u <= (*p) && (*p) <= 66u )
					goto tr293;
			} else if ( (*p) >= 33u )
				goto tr293;
		} else
			goto st167;
	} else if ( (*p) > 73u ) {
		if ( (*p) < 96u ) {
			if ( (*p) > 76u ) {
				if ( 92u <= (*p) && (*p) <= 95u )
					goto tr339;
			} else if ( (*p) >= 74u )
				goto tr338;
		} else if ( (*p) > 99u ) {
			if ( (*p) > 111u ) {
				if ( 120u <= (*p) && (*p) <= 127u )
					goto tr339;
			} else if ( (*p) >= 104u )
				goto tr339;
		} else
			goto tr293;
	} else
		goto tr337;
	goto tr19;
tr353:
	{
    SET_CPU_FEATURE(CPUFeature_AVX);
  }
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	switch( (*p) ) {
		case 4u: goto st35;
		case 12u: goto st35;
		case 20u: goto st35;
		case 28u: goto st35;
		case 36u: goto st35;
		case 44u: goto st35;
		case 52u: goto st35;
		case 60u: goto st35;
		case 68u: goto st41;
		case 76u: goto st41;
		case 84u: goto st41;
		case 92u: goto st41;
		case 100u: goto st41;
		case 108u: goto st41;
		case 116u: goto st41;
		case 124u: goto st41;
		case 132u: goto st42;
		case 140u: goto st42;
		case 148u: goto st42;
		case 156u: goto st42;
		case 164u: goto st42;
		case 172u: goto st42;
		case 180u: goto st42;
		case 188u: goto st42;
	}
	if ( (*p) < 38u ) {
		if ( (*p) < 14u ) {
			if ( (*p) > 3u ) {
				if ( 6u <= (*p) && (*p) <= 11u )
					goto st10;
			} else
				goto st10;
		} else if ( (*p) > 19u ) {
			if ( (*p) > 27u ) {
				if ( 30u <= (*p) && (*p) <= 35u )
					goto st10;
			} else if ( (*p) >= 22u )
				goto st10;
		} else
			goto st10;
	} else if ( (*p) > 43u ) {
		if ( (*p) < 62u ) {
			if ( (*p) > 51u ) {
				if ( 54u <= (*p) && (*p) <= 59u )
					goto st10;
			} else if ( (*p) >= 46u )
				goto st10;
		} else if ( (*p) > 63u ) {
			if ( (*p) > 127u ) {
				if ( 192u <= (*p) )
					goto tr19;
			} else if ( (*p) >= 64u )
				goto st40;
		} else
			goto st10;
	} else
		goto st10;
	goto st36;
tr333:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	switch( (*p) ) {
		case 29u: goto tr354;
		case 64u: goto tr293;
	}
	if ( (*p) < 74u ) {
		if ( (*p) < 12u ) {
			if ( (*p) > 6u ) {
				if ( 8u <= (*p) && (*p) <= 9u )
					goto tr293;
			} else if ( (*p) >= 4u )
				goto tr293;
		} else if ( (*p) > 13u ) {
			if ( (*p) > 25u ) {
				if ( 72u <= (*p) && (*p) <= 73u )
					goto tr337;
			} else if ( (*p) >= 24u )
				goto tr293;
		} else
			goto tr293;
	} else if ( (*p) > 75u ) {
		if ( (*p) < 108u ) {
			if ( (*p) > 95u ) {
				if ( 104u <= (*p) && (*p) <= 105u )
					goto tr339;
			} else if ( (*p) >= 92u )
				goto tr339;
		} else if ( (*p) > 109u ) {
			if ( (*p) > 121u ) {
				if ( 124u <= (*p) && (*p) <= 125u )
					goto tr339;
			} else if ( (*p) >= 120u )
				goto tr339;
		} else
			goto tr339;
	} else
		goto tr338;
	goto tr19;
tr334:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st199;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	if ( (*p) < 92u ) {
		if ( 72u <= (*p) && (*p) <= 73u )
			goto tr337;
	} else if ( (*p) > 95u ) {
		if ( (*p) > 111u ) {
			if ( 120u <= (*p) && (*p) <= 127u )
				goto tr339;
		} else if ( (*p) >= 104u )
			goto tr339;
	} else
		goto tr339;
	goto tr19;
tr335:
	{
    SET_VEX_PREFIX3(*p);
  }
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	if ( (*p) < 104u ) {
		if ( (*p) > 73u ) {
			if ( 92u <= (*p) && (*p) <= 95u )
				goto tr339;
		} else if ( (*p) >= 72u )
			goto tr337;
	} else if ( (*p) > 105u ) {
		if ( (*p) < 120u ) {
			if ( 108u <= (*p) && (*p) <= 109u )
				goto tr339;
		} else if ( (*p) > 121u ) {
			if ( 124u <= (*p) && (*p) <= 125u )
				goto tr339;
		} else
			goto tr339;
	} else
		goto tr339;
	goto tr19;
tr434:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	switch( (*p) ) {
		case 193u: goto tr356;
		case 194u: goto tr357;
		case 195u: goto tr358;
		case 196u: goto tr359;
		case 197u: goto tr360;
		case 198u: goto tr361;
		case 199u: goto tr362;
		case 201u: goto tr356;
		case 202u: goto tr357;
		case 203u: goto tr358;
		case 204u: goto tr359;
		case 205u: goto tr360;
		case 206u: goto tr361;
		case 207u: goto tr362;
		case 209u: goto tr356;
		case 210u: goto tr357;
		case 211u: goto tr358;
		case 212u: goto tr359;
		case 213u: goto tr360;
		case 214u: goto tr361;
		case 215u: goto tr362;
		case 217u: goto tr356;
		case 218u: goto tr357;
		case 219u: goto tr358;
		case 220u: goto tr359;
		case 221u: goto tr360;
		case 222u: goto tr361;
		case 223u: goto tr362;
		case 225u: goto tr356;
		case 226u: goto tr357;
		case 227u: goto tr358;
		case 228u: goto tr359;
		case 229u: goto tr360;
		case 230u: goto tr361;
		case 231u: goto tr362;
		case 233u: goto tr356;
		case 234u: goto tr357;
		case 235u: goto tr358;
		case 236u: goto tr359;
		case 237u: goto tr360;
		case 238u: goto tr361;
		case 239u: goto tr362;
		case 241u: goto tr356;
		case 242u: goto tr357;
		case 243u: goto tr358;
		case 244u: goto tr359;
		case 245u: goto tr360;
		case 246u: goto tr361;
		case 247u: goto tr362;
		case 248u: goto tr363;
		case 249u: goto tr364;
		case 250u: goto tr365;
		case 251u: goto tr366;
		case 252u: goto tr367;
		case 253u: goto tr368;
		case 254u: goto tr369;
		case 255u: goto tr370;
	}
	if ( 192u <= (*p) && (*p) <= 240u )
		goto tr355;
	goto tr19;
tr357:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st202;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	switch( (*p) ) {
		case 81u: goto tr291;
		case 83u: goto tr291;
		case 194u: goto tr293;
	}
	if ( (*p) > 90u ) {
		if ( 92u <= (*p) && (*p) <= 95u )
			goto tr291;
	} else if ( (*p) >= 88u )
		goto tr291;
	goto tr19;
tr358:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st203;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	switch( (*p) ) {
		case 81u: goto tr291;
		case 194u: goto tr293;
		case 208u: goto tr291;
	}
	if ( (*p) < 92u ) {
		if ( 88u <= (*p) && (*p) <= 90u )
			goto tr291;
	} else if ( (*p) > 95u ) {
		if ( 124u <= (*p) && (*p) <= 125u )
			goto tr291;
	} else
		goto tr291;
	goto tr19;
tr365:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st204;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	switch( (*p) ) {
		case 18u: goto tr291;
		case 22u: goto tr291;
		case 111u: goto tr291;
		case 112u: goto tr293;
		case 194u: goto tr293;
		case 230u: goto tr291;
	}
	if ( (*p) < 81u ) {
		if ( 16u <= (*p) && (*p) <= 17u )
			goto tr292;
	} else if ( (*p) > 83u ) {
		if ( (*p) > 95u ) {
			if ( 126u <= (*p) && (*p) <= 127u )
				goto tr291;
		} else if ( (*p) >= 88u )
			goto tr291;
	} else
		goto tr291;
	goto tr19;
tr366:
	{
    /* VEX.R is not used in ia32 mode.  */
    SET_VEX_PREFIX3(p[0] & 0x7f);
  }
	goto st205;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	switch( (*p) ) {
		case 18u: goto tr291;
		case 81u: goto tr291;
		case 112u: goto tr293;
		case 194u: goto tr293;
		case 208u: goto tr291;
		case 230u: goto tr291;
		case 240u: goto tr292;
	}
	if ( (*p) < 88u ) {
		if ( 16u <= (*p) && (*p) <= 17u )
			goto tr292;
	} else if ( (*p) > 90u ) {
		if ( (*p) > 95u ) {
			if ( 124u <= (*p) && (*p) <= 125u )
				goto tr291;
		} else if ( (*p) >= 92u )
			goto tr291;
	} else
		goto tr291;
	goto tr19;
tr435:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st206;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	switch( (*p) ) {
		case 4u: goto st35;
		case 5u: goto st36;
		case 68u: goto st41;
		case 132u: goto st42;
	}
	if ( (*p) < 64u ) {
		if ( (*p) <= 7u )
			goto st10;
	} else if ( (*p) > 71u ) {
		if ( (*p) > 135u ) {
			if ( 192u <= (*p) && (*p) <= 199u )
				goto st10;
		} else if ( (*p) >= 128u )
			goto st36;
	} else
		goto st40;
	goto tr19;
tr436:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st207;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	switch( (*p) ) {
		case 4u: goto st113;
		case 5u: goto st114;
		case 68u: goto st119;
		case 132u: goto st120;
	}
	if ( (*p) < 64u ) {
		if ( (*p) <= 7u )
			goto st11;
	} else if ( (*p) > 71u ) {
		if ( (*p) > 135u ) {
			if ( 192u <= (*p) && (*p) <= 199u )
				goto st11;
		} else if ( (*p) >= 128u )
			goto st114;
	} else
		goto st118;
	goto tr19;
tr437:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st208;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	goto st209;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	goto tr372;
tr440:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st210;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	switch( (*p) ) {
		case 4u: goto tr374;
		case 5u: goto tr375;
		case 12u: goto tr374;
		case 13u: goto tr375;
		case 20u: goto tr374;
		case 21u: goto tr375;
		case 28u: goto tr374;
		case 29u: goto tr375;
		case 36u: goto tr374;
		case 37u: goto tr375;
		case 44u: goto tr374;
		case 45u: goto tr375;
		case 52u: goto tr374;
		case 53u: goto tr375;
		case 60u: goto tr374;
		case 61u: goto tr375;
		case 68u: goto tr377;
		case 76u: goto tr377;
		case 84u: goto tr377;
		case 92u: goto tr377;
		case 100u: goto tr377;
		case 108u: goto tr377;
		case 116u: goto tr377;
		case 124u: goto tr377;
		case 132u: goto tr378;
		case 140u: goto tr378;
		case 148u: goto tr378;
		case 156u: goto tr378;
		case 164u: goto tr378;
		case 172u: goto tr378;
		case 180u: goto tr378;
		case 188u: goto tr378;
	}
	if ( (*p) > 127u ) {
		if ( 128u <= (*p) && (*p) <= 191u )
			goto tr375;
	} else if ( (*p) >= 64u )
		goto tr376;
	goto tr373;
tr441:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st211;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	switch( (*p) ) {
		case 4u: goto tr374;
		case 5u: goto tr375;
		case 20u: goto tr374;
		case 21u: goto tr375;
		case 28u: goto tr374;
		case 29u: goto tr375;
		case 36u: goto tr374;
		case 37u: goto tr375;
		case 44u: goto tr374;
		case 45u: goto tr375;
		case 52u: goto st2;
		case 53u: goto st3;
		case 60u: goto st2;
		case 61u: goto st3;
		case 68u: goto tr377;
		case 84u: goto tr377;
		case 92u: goto tr377;
		case 100u: goto tr377;
		case 108u: goto tr377;
		case 116u: goto st8;
		case 124u: goto st8;
		case 132u: goto tr378;
		case 148u: goto tr378;
		case 156u: goto tr378;
		case 164u: goto tr378;
		case 172u: goto tr378;
		case 180u: goto st9;
		case 188u: goto st9;
		case 239u: goto tr19;
	}
	if ( (*p) < 128u ) {
		if ( (*p) < 64u ) {
			if ( (*p) > 15u ) {
				if ( 48u <= (*p) && (*p) <= 63u )
					goto tr0;
			} else if ( (*p) >= 8u )
				goto tr19;
		} else if ( (*p) > 71u ) {
			if ( (*p) < 80u ) {
				if ( 72u <= (*p) && (*p) <= 79u )
					goto tr19;
			} else if ( (*p) > 111u ) {
				if ( 112u <= (*p) && (*p) <= 127u )
					goto st7;
			} else
				goto tr376;
		} else
			goto tr376;
	} else if ( (*p) > 135u ) {
		if ( (*p) < 176u ) {
			if ( (*p) > 143u ) {
				if ( 144u <= (*p) && (*p) <= 175u )
					goto tr375;
			} else if ( (*p) >= 136u )
				goto tr19;
		} else if ( (*p) > 191u ) {
			if ( (*p) < 226u ) {
				if ( 209u <= (*p) && (*p) <= 223u )
					goto tr19;
			} else if ( (*p) > 227u ) {
				if ( 230u <= (*p) && (*p) <= 231u )
					goto tr19;
			} else
				goto tr19;
		} else
			goto st3;
	} else
		goto tr375;
	goto tr373;
tr442:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st212;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	switch( (*p) ) {
		case 4u: goto tr374;
		case 12u: goto tr374;
		case 20u: goto tr374;
		case 28u: goto tr374;
		case 36u: goto tr374;
		case 44u: goto tr374;
		case 52u: goto tr374;
		case 60u: goto tr374;
		case 68u: goto tr377;
		case 76u: goto tr377;
		case 84u: goto tr377;
		case 92u: goto tr377;
		case 100u: goto tr377;
		case 108u: goto tr377;
		case 116u: goto tr377;
		case 124u: goto tr377;
		case 132u: goto tr378;
		case 140u: goto tr378;
		case 148u: goto tr378;
		case 156u: goto tr378;
		case 164u: goto tr378;
		case 172u: goto tr378;
		case 180u: goto tr378;
		case 188u: goto tr378;
		case 233u: goto tr373;
	}
	if ( (*p) < 38u ) {
		if ( (*p) < 14u ) {
			if ( (*p) > 3u ) {
				if ( 6u <= (*p) && (*p) <= 11u )
					goto tr373;
			} else
				goto tr373;
		} else if ( (*p) > 19u ) {
			if ( (*p) > 27u ) {
				if ( 30u <= (*p) && (*p) <= 35u )
					goto tr373;
			} else if ( (*p) >= 22u )
				goto tr373;
		} else
			goto tr373;
	} else if ( (*p) > 43u ) {
		if ( (*p) < 62u ) {
			if ( (*p) > 51u ) {
				if ( 54u <= (*p) && (*p) <= 59u )
					goto tr373;
			} else if ( (*p) >= 46u )
				goto tr373;
		} else if ( (*p) > 63u ) {
			if ( (*p) < 192u ) {
				if ( 64u <= (*p) && (*p) <= 127u )
					goto tr376;
			} else if ( (*p) > 223u ) {
				if ( 224u <= (*p) )
					goto tr19;
			} else
				goto tr379;
		} else
			goto tr373;
	} else
		goto tr373;
	goto tr375;
tr443:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st213;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	switch( (*p) ) {
		case 4u: goto tr374;
		case 5u: goto tr375;
		case 12u: goto tr374;
		case 13u: goto tr375;
		case 20u: goto tr374;
		case 21u: goto tr375;
		case 28u: goto tr374;
		case 29u: goto tr375;
		case 44u: goto tr374;
		case 45u: goto tr375;
		case 60u: goto tr374;
		case 61u: goto tr375;
		case 68u: goto tr377;
		case 76u: goto tr377;
		case 84u: goto tr377;
		case 92u: goto tr377;
		case 108u: goto tr377;
		case 124u: goto tr377;
		case 132u: goto tr378;
		case 140u: goto tr378;
		case 148u: goto tr378;
		case 156u: goto tr378;
		case 172u: goto tr378;
		case 188u: goto tr378;
	}
	if ( (*p) < 120u ) {
		if ( (*p) < 56u ) {
			if ( (*p) > 31u ) {
				if ( 40u <= (*p) && (*p) <= 47u )
					goto tr373;
			} else
				goto tr373;
		} else if ( (*p) > 63u ) {
			if ( (*p) > 95u ) {
				if ( 104u <= (*p) && (*p) <= 111u )
					goto tr376;
			} else if ( (*p) >= 64u )
				goto tr376;
		} else
			goto tr373;
	} else if ( (*p) > 127u ) {
		if ( (*p) < 184u ) {
			if ( (*p) > 159u ) {
				if ( 168u <= (*p) && (*p) <= 175u )
					goto tr375;
			} else if ( (*p) >= 128u )
				goto tr375;
		} else if ( (*p) > 191u ) {
			if ( (*p) < 226u ) {
				if ( 192u <= (*p) && (*p) <= 223u )
					goto tr379;
			} else if ( (*p) > 227u ) {
				if ( 232u <= (*p) && (*p) <= 247u )
					goto tr373;
			} else
				goto tr373;
		} else
			goto tr375;
	} else
		goto tr376;
	goto tr19;
tr444:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st214;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	switch( (*p) ) {
		case 4u: goto tr374;
		case 5u: goto tr375;
		case 12u: goto tr374;
		case 13u: goto tr375;
		case 20u: goto tr374;
		case 21u: goto tr375;
		case 28u: goto tr374;
		case 29u: goto tr375;
		case 36u: goto tr374;
		case 37u: goto tr375;
		case 44u: goto tr374;
		case 45u: goto tr375;
		case 52u: goto tr374;
		case 53u: goto tr375;
		case 60u: goto tr374;
		case 61u: goto tr375;
		case 68u: goto tr377;
		case 76u: goto tr377;
		case 84u: goto tr377;
		case 92u: goto tr377;
		case 100u: goto tr377;
		case 108u: goto tr377;
		case 116u: goto tr377;
		case 124u: goto tr377;
		case 132u: goto tr378;
		case 140u: goto tr378;
		case 148u: goto tr378;
		case 156u: goto tr378;
		case 164u: goto tr378;
		case 172u: goto tr378;
		case 180u: goto tr378;
		case 188u: goto tr378;
	}
	if ( (*p) < 128u ) {
		if ( 64u <= (*p) && (*p) <= 127u )
			goto tr376;
	} else if ( (*p) > 191u ) {
		if ( 208u <= (*p) && (*p) <= 223u )
			goto tr19;
	} else
		goto tr375;
	goto tr373;
tr445:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st215;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	switch( (*p) ) {
		case 4u: goto tr374;
		case 5u: goto tr375;
		case 12u: goto tr374;
		case 13u: goto tr375;
		case 20u: goto tr374;
		case 21u: goto tr375;
		case 28u: goto tr374;
		case 29u: goto tr375;
		case 36u: goto tr374;
		case 37u: goto tr375;
		case 52u: goto tr374;
		case 53u: goto tr375;
		case 60u: goto tr374;
		case 61u: goto tr375;
		case 68u: goto tr377;
		case 76u: goto tr377;
		case 84u: goto tr377;
		case 92u: goto tr377;
		case 100u: goto tr377;
		case 116u: goto tr377;
		case 124u: goto tr377;
		case 132u: goto tr378;
		case 140u: goto tr378;
		case 148u: goto tr378;
		case 156u: goto tr378;
		case 164u: goto tr378;
		case 180u: goto tr378;
		case 188u: goto tr378;
	}
	if ( (*p) < 128u ) {
		if ( (*p) < 64u ) {
			if ( 40u <= (*p) && (*p) <= 47u )
				goto tr19;
		} else if ( (*p) > 103u ) {
			if ( (*p) > 111u ) {
				if ( 112u <= (*p) && (*p) <= 127u )
					goto tr376;
			} else if ( (*p) >= 104u )
				goto tr19;
		} else
			goto tr376;
	} else if ( (*p) > 167u ) {
		if ( (*p) < 176u ) {
			if ( 168u <= (*p) && (*p) <= 175u )
				goto tr19;
		} else if ( (*p) > 191u ) {
			if ( (*p) > 207u ) {
				if ( 240u <= (*p) )
					goto tr19;
			} else if ( (*p) >= 200u )
				goto tr19;
		} else
			goto tr375;
	} else
		goto tr375;
	goto tr373;
tr446:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	switch( (*p) ) {
		case 4u: goto tr374;
		case 5u: goto tr375;
		case 12u: goto tr374;
		case 13u: goto tr375;
		case 20u: goto tr374;
		case 21u: goto tr375;
		case 28u: goto tr374;
		case 29u: goto tr375;
		case 36u: goto tr374;
		case 37u: goto tr375;
		case 44u: goto tr374;
		case 45u: goto tr375;
		case 52u: goto tr374;
		case 53u: goto tr375;
		case 60u: goto tr374;
		case 61u: goto tr375;
		case 68u: goto tr377;
		case 76u: goto tr377;
		case 84u: goto tr377;
		case 92u: goto tr377;
		case 100u: goto tr377;
		case 108u: goto tr377;
		case 116u: goto tr377;
		case 124u: goto tr377;
		case 132u: goto tr378;
		case 140u: goto tr378;
		case 148u: goto tr378;
		case 156u: goto tr378;
		case 164u: goto tr378;
		case 172u: goto tr378;
		case 180u: goto tr378;
		case 188u: goto tr378;
	}
	if ( (*p) < 128u ) {
		if ( 64u <= (*p) && (*p) <= 127u )
			goto tr376;
	} else if ( (*p) > 191u ) {
		if ( (*p) > 216u ) {
			if ( 218u <= (*p) && (*p) <= 223u )
				goto tr19;
		} else if ( (*p) >= 208u )
			goto tr19;
	} else
		goto tr375;
	goto tr373;
tr447:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st217;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	switch( (*p) ) {
		case 4u: goto tr374;
		case 5u: goto tr375;
		case 12u: goto tr374;
		case 13u: goto tr375;
		case 20u: goto tr374;
		case 21u: goto tr375;
		case 28u: goto tr374;
		case 29u: goto tr375;
		case 36u: goto tr374;
		case 37u: goto tr375;
		case 44u: goto tr374;
		case 45u: goto tr375;
		case 52u: goto tr374;
		case 53u: goto tr375;
		case 60u: goto tr374;
		case 61u: goto tr375;
		case 68u: goto tr377;
		case 76u: goto tr377;
		case 84u: goto tr377;
		case 92u: goto tr377;
		case 100u: goto tr377;
		case 108u: goto tr377;
		case 116u: goto tr377;
		case 124u: goto tr377;
		case 132u: goto tr378;
		case 140u: goto tr378;
		case 148u: goto tr378;
		case 156u: goto tr378;
		case 164u: goto tr378;
		case 172u: goto tr378;
		case 180u: goto tr378;
		case 188u: goto tr378;
	}
	if ( (*p) < 192u ) {
		if ( (*p) > 127u ) {
			if ( 128u <= (*p) && (*p) <= 191u )
				goto tr375;
		} else if ( (*p) >= 64u )
			goto tr376;
	} else if ( (*p) > 223u ) {
		if ( (*p) > 231u ) {
			if ( 248u <= (*p) )
				goto tr19;
		} else if ( (*p) >= 225u )
			goto tr19;
	} else
		goto tr19;
	goto tr373;
tr449:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	{
    SET_LOCK_PREFIX(TRUE);
  }
	goto st218;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	switch( (*p) ) {
		case 15u: goto st219;
		case 102u: goto tr381;
		case 128u: goto st102;
		case 129u: goto st220;
		case 131u: goto st102;
	}
	if ( (*p) < 32u ) {
		if ( (*p) < 8u ) {
			if ( (*p) <= 1u )
				goto st30;
		} else if ( (*p) > 9u ) {
			if ( (*p) > 17u ) {
				if ( 24u <= (*p) && (*p) <= 25u )
					goto st30;
			} else if ( (*p) >= 16u )
				goto st30;
		} else
			goto st30;
	} else if ( (*p) > 33u ) {
		if ( (*p) < 134u ) {
			if ( (*p) > 41u ) {
				if ( 48u <= (*p) && (*p) <= 49u )
					goto st30;
			} else if ( (*p) >= 40u )
				goto st30;
		} else if ( (*p) > 135u ) {
			if ( (*p) > 247u ) {
				if ( 254u <= (*p) )
					goto st104;
			} else if ( (*p) >= 246u )
				goto st103;
		} else
			goto st30;
	} else
		goto st30;
	goto tr19;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	if ( (*p) == 199u )
		goto st51;
	if ( (*p) > 177u ) {
		if ( 192u <= (*p) && (*p) <= 193u )
			goto st30;
	} else if ( (*p) >= 176u )
		goto st30;
	goto tr19;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	switch( (*p) ) {
		case 4u: goto st113;
		case 5u: goto st114;
		case 12u: goto st113;
		case 13u: goto st114;
		case 20u: goto st113;
		case 21u: goto st114;
		case 28u: goto st113;
		case 29u: goto st114;
		case 36u: goto st113;
		case 37u: goto st114;
		case 44u: goto st113;
		case 45u: goto st114;
		case 52u: goto st113;
		case 53u: goto st114;
		case 68u: goto st119;
		case 76u: goto st119;
		case 84u: goto st119;
		case 92u: goto st119;
		case 100u: goto st119;
		case 108u: goto st119;
		case 116u: goto st119;
		case 132u: goto st120;
		case 140u: goto st120;
		case 148u: goto st120;
		case 156u: goto st120;
		case 164u: goto st120;
		case 172u: goto st120;
		case 180u: goto st120;
	}
	if ( (*p) < 64u ) {
		if ( (*p) <= 55u )
			goto st11;
	} else if ( (*p) > 119u ) {
		if ( 128u <= (*p) && (*p) <= 183u )
			goto st114;
	} else
		goto st118;
	goto tr19;
tr450:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	{
    SET_REPNZ_PREFIX(TRUE);
  }
	goto st221;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	switch( (*p) ) {
		case 15u: goto st222;
		case 102u: goto tr384;
	}
	if ( (*p) > 167u ) {
		if ( 174u <= (*p) && (*p) <= 175u )
			goto tr0;
	} else if ( (*p) >= 166u )
		goto tr0;
	goto tr19;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	switch( (*p) ) {
		case 18u: goto tr386;
		case 43u: goto tr387;
		case 56u: goto st223;
		case 81u: goto tr385;
		case 112u: goto tr389;
		case 120u: goto tr390;
		case 121u: goto tr391;
		case 194u: goto tr389;
		case 208u: goto tr392;
		case 214u: goto tr393;
		case 230u: goto tr385;
		case 240u: goto tr394;
	}
	if ( (*p) < 88u ) {
		if ( (*p) > 17u ) {
			if ( 42u <= (*p) && (*p) <= 45u )
				goto tr385;
		} else if ( (*p) >= 16u )
			goto tr385;
	} else if ( (*p) > 90u ) {
		if ( (*p) > 95u ) {
			if ( 124u <= (*p) && (*p) <= 125u )
				goto tr386;
		} else if ( (*p) >= 92u )
			goto tr385;
	} else
		goto tr385;
	goto tr19;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	if ( 240u <= (*p) && (*p) <= 241u )
		goto tr201;
	goto tr19;
tr390:
	{
    SET_REPNZ_PREFIX(FALSE);
  }
	{
    SET_CPU_FEATURE(CPUFeature_SSE4A);
  }
	goto st224;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( 192u <= (*p) )
		goto st225;
	goto tr19;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	goto tr396;
tr451:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	{
    SET_REPZ_PREFIX(TRUE);
  }
	{
    SET_REPZ_PREFIX(TRUE);
  }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	switch( (*p) ) {
		case 15u: goto st227;
		case 102u: goto tr398;
		case 144u: goto tr399;
	}
	if ( (*p) > 167u ) {
		if ( 170u <= (*p) && (*p) <= 175u )
			goto tr0;
	} else if ( (*p) >= 164u )
		goto tr0;
	goto tr19;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	switch( (*p) ) {
		case 18u: goto tr401;
		case 22u: goto tr401;
		case 43u: goto tr402;
		case 111u: goto tr403;
		case 112u: goto tr404;
		case 184u: goto tr203;
		case 188u: goto tr204;
		case 189u: goto tr205;
		case 194u: goto tr405;
		case 214u: goto tr406;
		case 230u: goto tr403;
	}
	if ( (*p) < 88u ) {
		if ( (*p) < 42u ) {
			if ( 16u <= (*p) && (*p) <= 17u )
				goto tr400;
		} else if ( (*p) > 45u ) {
			if ( 81u <= (*p) && (*p) <= 83u )
				goto tr400;
		} else
			goto tr400;
	} else if ( (*p) > 89u ) {
		if ( (*p) < 92u ) {
			if ( 90u <= (*p) && (*p) <= 91u )
				goto tr403;
		} else if ( (*p) > 95u ) {
			if ( 126u <= (*p) && (*p) <= 127u )
				goto tr403;
		} else
			goto tr400;
	} else
		goto tr400;
	goto tr19;
tr452:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st228;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	switch( (*p) ) {
		case 4u: goto st35;
		case 5u: goto st36;
		case 20u: goto st2;
		case 21u: goto st3;
		case 28u: goto st2;
		case 29u: goto st3;
		case 36u: goto st2;
		case 37u: goto st3;
		case 44u: goto st2;
		case 45u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 60u: goto st2;
		case 61u: goto st3;
		case 68u: goto st41;
		case 84u: goto st8;
		case 92u: goto st8;
		case 100u: goto st8;
		case 108u: goto st8;
		case 116u: goto st8;
		case 124u: goto st8;
		case 132u: goto st42;
		case 148u: goto st9;
		case 156u: goto st9;
		case 164u: goto st9;
		case 172u: goto st9;
		case 180u: goto st9;
		case 188u: goto st9;
	}
	if ( (*p) < 80u ) {
		if ( (*p) < 8u ) {
			if ( (*p) <= 7u )
				goto st10;
		} else if ( (*p) > 15u ) {
			if ( (*p) > 71u ) {
				if ( 72u <= (*p) && (*p) <= 79u )
					goto tr19;
			} else if ( (*p) >= 64u )
				goto st40;
		} else
			goto tr19;
	} else if ( (*p) > 127u ) {
		if ( (*p) < 144u ) {
			if ( (*p) > 135u ) {
				if ( 136u <= (*p) && (*p) <= 143u )
					goto tr19;
			} else if ( (*p) >= 128u )
				goto st36;
		} else if ( (*p) > 191u ) {
			if ( (*p) > 199u ) {
				if ( 200u <= (*p) && (*p) <= 207u )
					goto tr19;
			} else if ( (*p) >= 192u )
				goto st10;
		} else
			goto st3;
	} else
		goto st7;
	goto tr0;
tr453:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st229;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	switch( (*p) ) {
		case 4u: goto st113;
		case 5u: goto st114;
		case 20u: goto st2;
		case 21u: goto st3;
		case 28u: goto st2;
		case 29u: goto st3;
		case 36u: goto st2;
		case 37u: goto st3;
		case 44u: goto st2;
		case 45u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 60u: goto st2;
		case 61u: goto st3;
		case 68u: goto st119;
		case 84u: goto st8;
		case 92u: goto st8;
		case 100u: goto st8;
		case 108u: goto st8;
		case 116u: goto st8;
		case 124u: goto st8;
		case 132u: goto st120;
		case 148u: goto st9;
		case 156u: goto st9;
		case 164u: goto st9;
		case 172u: goto st9;
		case 180u: goto st9;
		case 188u: goto st9;
	}
	if ( (*p) < 80u ) {
		if ( (*p) < 8u ) {
			if ( (*p) <= 7u )
				goto st11;
		} else if ( (*p) > 15u ) {
			if ( (*p) > 71u ) {
				if ( 72u <= (*p) && (*p) <= 79u )
					goto tr19;
			} else if ( (*p) >= 64u )
				goto st118;
		} else
			goto tr19;
	} else if ( (*p) > 127u ) {
		if ( (*p) < 144u ) {
			if ( (*p) > 135u ) {
				if ( 136u <= (*p) && (*p) <= 143u )
					goto tr19;
			} else if ( (*p) >= 128u )
				goto st114;
		} else if ( (*p) > 191u ) {
			if ( (*p) > 199u ) {
				if ( 200u <= (*p) && (*p) <= 207u )
					goto tr19;
			} else if ( (*p) >= 192u )
				goto st11;
		} else
			goto st3;
	} else
		goto st7;
	goto tr0;
tr454:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st230;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
	}
	if ( (*p) < 64u ) {
		if ( (*p) <= 15u )
			goto tr0;
	} else if ( (*p) > 79u ) {
		if ( (*p) > 143u ) {
			if ( 192u <= (*p) && (*p) <= 207u )
				goto tr0;
		} else if ( (*p) >= 128u )
			goto st3;
	} else
		goto st7;
	goto tr19;
tr456:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st231;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 116u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
		case 180u: goto st9;
		case 208u: goto tr407;
		case 224u: goto tr407;
	}
	if ( (*p) < 112u ) {
		if ( (*p) < 48u ) {
			if ( (*p) <= 15u )
				goto tr0;
		} else if ( (*p) > 55u ) {
			if ( 64u <= (*p) && (*p) <= 79u )
				goto st7;
		} else
			goto tr0;
	} else if ( (*p) > 119u ) {
		if ( (*p) < 176u ) {
			if ( 128u <= (*p) && (*p) <= 143u )
				goto st3;
		} else if ( (*p) > 183u ) {
			if ( (*p) > 207u ) {
				if ( 240u <= (*p) && (*p) <= 247u )
					goto tr0;
			} else if ( (*p) >= 192u )
				goto tr0;
		} else
			goto st3;
	} else
		goto st7;
	goto tr19;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	if ( (*p) == 224u )
		goto tr408;
	goto tr11;
tr408:
	{ }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st248;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	switch( (*p) ) {
		case 4u: goto tr416;
		case 5u: goto tr417;
		case 12u: goto tr416;
		case 13u: goto tr417;
		case 14u: goto tr19;
		case 15u: goto tr418;
		case 20u: goto tr416;
		case 21u: goto tr417;
		case 28u: goto tr416;
		case 29u: goto tr417;
		case 36u: goto tr416;
		case 37u: goto tr417;
		case 44u: goto tr416;
		case 45u: goto tr417;
		case 46u: goto tr419;
		case 47u: goto tr19;
		case 52u: goto tr416;
		case 53u: goto tr417;
		case 60u: goto tr416;
		case 61u: goto tr417;
		case 62u: goto tr420;
		case 63u: goto tr19;
		case 101u: goto tr422;
		case 102u: goto tr423;
		case 104u: goto tr417;
		case 105u: goto tr424;
		case 106u: goto tr416;
		case 107u: goto tr425;
		case 128u: goto tr425;
		case 129u: goto tr424;
		case 130u: goto tr19;
		case 131u: goto tr427;
		case 141u: goto tr428;
		case 143u: goto tr429;
		case 155u: goto tr430;
		case 168u: goto tr416;
		case 169u: goto tr417;
		case 196u: goto tr433;
		case 197u: goto tr434;
		case 198u: goto tr435;
		case 199u: goto tr436;
		case 200u: goto tr437;
		case 202u: goto tr438;
		case 216u: goto tr440;
		case 217u: goto tr441;
		case 218u: goto tr442;
		case 219u: goto tr443;
		case 220u: goto tr444;
		case 221u: goto tr445;
		case 222u: goto tr446;
		case 223u: goto tr447;
		case 235u: goto tr426;
		case 240u: goto tr449;
		case 242u: goto tr450;
		case 243u: goto tr451;
		case 246u: goto tr452;
		case 247u: goto tr453;
		case 254u: goto tr454;
		case 255u: goto tr457;
	}
	if ( (*p) < 132u ) {
		if ( (*p) < 32u ) {
			if ( (*p) < 8u ) {
				if ( (*p) > 3u ) {
					if ( 6u <= (*p) && (*p) <= 7u )
						goto tr19;
				} else
					goto tr415;
			} else if ( (*p) > 19u ) {
				if ( (*p) < 24u ) {
					if ( 22u <= (*p) && (*p) <= 23u )
						goto tr19;
				} else if ( (*p) > 27u ) {
					if ( 30u <= (*p) && (*p) <= 31u )
						goto tr19;
				} else
					goto tr415;
			} else
				goto tr415;
		} else if ( (*p) > 35u ) {
			if ( (*p) < 54u ) {
				if ( (*p) > 39u ) {
					if ( 40u <= (*p) && (*p) <= 51u )
						goto tr415;
				} else if ( (*p) >= 38u )
					goto tr19;
			} else if ( (*p) > 55u ) {
				if ( (*p) < 96u ) {
					if ( 56u <= (*p) && (*p) <= 59u )
						goto tr415;
				} else if ( (*p) > 111u ) {
					if ( 112u <= (*p) && (*p) <= 127u )
						goto tr426;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr415;
	} else if ( (*p) > 139u ) {
		if ( (*p) < 194u ) {
			if ( (*p) < 160u ) {
				if ( (*p) > 142u ) {
					if ( 154u <= (*p) && (*p) <= 157u )
						goto tr19;
				} else if ( (*p) >= 140u )
					goto tr19;
			} else if ( (*p) > 163u ) {
				if ( (*p) < 184u ) {
					if ( 176u <= (*p) && (*p) <= 183u )
						goto tr416;
				} else if ( (*p) > 191u ) {
					if ( 192u <= (*p) && (*p) <= 193u )
						goto tr432;
				} else
					goto tr417;
			} else
				goto tr431;
		} else if ( (*p) > 195u ) {
			if ( (*p) < 212u ) {
				if ( (*p) > 207u ) {
					if ( 208u <= (*p) && (*p) <= 211u )
						goto tr439;
				} else if ( (*p) >= 204u )
					goto tr19;
			} else if ( (*p) > 231u ) {
				if ( (*p) < 234u ) {
					if ( 232u <= (*p) && (*p) <= 233u )
						goto tr448;
				} else if ( (*p) > 241u ) {
					if ( 250u <= (*p) && (*p) <= 251u )
						goto tr19;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr19;
	} else
		goto tr415;
	goto tr421;
tr457:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 116u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
		case 180u: goto st9;
		case 209u: goto tr407;
		case 225u: goto tr407;
	}
	if ( (*p) < 112u ) {
		if ( (*p) < 48u ) {
			if ( (*p) <= 15u )
				goto tr0;
		} else if ( (*p) > 55u ) {
			if ( 64u <= (*p) && (*p) <= 79u )
				goto st7;
		} else
			goto tr0;
	} else if ( (*p) > 119u ) {
		if ( (*p) < 176u ) {
			if ( 128u <= (*p) && (*p) <= 143u )
				goto st3;
		} else if ( (*p) > 183u ) {
			if ( (*p) > 207u ) {
				if ( 240u <= (*p) && (*p) <= 247u )
					goto tr0;
			} else if ( (*p) >= 192u )
				goto tr0;
		} else
			goto st3;
	} else
		goto st7;
	goto tr19;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	if ( (*p) == 224u )
		goto tr409;
	goto tr11;
tr409:
	{ }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st249;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	switch( (*p) ) {
		case 4u: goto tr416;
		case 5u: goto tr417;
		case 12u: goto tr416;
		case 13u: goto tr417;
		case 14u: goto tr19;
		case 15u: goto tr418;
		case 20u: goto tr416;
		case 21u: goto tr417;
		case 28u: goto tr416;
		case 29u: goto tr417;
		case 36u: goto tr416;
		case 37u: goto tr417;
		case 44u: goto tr416;
		case 45u: goto tr417;
		case 46u: goto tr419;
		case 47u: goto tr19;
		case 52u: goto tr416;
		case 53u: goto tr417;
		case 60u: goto tr416;
		case 61u: goto tr417;
		case 62u: goto tr420;
		case 63u: goto tr19;
		case 101u: goto tr422;
		case 102u: goto tr423;
		case 104u: goto tr417;
		case 105u: goto tr424;
		case 106u: goto tr416;
		case 107u: goto tr425;
		case 128u: goto tr425;
		case 129u: goto tr424;
		case 130u: goto tr19;
		case 131u: goto tr427;
		case 141u: goto tr428;
		case 143u: goto tr429;
		case 155u: goto tr430;
		case 168u: goto tr416;
		case 169u: goto tr417;
		case 196u: goto tr433;
		case 197u: goto tr434;
		case 198u: goto tr435;
		case 199u: goto tr436;
		case 200u: goto tr437;
		case 202u: goto tr438;
		case 216u: goto tr440;
		case 217u: goto tr441;
		case 218u: goto tr442;
		case 219u: goto tr443;
		case 220u: goto tr444;
		case 221u: goto tr445;
		case 222u: goto tr446;
		case 223u: goto tr447;
		case 235u: goto tr426;
		case 240u: goto tr449;
		case 242u: goto tr450;
		case 243u: goto tr451;
		case 246u: goto tr452;
		case 247u: goto tr453;
		case 254u: goto tr454;
		case 255u: goto tr458;
	}
	if ( (*p) < 132u ) {
		if ( (*p) < 32u ) {
			if ( (*p) < 8u ) {
				if ( (*p) > 3u ) {
					if ( 6u <= (*p) && (*p) <= 7u )
						goto tr19;
				} else
					goto tr415;
			} else if ( (*p) > 19u ) {
				if ( (*p) < 24u ) {
					if ( 22u <= (*p) && (*p) <= 23u )
						goto tr19;
				} else if ( (*p) > 27u ) {
					if ( 30u <= (*p) && (*p) <= 31u )
						goto tr19;
				} else
					goto tr415;
			} else
				goto tr415;
		} else if ( (*p) > 35u ) {
			if ( (*p) < 54u ) {
				if ( (*p) > 39u ) {
					if ( 40u <= (*p) && (*p) <= 51u )
						goto tr415;
				} else if ( (*p) >= 38u )
					goto tr19;
			} else if ( (*p) > 55u ) {
				if ( (*p) < 96u ) {
					if ( 56u <= (*p) && (*p) <= 59u )
						goto tr415;
				} else if ( (*p) > 111u ) {
					if ( 112u <= (*p) && (*p) <= 127u )
						goto tr426;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr415;
	} else if ( (*p) > 139u ) {
		if ( (*p) < 194u ) {
			if ( (*p) < 160u ) {
				if ( (*p) > 142u ) {
					if ( 154u <= (*p) && (*p) <= 157u )
						goto tr19;
				} else if ( (*p) >= 140u )
					goto tr19;
			} else if ( (*p) > 163u ) {
				if ( (*p) < 184u ) {
					if ( 176u <= (*p) && (*p) <= 183u )
						goto tr416;
				} else if ( (*p) > 191u ) {
					if ( 192u <= (*p) && (*p) <= 193u )
						goto tr432;
				} else
					goto tr417;
			} else
				goto tr431;
		} else if ( (*p) > 195u ) {
			if ( (*p) < 212u ) {
				if ( (*p) > 207u ) {
					if ( 208u <= (*p) && (*p) <= 211u )
						goto tr439;
				} else if ( (*p) >= 204u )
					goto tr19;
			} else if ( (*p) > 231u ) {
				if ( (*p) < 234u ) {
					if ( 232u <= (*p) && (*p) <= 233u )
						goto tr448;
				} else if ( (*p) > 241u ) {
					if ( 250u <= (*p) && (*p) <= 251u )
						goto tr19;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr19;
	} else
		goto tr415;
	goto tr421;
tr458:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 116u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
		case 180u: goto st9;
		case 210u: goto tr407;
		case 226u: goto tr407;
	}
	if ( (*p) < 112u ) {
		if ( (*p) < 48u ) {
			if ( (*p) <= 15u )
				goto tr0;
		} else if ( (*p) > 55u ) {
			if ( 64u <= (*p) && (*p) <= 79u )
				goto st7;
		} else
			goto tr0;
	} else if ( (*p) > 119u ) {
		if ( (*p) < 176u ) {
			if ( 128u <= (*p) && (*p) <= 143u )
				goto st3;
		} else if ( (*p) > 183u ) {
			if ( (*p) > 207u ) {
				if ( 240u <= (*p) && (*p) <= 247u )
					goto tr0;
			} else if ( (*p) >= 192u )
				goto tr0;
		} else
			goto st3;
	} else
		goto st7;
	goto tr19;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	if ( (*p) == 224u )
		goto tr410;
	goto tr11;
tr410:
	{ }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
	switch( (*p) ) {
		case 4u: goto tr416;
		case 5u: goto tr417;
		case 12u: goto tr416;
		case 13u: goto tr417;
		case 14u: goto tr19;
		case 15u: goto tr418;
		case 20u: goto tr416;
		case 21u: goto tr417;
		case 28u: goto tr416;
		case 29u: goto tr417;
		case 36u: goto tr416;
		case 37u: goto tr417;
		case 44u: goto tr416;
		case 45u: goto tr417;
		case 46u: goto tr419;
		case 47u: goto tr19;
		case 52u: goto tr416;
		case 53u: goto tr417;
		case 60u: goto tr416;
		case 61u: goto tr417;
		case 62u: goto tr420;
		case 63u: goto tr19;
		case 101u: goto tr422;
		case 102u: goto tr423;
		case 104u: goto tr417;
		case 105u: goto tr424;
		case 106u: goto tr416;
		case 107u: goto tr425;
		case 128u: goto tr425;
		case 129u: goto tr424;
		case 130u: goto tr19;
		case 131u: goto tr427;
		case 141u: goto tr428;
		case 143u: goto tr429;
		case 155u: goto tr430;
		case 168u: goto tr416;
		case 169u: goto tr417;
		case 196u: goto tr433;
		case 197u: goto tr434;
		case 198u: goto tr435;
		case 199u: goto tr436;
		case 200u: goto tr437;
		case 202u: goto tr438;
		case 216u: goto tr440;
		case 217u: goto tr441;
		case 218u: goto tr442;
		case 219u: goto tr443;
		case 220u: goto tr444;
		case 221u: goto tr445;
		case 222u: goto tr446;
		case 223u: goto tr447;
		case 235u: goto tr426;
		case 240u: goto tr449;
		case 242u: goto tr450;
		case 243u: goto tr451;
		case 246u: goto tr452;
		case 247u: goto tr453;
		case 254u: goto tr454;
		case 255u: goto tr459;
	}
	if ( (*p) < 132u ) {
		if ( (*p) < 32u ) {
			if ( (*p) < 8u ) {
				if ( (*p) > 3u ) {
					if ( 6u <= (*p) && (*p) <= 7u )
						goto tr19;
				} else
					goto tr415;
			} else if ( (*p) > 19u ) {
				if ( (*p) < 24u ) {
					if ( 22u <= (*p) && (*p) <= 23u )
						goto tr19;
				} else if ( (*p) > 27u ) {
					if ( 30u <= (*p) && (*p) <= 31u )
						goto tr19;
				} else
					goto tr415;
			} else
				goto tr415;
		} else if ( (*p) > 35u ) {
			if ( (*p) < 54u ) {
				if ( (*p) > 39u ) {
					if ( 40u <= (*p) && (*p) <= 51u )
						goto tr415;
				} else if ( (*p) >= 38u )
					goto tr19;
			} else if ( (*p) > 55u ) {
				if ( (*p) < 96u ) {
					if ( 56u <= (*p) && (*p) <= 59u )
						goto tr415;
				} else if ( (*p) > 111u ) {
					if ( 112u <= (*p) && (*p) <= 127u )
						goto tr426;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr415;
	} else if ( (*p) > 139u ) {
		if ( (*p) < 194u ) {
			if ( (*p) < 160u ) {
				if ( (*p) > 142u ) {
					if ( 154u <= (*p) && (*p) <= 157u )
						goto tr19;
				} else if ( (*p) >= 140u )
					goto tr19;
			} else if ( (*p) > 163u ) {
				if ( (*p) < 184u ) {
					if ( 176u <= (*p) && (*p) <= 183u )
						goto tr416;
				} else if ( (*p) > 191u ) {
					if ( 192u <= (*p) && (*p) <= 193u )
						goto tr432;
				} else
					goto tr417;
			} else
				goto tr431;
		} else if ( (*p) > 195u ) {
			if ( (*p) < 212u ) {
				if ( (*p) > 207u ) {
					if ( 208u <= (*p) && (*p) <= 211u )
						goto tr439;
				} else if ( (*p) >= 204u )
					goto tr19;
			} else if ( (*p) > 231u ) {
				if ( (*p) < 234u ) {
					if ( 232u <= (*p) && (*p) <= 233u )
						goto tr448;
				} else if ( (*p) > 241u ) {
					if ( 250u <= (*p) && (*p) <= 251u )
						goto tr19;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr19;
	} else
		goto tr415;
	goto tr421;
tr459:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 116u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
		case 180u: goto st9;
		case 211u: goto tr407;
		case 227u: goto tr407;
	}
	if ( (*p) < 112u ) {
		if ( (*p) < 48u ) {
			if ( (*p) <= 15u )
				goto tr0;
		} else if ( (*p) > 55u ) {
			if ( 64u <= (*p) && (*p) <= 79u )
				goto st7;
		} else
			goto tr0;
	} else if ( (*p) > 119u ) {
		if ( (*p) < 176u ) {
			if ( 128u <= (*p) && (*p) <= 143u )
				goto st3;
		} else if ( (*p) > 183u ) {
			if ( (*p) > 207u ) {
				if ( 240u <= (*p) && (*p) <= 247u )
					goto tr0;
			} else if ( (*p) >= 192u )
				goto tr0;
		} else
			goto st3;
	} else
		goto st7;
	goto tr19;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	if ( (*p) == 224u )
		goto tr411;
	goto tr11;
tr411:
	{ }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	switch( (*p) ) {
		case 4u: goto tr416;
		case 5u: goto tr417;
		case 12u: goto tr416;
		case 13u: goto tr417;
		case 14u: goto tr19;
		case 15u: goto tr418;
		case 20u: goto tr416;
		case 21u: goto tr417;
		case 28u: goto tr416;
		case 29u: goto tr417;
		case 36u: goto tr416;
		case 37u: goto tr417;
		case 44u: goto tr416;
		case 45u: goto tr417;
		case 46u: goto tr419;
		case 47u: goto tr19;
		case 52u: goto tr416;
		case 53u: goto tr417;
		case 60u: goto tr416;
		case 61u: goto tr417;
		case 62u: goto tr420;
		case 63u: goto tr19;
		case 101u: goto tr422;
		case 102u: goto tr423;
		case 104u: goto tr417;
		case 105u: goto tr424;
		case 106u: goto tr416;
		case 107u: goto tr425;
		case 128u: goto tr425;
		case 129u: goto tr424;
		case 130u: goto tr19;
		case 131u: goto tr427;
		case 141u: goto tr428;
		case 143u: goto tr429;
		case 155u: goto tr430;
		case 168u: goto tr416;
		case 169u: goto tr417;
		case 196u: goto tr433;
		case 197u: goto tr434;
		case 198u: goto tr435;
		case 199u: goto tr436;
		case 200u: goto tr437;
		case 202u: goto tr438;
		case 216u: goto tr440;
		case 217u: goto tr441;
		case 218u: goto tr442;
		case 219u: goto tr443;
		case 220u: goto tr444;
		case 221u: goto tr445;
		case 222u: goto tr446;
		case 223u: goto tr447;
		case 235u: goto tr426;
		case 240u: goto tr449;
		case 242u: goto tr450;
		case 243u: goto tr451;
		case 246u: goto tr452;
		case 247u: goto tr453;
		case 254u: goto tr454;
		case 255u: goto tr460;
	}
	if ( (*p) < 132u ) {
		if ( (*p) < 32u ) {
			if ( (*p) < 8u ) {
				if ( (*p) > 3u ) {
					if ( 6u <= (*p) && (*p) <= 7u )
						goto tr19;
				} else
					goto tr415;
			} else if ( (*p) > 19u ) {
				if ( (*p) < 24u ) {
					if ( 22u <= (*p) && (*p) <= 23u )
						goto tr19;
				} else if ( (*p) > 27u ) {
					if ( 30u <= (*p) && (*p) <= 31u )
						goto tr19;
				} else
					goto tr415;
			} else
				goto tr415;
		} else if ( (*p) > 35u ) {
			if ( (*p) < 54u ) {
				if ( (*p) > 39u ) {
					if ( 40u <= (*p) && (*p) <= 51u )
						goto tr415;
				} else if ( (*p) >= 38u )
					goto tr19;
			} else if ( (*p) > 55u ) {
				if ( (*p) < 96u ) {
					if ( 56u <= (*p) && (*p) <= 59u )
						goto tr415;
				} else if ( (*p) > 111u ) {
					if ( 112u <= (*p) && (*p) <= 127u )
						goto tr426;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr415;
	} else if ( (*p) > 139u ) {
		if ( (*p) < 194u ) {
			if ( (*p) < 160u ) {
				if ( (*p) > 142u ) {
					if ( 154u <= (*p) && (*p) <= 157u )
						goto tr19;
				} else if ( (*p) >= 140u )
					goto tr19;
			} else if ( (*p) > 163u ) {
				if ( (*p) < 184u ) {
					if ( 176u <= (*p) && (*p) <= 183u )
						goto tr416;
				} else if ( (*p) > 191u ) {
					if ( 192u <= (*p) && (*p) <= 193u )
						goto tr432;
				} else
					goto tr417;
			} else
				goto tr431;
		} else if ( (*p) > 195u ) {
			if ( (*p) < 212u ) {
				if ( (*p) > 207u ) {
					if ( 208u <= (*p) && (*p) <= 211u )
						goto tr439;
				} else if ( (*p) >= 204u )
					goto tr19;
			} else if ( (*p) > 231u ) {
				if ( (*p) < 234u ) {
					if ( 232u <= (*p) && (*p) <= 233u )
						goto tr448;
				} else if ( (*p) > 241u ) {
					if ( 250u <= (*p) && (*p) <= 251u )
						goto tr19;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr19;
	} else
		goto tr415;
	goto tr421;
tr460:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st239;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 116u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
		case 180u: goto st9;
		case 212u: goto tr407;
		case 228u: goto tr407;
	}
	if ( (*p) < 112u ) {
		if ( (*p) < 48u ) {
			if ( (*p) <= 15u )
				goto tr0;
		} else if ( (*p) > 55u ) {
			if ( 64u <= (*p) && (*p) <= 79u )
				goto st7;
		} else
			goto tr0;
	} else if ( (*p) > 119u ) {
		if ( (*p) < 176u ) {
			if ( 128u <= (*p) && (*p) <= 143u )
				goto st3;
		} else if ( (*p) > 183u ) {
			if ( (*p) > 207u ) {
				if ( 240u <= (*p) && (*p) <= 247u )
					goto tr0;
			} else if ( (*p) >= 192u )
				goto tr0;
		} else
			goto st3;
	} else
		goto st7;
	goto tr19;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( (*p) == 224u )
		goto tr412;
	goto tr11;
tr412:
	{ }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st252;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	switch( (*p) ) {
		case 4u: goto tr416;
		case 5u: goto tr417;
		case 12u: goto tr416;
		case 13u: goto tr417;
		case 14u: goto tr19;
		case 15u: goto tr418;
		case 20u: goto tr416;
		case 21u: goto tr417;
		case 28u: goto tr416;
		case 29u: goto tr417;
		case 36u: goto tr416;
		case 37u: goto tr417;
		case 44u: goto tr416;
		case 45u: goto tr417;
		case 46u: goto tr419;
		case 47u: goto tr19;
		case 52u: goto tr416;
		case 53u: goto tr417;
		case 60u: goto tr416;
		case 61u: goto tr417;
		case 62u: goto tr420;
		case 63u: goto tr19;
		case 101u: goto tr422;
		case 102u: goto tr423;
		case 104u: goto tr417;
		case 105u: goto tr424;
		case 106u: goto tr416;
		case 107u: goto tr425;
		case 128u: goto tr425;
		case 129u: goto tr424;
		case 130u: goto tr19;
		case 131u: goto tr427;
		case 141u: goto tr428;
		case 143u: goto tr429;
		case 155u: goto tr430;
		case 168u: goto tr416;
		case 169u: goto tr417;
		case 196u: goto tr433;
		case 197u: goto tr434;
		case 198u: goto tr435;
		case 199u: goto tr436;
		case 200u: goto tr437;
		case 202u: goto tr438;
		case 216u: goto tr440;
		case 217u: goto tr441;
		case 218u: goto tr442;
		case 219u: goto tr443;
		case 220u: goto tr444;
		case 221u: goto tr445;
		case 222u: goto tr446;
		case 223u: goto tr447;
		case 235u: goto tr426;
		case 240u: goto tr449;
		case 242u: goto tr450;
		case 243u: goto tr451;
		case 246u: goto tr452;
		case 247u: goto tr453;
		case 254u: goto tr454;
		case 255u: goto tr461;
	}
	if ( (*p) < 132u ) {
		if ( (*p) < 32u ) {
			if ( (*p) < 8u ) {
				if ( (*p) > 3u ) {
					if ( 6u <= (*p) && (*p) <= 7u )
						goto tr19;
				} else
					goto tr415;
			} else if ( (*p) > 19u ) {
				if ( (*p) < 24u ) {
					if ( 22u <= (*p) && (*p) <= 23u )
						goto tr19;
				} else if ( (*p) > 27u ) {
					if ( 30u <= (*p) && (*p) <= 31u )
						goto tr19;
				} else
					goto tr415;
			} else
				goto tr415;
		} else if ( (*p) > 35u ) {
			if ( (*p) < 54u ) {
				if ( (*p) > 39u ) {
					if ( 40u <= (*p) && (*p) <= 51u )
						goto tr415;
				} else if ( (*p) >= 38u )
					goto tr19;
			} else if ( (*p) > 55u ) {
				if ( (*p) < 96u ) {
					if ( 56u <= (*p) && (*p) <= 59u )
						goto tr415;
				} else if ( (*p) > 111u ) {
					if ( 112u <= (*p) && (*p) <= 127u )
						goto tr426;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr415;
	} else if ( (*p) > 139u ) {
		if ( (*p) < 194u ) {
			if ( (*p) < 160u ) {
				if ( (*p) > 142u ) {
					if ( 154u <= (*p) && (*p) <= 157u )
						goto tr19;
				} else if ( (*p) >= 140u )
					goto tr19;
			} else if ( (*p) > 163u ) {
				if ( (*p) < 184u ) {
					if ( 176u <= (*p) && (*p) <= 183u )
						goto tr416;
				} else if ( (*p) > 191u ) {
					if ( 192u <= (*p) && (*p) <= 193u )
						goto tr432;
				} else
					goto tr417;
			} else
				goto tr431;
		} else if ( (*p) > 195u ) {
			if ( (*p) < 212u ) {
				if ( (*p) > 207u ) {
					if ( 208u <= (*p) && (*p) <= 211u )
						goto tr439;
				} else if ( (*p) >= 204u )
					goto tr19;
			} else if ( (*p) > 231u ) {
				if ( (*p) < 234u ) {
					if ( 232u <= (*p) && (*p) <= 233u )
						goto tr448;
				} else if ( (*p) > 241u ) {
					if ( 250u <= (*p) && (*p) <= 251u )
						goto tr19;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr19;
	} else
		goto tr415;
	goto tr421;
tr461:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 116u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
		case 180u: goto st9;
		case 213u: goto tr407;
		case 229u: goto tr407;
	}
	if ( (*p) < 112u ) {
		if ( (*p) < 48u ) {
			if ( (*p) <= 15u )
				goto tr0;
		} else if ( (*p) > 55u ) {
			if ( 64u <= (*p) && (*p) <= 79u )
				goto st7;
		} else
			goto tr0;
	} else if ( (*p) > 119u ) {
		if ( (*p) < 176u ) {
			if ( 128u <= (*p) && (*p) <= 143u )
				goto st3;
		} else if ( (*p) > 183u ) {
			if ( (*p) > 207u ) {
				if ( 240u <= (*p) && (*p) <= 247u )
					goto tr0;
			} else if ( (*p) >= 192u )
				goto tr0;
		} else
			goto st3;
	} else
		goto st7;
	goto tr19;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	if ( (*p) == 224u )
		goto tr413;
	goto tr11;
tr413:
	{ }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st253;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	switch( (*p) ) {
		case 4u: goto tr416;
		case 5u: goto tr417;
		case 12u: goto tr416;
		case 13u: goto tr417;
		case 14u: goto tr19;
		case 15u: goto tr418;
		case 20u: goto tr416;
		case 21u: goto tr417;
		case 28u: goto tr416;
		case 29u: goto tr417;
		case 36u: goto tr416;
		case 37u: goto tr417;
		case 44u: goto tr416;
		case 45u: goto tr417;
		case 46u: goto tr419;
		case 47u: goto tr19;
		case 52u: goto tr416;
		case 53u: goto tr417;
		case 60u: goto tr416;
		case 61u: goto tr417;
		case 62u: goto tr420;
		case 63u: goto tr19;
		case 101u: goto tr422;
		case 102u: goto tr423;
		case 104u: goto tr417;
		case 105u: goto tr424;
		case 106u: goto tr416;
		case 107u: goto tr425;
		case 128u: goto tr425;
		case 129u: goto tr424;
		case 130u: goto tr19;
		case 131u: goto tr427;
		case 141u: goto tr428;
		case 143u: goto tr429;
		case 155u: goto tr430;
		case 168u: goto tr416;
		case 169u: goto tr417;
		case 196u: goto tr433;
		case 197u: goto tr434;
		case 198u: goto tr435;
		case 199u: goto tr436;
		case 200u: goto tr437;
		case 202u: goto tr438;
		case 216u: goto tr440;
		case 217u: goto tr441;
		case 218u: goto tr442;
		case 219u: goto tr443;
		case 220u: goto tr444;
		case 221u: goto tr445;
		case 222u: goto tr446;
		case 223u: goto tr447;
		case 235u: goto tr426;
		case 240u: goto tr449;
		case 242u: goto tr450;
		case 243u: goto tr451;
		case 246u: goto tr452;
		case 247u: goto tr453;
		case 254u: goto tr454;
		case 255u: goto tr462;
	}
	if ( (*p) < 132u ) {
		if ( (*p) < 32u ) {
			if ( (*p) < 8u ) {
				if ( (*p) > 3u ) {
					if ( 6u <= (*p) && (*p) <= 7u )
						goto tr19;
				} else
					goto tr415;
			} else if ( (*p) > 19u ) {
				if ( (*p) < 24u ) {
					if ( 22u <= (*p) && (*p) <= 23u )
						goto tr19;
				} else if ( (*p) > 27u ) {
					if ( 30u <= (*p) && (*p) <= 31u )
						goto tr19;
				} else
					goto tr415;
			} else
				goto tr415;
		} else if ( (*p) > 35u ) {
			if ( (*p) < 54u ) {
				if ( (*p) > 39u ) {
					if ( 40u <= (*p) && (*p) <= 51u )
						goto tr415;
				} else if ( (*p) >= 38u )
					goto tr19;
			} else if ( (*p) > 55u ) {
				if ( (*p) < 96u ) {
					if ( 56u <= (*p) && (*p) <= 59u )
						goto tr415;
				} else if ( (*p) > 111u ) {
					if ( 112u <= (*p) && (*p) <= 127u )
						goto tr426;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr415;
	} else if ( (*p) > 139u ) {
		if ( (*p) < 194u ) {
			if ( (*p) < 160u ) {
				if ( (*p) > 142u ) {
					if ( 154u <= (*p) && (*p) <= 157u )
						goto tr19;
				} else if ( (*p) >= 140u )
					goto tr19;
			} else if ( (*p) > 163u ) {
				if ( (*p) < 184u ) {
					if ( 176u <= (*p) && (*p) <= 183u )
						goto tr416;
				} else if ( (*p) > 191u ) {
					if ( 192u <= (*p) && (*p) <= 193u )
						goto tr432;
				} else
					goto tr417;
			} else
				goto tr431;
		} else if ( (*p) > 195u ) {
			if ( (*p) < 212u ) {
				if ( (*p) > 207u ) {
					if ( 208u <= (*p) && (*p) <= 211u )
						goto tr439;
				} else if ( (*p) >= 204u )
					goto tr19;
			} else if ( (*p) > 231u ) {
				if ( (*p) < 234u ) {
					if ( 232u <= (*p) && (*p) <= 233u )
						goto tr448;
				} else if ( (*p) > 241u ) {
					if ( 250u <= (*p) && (*p) <= 251u )
						goto tr19;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr19;
	} else
		goto tr415;
	goto tr421;
tr462:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 116u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
		case 180u: goto st9;
		case 214u: goto tr407;
		case 230u: goto tr407;
	}
	if ( (*p) < 112u ) {
		if ( (*p) < 48u ) {
			if ( (*p) <= 15u )
				goto tr0;
		} else if ( (*p) > 55u ) {
			if ( 64u <= (*p) && (*p) <= 79u )
				goto st7;
		} else
			goto tr0;
	} else if ( (*p) > 119u ) {
		if ( (*p) < 176u ) {
			if ( 128u <= (*p) && (*p) <= 143u )
				goto st3;
		} else if ( (*p) > 183u ) {
			if ( (*p) > 207u ) {
				if ( 240u <= (*p) && (*p) <= 247u )
					goto tr0;
			} else if ( (*p) >= 192u )
				goto tr0;
		} else
			goto st3;
	} else
		goto st7;
	goto tr19;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
	if ( (*p) == 224u )
		goto tr414;
	goto tr11;
tr414:
	{ }
	{
       if (errors_detected) {
         process_error(begin, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       begin = p + 1;
     }
	goto st254;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	switch( (*p) ) {
		case 4u: goto tr416;
		case 5u: goto tr417;
		case 12u: goto tr416;
		case 13u: goto tr417;
		case 14u: goto tr19;
		case 15u: goto tr418;
		case 20u: goto tr416;
		case 21u: goto tr417;
		case 28u: goto tr416;
		case 29u: goto tr417;
		case 36u: goto tr416;
		case 37u: goto tr417;
		case 44u: goto tr416;
		case 45u: goto tr417;
		case 46u: goto tr419;
		case 47u: goto tr19;
		case 52u: goto tr416;
		case 53u: goto tr417;
		case 60u: goto tr416;
		case 61u: goto tr417;
		case 62u: goto tr420;
		case 63u: goto tr19;
		case 101u: goto tr422;
		case 102u: goto tr423;
		case 104u: goto tr417;
		case 105u: goto tr424;
		case 106u: goto tr416;
		case 107u: goto tr425;
		case 128u: goto tr425;
		case 129u: goto tr424;
		case 130u: goto tr19;
		case 131u: goto tr427;
		case 141u: goto tr428;
		case 143u: goto tr429;
		case 155u: goto tr430;
		case 168u: goto tr416;
		case 169u: goto tr417;
		case 196u: goto tr433;
		case 197u: goto tr434;
		case 198u: goto tr435;
		case 199u: goto tr436;
		case 200u: goto tr437;
		case 202u: goto tr438;
		case 216u: goto tr440;
		case 217u: goto tr441;
		case 218u: goto tr442;
		case 219u: goto tr443;
		case 220u: goto tr444;
		case 221u: goto tr445;
		case 222u: goto tr446;
		case 223u: goto tr447;
		case 235u: goto tr426;
		case 240u: goto tr449;
		case 242u: goto tr450;
		case 243u: goto tr451;
		case 246u: goto tr452;
		case 247u: goto tr453;
		case 254u: goto tr454;
		case 255u: goto tr463;
	}
	if ( (*p) < 132u ) {
		if ( (*p) < 32u ) {
			if ( (*p) < 8u ) {
				if ( (*p) > 3u ) {
					if ( 6u <= (*p) && (*p) <= 7u )
						goto tr19;
				} else
					goto tr415;
			} else if ( (*p) > 19u ) {
				if ( (*p) < 24u ) {
					if ( 22u <= (*p) && (*p) <= 23u )
						goto tr19;
				} else if ( (*p) > 27u ) {
					if ( 30u <= (*p) && (*p) <= 31u )
						goto tr19;
				} else
					goto tr415;
			} else
				goto tr415;
		} else if ( (*p) > 35u ) {
			if ( (*p) < 54u ) {
				if ( (*p) > 39u ) {
					if ( 40u <= (*p) && (*p) <= 51u )
						goto tr415;
				} else if ( (*p) >= 38u )
					goto tr19;
			} else if ( (*p) > 55u ) {
				if ( (*p) < 96u ) {
					if ( 56u <= (*p) && (*p) <= 59u )
						goto tr415;
				} else if ( (*p) > 111u ) {
					if ( 112u <= (*p) && (*p) <= 127u )
						goto tr426;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr415;
	} else if ( (*p) > 139u ) {
		if ( (*p) < 194u ) {
			if ( (*p) < 160u ) {
				if ( (*p) > 142u ) {
					if ( 154u <= (*p) && (*p) <= 157u )
						goto tr19;
				} else if ( (*p) >= 140u )
					goto tr19;
			} else if ( (*p) > 163u ) {
				if ( (*p) < 184u ) {
					if ( 176u <= (*p) && (*p) <= 183u )
						goto tr416;
				} else if ( (*p) > 191u ) {
					if ( 192u <= (*p) && (*p) <= 193u )
						goto tr432;
				} else
					goto tr417;
			} else
				goto tr431;
		} else if ( (*p) > 195u ) {
			if ( (*p) < 212u ) {
				if ( (*p) > 207u ) {
					if ( 208u <= (*p) && (*p) <= 211u )
						goto tr439;
				} else if ( (*p) >= 204u )
					goto tr19;
			} else if ( (*p) > 231u ) {
				if ( (*p) < 234u ) {
					if ( 232u <= (*p) && (*p) <= 233u )
						goto tr448;
				} else if ( (*p) > 241u ) {
					if ( 250u <= (*p) && (*p) <= 251u )
						goto tr19;
				} else
					goto tr19;
			} else
				goto tr19;
		} else
			goto tr19;
	} else
		goto tr415;
	goto tr421;
tr463:
	{
        begin = p;
        errors_detected = 0;
        BitmapSetBit(valid_targets, p - data);
     }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	switch( (*p) ) {
		case 4u: goto st2;
		case 5u: goto st3;
		case 12u: goto st2;
		case 13u: goto st3;
		case 52u: goto st2;
		case 53u: goto st3;
		case 68u: goto st8;
		case 76u: goto st8;
		case 116u: goto st8;
		case 132u: goto st9;
		case 140u: goto st9;
		case 180u: goto st9;
		case 215u: goto tr407;
		case 231u: goto tr407;
	}
	if ( (*p) < 112u ) {
		if ( (*p) < 48u ) {
			if ( (*p) <= 15u )
				goto tr0;
		} else if ( (*p) > 55u ) {
			if ( 64u <= (*p) && (*p) <= 79u )
				goto st7;
		} else
			goto tr0;
	} else if ( (*p) > 119u ) {
		if ( (*p) < 176u ) {
			if ( 128u <= (*p) && (*p) <= 143u )
				goto st3;
		} else if ( (*p) > 183u ) {
			if ( (*p) > 207u ) {
				if ( 240u <= (*p) && (*p) <= 247u )
					goto tr0;
			} else if ( (*p) >= 192u )
				goto tr0;
		} else
			goto st3;
	} else
		goto st7;
	goto tr19;
	}
	_test_eof246: cs = 246; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof247: cs = 247; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof199: cs = 199; goto _test_eof; 
	_test_eof200: cs = 200; goto _test_eof; 
	_test_eof201: cs = 201; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof213: cs = 213; goto _test_eof; 
	_test_eof214: cs = 214; goto _test_eof; 
	_test_eof215: cs = 215; goto _test_eof; 
	_test_eof216: cs = 216; goto _test_eof; 
	_test_eof217: cs = 217; goto _test_eof; 
	_test_eof218: cs = 218; goto _test_eof; 
	_test_eof219: cs = 219; goto _test_eof; 
	_test_eof220: cs = 220; goto _test_eof; 
	_test_eof221: cs = 221; goto _test_eof; 
	_test_eof222: cs = 222; goto _test_eof; 
	_test_eof223: cs = 223; goto _test_eof; 
	_test_eof224: cs = 224; goto _test_eof; 
	_test_eof225: cs = 225; goto _test_eof; 
	_test_eof226: cs = 226; goto _test_eof; 
	_test_eof227: cs = 227; goto _test_eof; 
	_test_eof228: cs = 228; goto _test_eof; 
	_test_eof229: cs = 229; goto _test_eof; 
	_test_eof230: cs = 230; goto _test_eof; 
	_test_eof231: cs = 231; goto _test_eof; 
	_test_eof232: cs = 232; goto _test_eof; 
	_test_eof248: cs = 248; goto _test_eof; 
	_test_eof233: cs = 233; goto _test_eof; 
	_test_eof234: cs = 234; goto _test_eof; 
	_test_eof249: cs = 249; goto _test_eof; 
	_test_eof235: cs = 235; goto _test_eof; 
	_test_eof236: cs = 236; goto _test_eof; 
	_test_eof250: cs = 250; goto _test_eof; 
	_test_eof237: cs = 237; goto _test_eof; 
	_test_eof238: cs = 238; goto _test_eof; 
	_test_eof251: cs = 251; goto _test_eof; 
	_test_eof239: cs = 239; goto _test_eof; 
	_test_eof240: cs = 240; goto _test_eof; 
	_test_eof252: cs = 252; goto _test_eof; 
	_test_eof241: cs = 241; goto _test_eof; 
	_test_eof242: cs = 242; goto _test_eof; 
	_test_eof253: cs = 253; goto _test_eof; 
	_test_eof243: cs = 243; goto _test_eof; 
	_test_eof244: cs = 244; goto _test_eof; 
	_test_eof254: cs = 254; goto _test_eof; 
	_test_eof245: cs = 245; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 1: 
	case 2: 
	case 3: 
	case 4: 
	case 5: 
	case 6: 
	case 7: 
	case 8: 
	case 9: 
	case 10: 
	case 11: 
	case 12: 
	case 13: 
	case 14: 
	case 15: 
	case 16: 
	case 17: 
	case 18: 
	case 19: 
	case 20: 
	case 21: 
	case 22: 
	case 23: 
	case 24: 
	case 25: 
	case 26: 
	case 27: 
	case 28: 
	case 29: 
	case 30: 
	case 31: 
	case 32: 
	case 33: 
	case 34: 
	case 35: 
	case 36: 
	case 37: 
	case 38: 
	case 39: 
	case 40: 
	case 41: 
	case 42: 
	case 43: 
	case 44: 
	case 45: 
	case 46: 
	case 47: 
	case 48: 
	case 49: 
	case 50: 
	case 51: 
	case 52: 
	case 53: 
	case 54: 
	case 55: 
	case 56: 
	case 57: 
	case 58: 
	case 59: 
	case 60: 
	case 61: 
	case 62: 
	case 63: 
	case 64: 
	case 65: 
	case 66: 
	case 67: 
	case 68: 
	case 69: 
	case 70: 
	case 71: 
	case 72: 
	case 73: 
	case 74: 
	case 75: 
	case 76: 
	case 77: 
	case 78: 
	case 79: 
	case 80: 
	case 81: 
	case 82: 
	case 83: 
	case 84: 
	case 85: 
	case 86: 
	case 87: 
	case 88: 
	case 89: 
	case 90: 
	case 91: 
	case 92: 
	case 93: 
	case 94: 
	case 95: 
	case 96: 
	case 97: 
	case 98: 
	case 99: 
	case 100: 
	case 101: 
	case 102: 
	case 103: 
	case 104: 
	case 105: 
	case 106: 
	case 107: 
	case 108: 
	case 109: 
	case 110: 
	case 111: 
	case 112: 
	case 113: 
	case 114: 
	case 115: 
	case 116: 
	case 117: 
	case 118: 
	case 119: 
	case 120: 
	case 121: 
	case 122: 
	case 123: 
	case 124: 
	case 125: 
	case 126: 
	case 127: 
	case 128: 
	case 129: 
	case 130: 
	case 131: 
	case 132: 
	case 133: 
	case 134: 
	case 135: 
	case 136: 
	case 137: 
	case 138: 
	case 139: 
	case 140: 
	case 141: 
	case 142: 
	case 143: 
	case 144: 
	case 145: 
	case 146: 
	case 147: 
	case 148: 
	case 149: 
	case 150: 
	case 151: 
	case 152: 
	case 153: 
	case 154: 
	case 155: 
	case 156: 
	case 157: 
	case 158: 
	case 159: 
	case 160: 
	case 161: 
	case 162: 
	case 163: 
	case 164: 
	case 165: 
	case 166: 
	case 167: 
	case 168: 
	case 169: 
	case 170: 
	case 171: 
	case 172: 
	case 173: 
	case 174: 
	case 175: 
	case 176: 
	case 177: 
	case 178: 
	case 179: 
	case 180: 
	case 181: 
	case 182: 
	case 183: 
	case 184: 
	case 185: 
	case 186: 
	case 187: 
	case 188: 
	case 189: 
	case 190: 
	case 191: 
	case 192: 
	case 193: 
	case 194: 
	case 195: 
	case 196: 
	case 197: 
	case 198: 
	case 199: 
	case 200: 
	case 201: 
	case 202: 
	case 203: 
	case 204: 
	case 205: 
	case 206: 
	case 207: 
	case 208: 
	case 209: 
	case 210: 
	case 211: 
	case 212: 
	case 213: 
	case 214: 
	case 215: 
	case 216: 
	case 217: 
	case 218: 
	case 219: 
	case 220: 
	case 221: 
	case 222: 
	case 223: 
	case 224: 
	case 225: 
	case 226: 
	case 227: 
	case 228: 
	case 229: 
	case 230: 
	case 231: 
	case 232: 
	case 233: 
	case 234: 
	case 235: 
	case 236: 
	case 237: 
	case 238: 
	case 239: 
	case 240: 
	case 241: 
	case 242: 
	case 243: 
	case 244: 
	case 245: 
	{
        process_error(begin, UNRECOGNIZED_INSTRUCTION, userdata);
        result = 1;
        goto error_detected;
    }
	break;
	}
	}

	_out: {}
	}

  }

  for (i = 0; i < size / 32; i++) {
    uint32_t jump_dest_mask = ((uint32_t *) jump_dests)[i];
    uint32_t valid_target_mask = ((uint32_t *) valid_targets)[i];
    if ((jump_dest_mask & ~valid_target_mask) != 0) {
      process_error(data + i * 32, BAD_JUMP_TARGET, userdata);
      result = 1;
      break;
    }
  }

error_detected:
  return result;
}