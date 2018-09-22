/** @file opcode.cpp \brief Brizo opcode helper functions. */
// $Workfile: opcode.cpp $
//
// Brizo Disassembler by DEATH, 2003-2004
//
// Opcode class.
//
// $Author: Death $
// $Revision: 10 $
// $Date: 11/22/04 1:54 $
//
// $NoKeywords: $
//
#include "stdafx.h"
#include <brizo/opcode.h>

namespace Brizo_DE20041115
{

std::size_t Opcode::GetOperandCount(void) const
{
    std::size_t i = 0;

    do {
        if (operands[i].reg == REG_NONE && operands[i].amode == AM_NONE && operands[i].otype == OT_NONE)
            break;
        i++;
    } while (i < 3);

    return i;
}

bool Opcode::IsStringOperation(void) const
{
    static const OpcodeType StringOpsTable[] = {
        O_CMPS, O_STOS, O_MOVS, O_INS, O_OUTS, O_SCAS
    };
    static const OpcodeType *StringOpsTableEnd = StringOpsTable + (sizeof(StringOpsTable) / sizeof(OpcodeType));

    const OpcodeType *found = std::find(StringOpsTable, StringOpsTableEnd, op);
    return found != StringOpsTableEnd;
}

bool Opcode::IsJccOperation(void) const
{
    static const OpcodeType JccOpsTable[] = {
        O_JO, O_JNO, O_JB, O_JNB, O_JZ, O_JNZ, O_JBE, O_JNBE, O_JS, O_JNS, O_JP,
        O_JNP, O_JL, O_JNL, O_JLE, O_JNLE, O_JCXZ, O_JMP
    };
    static const OpcodeType *JccOpsTableEnd = JccOpsTable + (sizeof(JccOpsTable) / sizeof(OpcodeType));

    const OpcodeType *found = std::find(JccOpsTable, JccOpsTableEnd, op);
    return found != JccOpsTableEnd;
}

}
