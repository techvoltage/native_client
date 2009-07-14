/*
 * Copyright 2009, Google Inc.
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

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "native_client/src/trusted/validator_x86/ncop_exps.h"
#include "native_client/src/trusted/validator_x86/nc_inst_state.h"
#include "native_client/src/include/portability.h"
#include "native_client/src/shared/utils/types.h"

/* To turn on debugging of instruction decoding, change value of
 * DEBUGGING to 1.
 */
#define DEBUGGING 0

#if DEBUGGING
/* Defines to execute statement(s) s if in debug mode. */
#define DEBUG(s) s
#else
/* Defines to not include statement(s) s if not in debugging mode. */
#define DEBUG(s) do { if (0) { s; } } while(0)
#endif

/* The print names of valid ExprNodeKind values. */
static const char* const g_ExprNodeKindName[ExprNodeKindEnumSize] = {
  "UndefinedExp",
  "ExprRegister",
  "OperandReference",
  "ExprConstant",
  "ExprSegmentAddress",
  "ExprMemOffset",
};

const char* ExprNodeKindName(ExprNodeKind kind) {
  return g_ExprNodeKindName[kind];
}

/* The number of kids each valid ExprNodeKind has. */
static const int g_ExprNodeKindRank[ExprNodeKindEnumSize] = {
  0,
  0,
  1,
  0,
  2,
  4
};

int ExprNodeKindRank(ExprNodeKind kind) {
  return g_ExprNodeKindRank[kind];
}

/* The print names of valid ExprNodeFlagEnum values. */
static const char* const g_ExprNodeFlagName[ExprNodeFlagEnumSize] = {
  "ExprSet",
  "ExprUsed",
  "ExprSize8",
  "ExprSize16",
  "ExprSize32",
  "ExprSize64",
  "EpxrHexConstant",
  "ExprIntConstant",
};

const char* ExprNodeFlagName(ExprNodeFlagEnum flag) {
  return g_ExprNodeFlagName[flag];
}

/* Returns the constant defined by the given node. */
static INLINE uint32_t GetNodeConstant(ExprNode* node) {
  assert(node->kind == ExprConstant);
  return node->value;
}

/* Returns the constant defined by the indexed node in the vector of nodes. */
static INLINE uint32_t GetNodeVectorConstant(ExprNodeVector* vector, int node) {
  return GetNodeConstant(&vector->node[node]);
}

/* Returns the register defined by the given node. */
static INLINE OperandKind GetNodeRegister(ExprNode* node) {
  assert(node->kind == ExprRegister);
  return (OperandKind) node->value;
}

/* Returns the name of the register defined by the indexed node in the
 * vector of nodes.
 */
static INLINE OperandKind GetNodeVectorRegister(ExprNodeVector* vector,
                                                int node) {
  return GetNodeRegister(&vector->node[node]);
}

static int PrintDisassembledExp(FILE* file,
                                ExprNodeVector* vector,
                                uint32_t index);

/* Print the characters in the given string using lower case. */
static void PrintLower(FILE* file, char* str) {
  while (*str) {
    putc(tolower(*str), file);
    ++str;
  }
}

/* Print out the given (constant) expression node to the given file. */
static void PrintDisassembledConst(FILE* file, ExprNode* node) {
  assert(node->kind == ExprConstant);
  if (node->flags & ExprFlag(ExprHexConstant)) {
    if (node->flags & ExprFlag(ExprSize8)) {
      fprintf(file, "0x%"PRIx8, (uint8_t) node->value);
    } else if (node->flags & ExprFlag(ExprSize16)) {
      fprintf(file, "0x%"PRIx16, (uint16_t) node->value);
    } else {
      fprintf(file, "0x%"PRIx32, node->value);
    }
  } else {
    if (node->flags & ExprFlag(ExprSize8)) {
      fprintf(file, "%"PRId8, (int8_t) node->value);
    } else if (node->flags & ExprFlag(ExprSize16)) {
      fprintf(file, "%"PRId16, (int16_t) node->value);
    } else {
      fprintf(file, "%"PRId32, (int32_t) node->value);
    }
  }
}

/* Print out the disassembled representation of the given register
 * to the given file.
 */
static void PrintDisassembledRegKind(FILE* file, OperandKind reg) {
  const char* name = OperandKindName(reg);
  char* str = strstr(name, "Reg");
  putc('%', file);
  PrintLower(file, str == NULL ? (char*) name : str + strlen("Reg"));
}

static INLINE void PrintDisassembledReg(FILE* file, ExprNode* node) {
  PrintDisassembledRegKind(file, GetNodeRegister(node));
}

void PrintExprNodeVector(FILE* file, ExprNodeVector* vector) {
  uint32_t i;
  fprintf(file, "ExprNodeVector[%d] = {\n", vector->number_expr_nodes);
  for (i = 0; i < vector->number_expr_nodes; i++) {
    ExprNode* node = &vector->node[i];
    fprintf(file, "  { %s[%d] , ",
            ExprNodeKindName(node->kind),
            ExprNodeKindRank(node->kind));
    switch (node->kind) {
    case ExprRegister:
      PrintDisassembledReg(file, node);
      break;
    case ExprConstant:
      PrintDisassembledConst(file, node);
      break;
    default:
      fprintf(file, "%"PRIu32, node->value);
      break;
    }
    fprintf(file, ", ");
    if (node->flags == 0) {
      fprintf(file, "0");
    } else {
      ExprNodeFlagEnum f;
      Bool is_first = TRUE;
      for (f = 0; f < ExprNodeFlagEnumSize; f++) {
        if (node->flags & ExprFlag(f)) {
          if (is_first) {
            is_first = FALSE;
          } else {
            fprintf(file, " | ");
          }
          fprintf(file, "%s", ExprNodeFlagName(f));
        }
      }
    }
    fprintf(file, " },\n");
  }
  fprintf(file, "};\n");
}

/* Print out the given (memory offset) expression node to the given file.
 * Returns the index of the node following the given (indexed) memory offset.
 */
static int PrintDisassembledMemOffset(FILE* file,
                                      ExprNodeVector* vector,
                                      int index) {
  int r1_index = index + 1;
  int r2_index = r1_index + ExprNodeWidth(vector, r1_index);
  int scale_index = r2_index + ExprNodeWidth(vector, r2_index);
  int disp_index = scale_index + ExprNodeWidth(vector, scale_index);
  OperandKind r1 = GetNodeVectorRegister(vector, r1_index);
  OperandKind r2 = GetNodeVectorRegister(vector, r2_index);
  int scale = (int) GetNodeVectorConstant(vector, scale_index);
  uint32_t disp = GetNodeVectorConstant(vector, disp_index);
  assert(ExprMemOffset == vector->node[index].kind);
  fprintf(file,"[");
  if (r1 != RegUnknown) {
    PrintDisassembledRegKind(file, r1);
    if (r2 != RegUnknown || disp != 0) {
      fprintf(file, "+");
    }
  }
  if (r2 != RegUnknown) {
    PrintDisassembledRegKind(file, r2);
    fprintf(file, "*%d", scale);
    if (disp != 0) {
      fprintf(file, "+");
    }
  }
  if (disp != 0) {
    /* Recurse to handle print using format flags. */
    PrintDisassembledExp(file, vector, disp_index);
  }
  fprintf(file, "]");
  return disp_index + ExprNodeWidth(vector, disp_index);
}

/* Print out the given (segment address) expression node to the
 * given file. Returns the index of the node following the
 * given (indexed) segment address.
 */
static int PrintDisassembledSegmentAddr(FILE* file,
                                        ExprNodeVector* vector,
                                        int index) {
  assert(ExprSegmentAddress == vector->node[index].kind);
  index = PrintDisassembledExp(file, vector, index + 1);
  if (vector->node[index].kind != ExprMemOffset) {
    fprintf(file, ":");
  }
  return PrintDisassembledExp(file, vector, index);
}

/* Print out the given expression node to the given file.
 * Returns the index of the node following the given indexed
 * expression.
 */
static int PrintDisassembledExp(FILE* file,
                                ExprNodeVector* vector,
                                uint32_t index) {
  ExprNode* node;
  assert(index < vector->number_expr_nodes);
  node = &vector->node[index];
  switch (node->kind) {
  default:
    fprintf(file, "undefined");
    return index + 1;
  case ExprRegister:
    PrintDisassembledReg(file, node);
    return index + 1;
  case OperandReference:
    return PrintDisassembledExp(file, vector, index+1);
  case ExprConstant:
    PrintDisassembledConst(file, node);
    return index + 1;
  case ExprSegmentAddress:
    return PrintDisassembledSegmentAddr(file, vector, index);
  case ExprMemOffset:
    return PrintDisassembledMemOffset(file, vector, index);
  }
}

/* Print the given instruction opcode of the give state, to the
 * given file.
 */
static void PrintDisassembled(FILE* file,
                              NcInstState* state,
                              Opcode* opcode) {
  uint32_t tree_index = 0;
  Bool is_first = TRUE;
  ExprNodeVector* vector = NcInstStateNodeVector(state);
  PrintLower(file, (char*) InstMnemonicName(opcode->name));
  while (tree_index < vector->number_expr_nodes) {
    if (is_first) {
      putc(' ', file);
      is_first = FALSE;
    } else {
      fprintf(file, ", ");
    }
    tree_index = PrintDisassembledExp(file, vector, tree_index);
  }
}

void PrintNcInstStateInstruction(FILE* file, NcInstState* state) {
  int i;
  Opcode* opcode;

  /* Print out the address and the opcode bytes. */
  int length = NcInstStateLength(state);
  DEBUG(PrintOpcode(stdout, NcInstStateOpcode(state)));
  DEBUG(PrintExprNodeVector(stdout, NcInstStateNodeVector(state)));
  fprintf(file, "%"PRIxPcAddressAll": ", NcInstStateVpc(state));
  for (i = 0; i < length; ++i) {
      fprintf(file, "%02"PRIx8" ", NcInstStateByte(state, i));
  }
  for (i = length; i < MAX_BYTES_PER_X86_INSTRUCTION; ++i) {
    fprintf(file, "   ");
  }

  /* Print out the assembly instruction it disassembles to. */
  opcode = NcInstStateOpcode(state);
  PrintDisassembled(file, state, opcode);

  /* Print out if not allowed in native client (as a comment). */
  if (! NcInstStateIsNaclLegal(state)) {
    fprintf(file, "; *NACL Disallows!*");
  }
  putc('\n', file);
}

int ExprNodeWidth(ExprNodeVector* vector, int node) {
  int i;
  int count = 1;
  int num_kids = ExprNodeKindRank(vector->node[node].kind);
  for (i = 0; i < num_kids; i++) {
    count += ExprNodeWidth(vector, node + count);
  }
  return count;
}

int GetExprNodeKidIndex(ExprNodeVector* vector, int node, int kid) {
  node++;
  while (kid-- > 0) {
    node += ExprNodeWidth(vector, node);
  }
  return node;
}
