/*
 * Copyright 2008, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
  Interface test for simple rpc.  Try out parameter passing.
*/

#include <stdio.h>
#include <string.h>
#include <nacl/nacl_srpc.h>

/*
 *  First, tests for scalar argument passing and return.
 */
int BoolMethod(NaClSrpcChannel *channel,
               NaClSrpcArg **in_args,
               NaClSrpcArg **out_args);
int DoubleMethod(NaClSrpcChannel *channel,
                 NaClSrpcArg **in_args,
                 NaClSrpcArg **out_args);
int IntMethod(NaClSrpcChannel *channel,
              NaClSrpcArg **in_args,
              NaClSrpcArg **out_args);
int StringMethod(NaClSrpcChannel *channel,
                 NaClSrpcArg **in_args,
                 NaClSrpcArg **out_args);

NACL_SRPC_METHOD("bool:b:b", BoolMethod);
NACL_SRPC_METHOD("double:d:d", DoubleMethod);
NACL_SRPC_METHOD("int:i:i", IntMethod);
NACL_SRPC_METHOD("string:s:i", StringMethod);

/*
 *  The test for bool inverts the input and returns it.
 */
int BoolMethod(NaClSrpcChannel *channel,
               NaClSrpcArg **in_args,
               NaClSrpcArg **out_args) {
  out_args[0]->u.bval = !in_args[0]->u.bval;
  return NACL_SRPC_RESULT_OK;
}

/*
 *  The test for double negates the input and returns it.
 */
int DoubleMethod(NaClSrpcChannel *channel,
                 NaClSrpcArg **in_args,
                 NaClSrpcArg **out_args) {
  out_args[0]->u.dval = -in_args[0]->u.dval;
  return NACL_SRPC_RESULT_OK;
}

/*
 *  The test for int negates the input and returns it.
 */
int IntMethod(NaClSrpcChannel *channel,
              NaClSrpcArg **in_args,
              NaClSrpcArg **out_args) {
  out_args[0]->u.ival = -in_args[0]->u.ival;
  return NACL_SRPC_RESULT_OK;
}

/*
 *  The test for string returns the length of the string.
 */
int StringMethod(NaClSrpcChannel *channel,
                 NaClSrpcArg **in_args,
                 NaClSrpcArg **out_args) {
  out_args[0]->u.ival = strlen(in_args[0]->u.sval);
  return NACL_SRPC_RESULT_OK;
}

/*
 *  Second, tests for array argument passing and return.
 *  All the array methods reverse their input arrays and return them.
 *  If the counts don't match, return an error.
 */
int CharArrayMethod(NaClSrpcChannel *channel,
                    NaClSrpcArg **in_args,
                    NaClSrpcArg **out_args);
int DoubleArrayMethod(NaClSrpcChannel *channel,
                      NaClSrpcArg **in_args,
                      NaClSrpcArg **out_args);
int IntArrayMethod(NaClSrpcChannel *channel,
                   NaClSrpcArg **in_args,
                   NaClSrpcArg **out_args);

NACL_SRPC_METHOD("char_array:C:C", CharArrayMethod);
NACL_SRPC_METHOD("double_array:D:D", DoubleArrayMethod);
NACL_SRPC_METHOD("int_array:I:I", IntArrayMethod);

int CharArrayMethod(NaClSrpcChannel *channel,
                    NaClSrpcArg **in_args,
                    NaClSrpcArg **out_args) {
  int i, length;
  if (out_args[0]->u.caval.count != in_args[0]->u.caval.count) {
    printf("Mismatch: %d %d\n", (int) in_args[0]->u.caval.count,
           (int) out_args[0]->u.caval.count);
    return NACL_SRPC_RESULT_APP_ERROR;
  }
  length = in_args[0]->u.caval.count;
  for (i = 0; i < length; i++) {
    out_args[0]->u.caval.carr[length-i-1] = in_args[0]->u.caval.carr[i];
  }
  return NACL_SRPC_RESULT_OK;
}

int DoubleArrayMethod(NaClSrpcChannel *channel,
                      NaClSrpcArg **in_args,
                      NaClSrpcArg **out_args) {
  int i, length;
  if (out_args[0]->u.daval.count != in_args[0]->u.daval.count) {
    return NACL_SRPC_RESULT_APP_ERROR;
  }
  length = in_args[0]->u.daval.count;
  for (i = 0; i < length; i++) {
    out_args[0]->u.daval.darr[length-i-1] = in_args[0]->u.daval.darr[i];
  }
  return NACL_SRPC_RESULT_OK;
}

int IntArrayMethod(NaClSrpcChannel *channel,
                   NaClSrpcArg **in_args,
                   NaClSrpcArg **out_args) {
  int i, length;
  if (out_args[0]->u.iaval.count != in_args[0]->u.iaval.count) {
    return NACL_SRPC_RESULT_APP_ERROR;
  }
  length = in_args[0]->u.iaval.count;
  for (i = 0; i < length; i++) {
    out_args[0]->u.iaval.iarr[length-i-1] = in_args[0]->u.iaval.iarr[i];
  }
  return NACL_SRPC_RESULT_OK;
}

/*
 * Finally, a null RPC to test throughput and latency.
 */
int NullMethod(NaClSrpcChannel *channel,
               NaClSrpcArg **in_args,
               NaClSrpcArg **out_args);

NACL_SRPC_METHOD("null_method::", NullMethod);

int NullMethod(NaClSrpcChannel *channel,
               NaClSrpcArg **in_args,
               NaClSrpcArg **out_args) {
  return NACL_SRPC_RESULT_OK;
}

/*
 * Experimental: a method to return a string.
 */

int ReturnStringMethod(NaClSrpcChannel *channel,
                       NaClSrpcArg **in_args,
                       NaClSrpcArg **out_args);

NACL_SRPC_METHOD("stringret_method:i:s", ReturnStringMethod);

int ReturnStringMethod(NaClSrpcChannel *channel,
                       NaClSrpcArg **in_args,
                       NaClSrpcArg **out_args) {
  static char string[] = "Ich weiss nicht, was soll es bedeuten"
                         "Dass ich so traurig bin,"
                         "Ein Maerchen aus uralten Zeiten,"
                         "Das kommt mir nicht aus dem Sinn."
                         "Die Luft ist kuehl und es dunkelt,"
                         "Und ruhig fliesst der Rhein;"
                         "Der Gipfel des Berges funkelt,"
                         "Im Abendsonnenschein."
                         "Die schoenste Jungfrau sitzet"
                         "Dort oben wunderbar,"
                         "Ihr gold'nes Geschmeide blitzet,"
                         "Sie kaemmt ihr goldenes Haar,"
                         "Sie kaemmt es mit goldenem Kamme,"
                         "Und singt ein Lied dabei;"
                         "Das hat eine wundersame,"
                         "Gewalt'ge Melodei.";
  out_args[0]->u.sval = strdup(string + in_args[0]->u.ival);
  return NACL_SRPC_RESULT_OK;
}

/*
 * Experimental: a method to return a file handle.
 */

int ReturnHandleMethod(NaClSrpcChannel *channel,
                       NaClSrpcArg **in_args,
                       NaClSrpcArg **out_args);

NACL_SRPC_METHOD("outh_method::h", ReturnHandleMethod);

int ReturnHandleMethod(NaClSrpcChannel *channel,
                       NaClSrpcArg **in_args,
                       NaClSrpcArg **out_args) {
  out_args[0]->u.hval = 2; /* stderr */
  return NACL_SRPC_RESULT_OK;
}
