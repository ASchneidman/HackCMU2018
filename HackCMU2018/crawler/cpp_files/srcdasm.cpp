/** @file dasm.cpp \brief Brizo default disassembler implementation. */
// $Workfile: dasm.cpp $
//
// Brizo Disassembler by DEATH, 2003-2004
//
// Disassembler with a default formatter implementation.
//
// $Author: Death $
// $Revision: 25 $
// $Date: 11/22/04 21:32 $
//
// $NoKeywords: $
//
#include "stdafx.h"
#include <brizo/dasm.h>

#pragma warning(disable:4355) // 'this' : used in base member initializer list

using namespace Brizo_DE20041115;

namespace {

const char *GetPrefixText(const Prefix & prefix);
const char **GetRegisterTextTable(DecodeMode dm);
const char *GetOpcodeText(OpcodeType op, DecodeMode dm);
std::string FormatDisplacement(unsigned int disp, DisplacementType dt);
void FormatOperandType(std::string & text, OperandType ot, DecodeMode dm);
bool FormatOperandTypeSpecialCases(OpcodeType op);
std::string FormatSIB(unsigned int ma, const SIB & sib, unsigned int disp);

}

namespace Brizo_DE20041115
{

extern const char *MemAddr1TextTable[];
extern const char *MemAddr2TextTable[];
extern const char *MemAddr3TextTable[];
extern const char *OpcodeTextTable[];
extern const char *PrefixTextTable[];
extern const char *RegisterTextTable16[];
extern const char *RegisterTextTable32[];

/// Brizo default disassembler implementation
struct Disassembler::Impl
{
    typedef std::vector<std::string> OperandStrings; ///< A vector of operand strings

    Impl(Disassembler *self_)
    : self(self_)
    {
    }

    Impl(Disassembler *self_, const Impl & other)
    : self(self_)
    , prefix(other.prefix)
    , opcode(other.opcode)
    , operands(other.operands)
    {
    }

    /// Format a single prefix in the opcode matching the prefix group specified
    /// @param text The output prefix text
    /// @param group Format a prefix from this group
    /// @return true if a prefix was found and formatted, false if not
    bool FormatPrefix(std::string & text, PrefixGroup group) const;

public:
    Disassembler *self; ///< A pointer to the Disassembler containing this Disassembler::Impl instance
    std::string prefix; ///< The formatted instruction's prefix text (before opcode mnemonic)
    std::string opcode; ///< The formatted instruction's opcode text
    OperandStrings operands; ///< The formatted instruction's operand text strings
};

Disassembler::Disassembler()
: m_pimpl(new Impl(this))
{
}

Disassembler::Disassembler(const Disassembler & other)
: Decoder(other)
, m_pimpl(new Impl(this, *other.m_pimpl))
{
}

Disassembler::~Disassembler()
{
}

Disassembler & Disassembler::operator= (const Disassembler & rhs)
{
    if (this != &rhs) {
        Disassembler temp(rhs);
        std::swap(temp.m_pimpl, m_pimpl);
        std::swap(temp.m_pimpl->self, m_pimpl->self);
    }
    return *this;
}

void Disassembler::Format(unsigned int address)
{
    m_pimpl->prefix.erase();
    m_pimpl->opcode.erase();
    m_pimpl->operands.clear();

    if (CanFormat() == false)
        return;

    // Prefix formatting
    m_pimpl->FormatPrefix(m_pimpl->prefix, PG_LOCK_REP);

    // Opcode mnemonic formatting
    m_pimpl->opcode = GetOpcodeText(GetOpcodeType(), GetOperandDecodeMode());

    // Operand values formatting
    const char **RegisterTextTable = GetRegisterTextTable(GetOperandDecodeMode());
    char buf[64];
    std::size_t operandCount = GetOperandCount();
    for (std::size_t i = 0; i < operandCount; i++) {
        const OperandValue & value = GetOperandValue(i);
        std::string text;

        switch (value.type) {
            case OVT_REGISTER:
                text += RegisterTextTable[value.Value.reg];
                break;
            case OVT_MEM_ADDR_1:
                if (!(i == 0 && operandCount > 1 && GetOperandValue(1).type == OVT_REGISTER)) {
                    if (!(i == 1 && GetOperandValue(0).type == OVT_REGISTER) || FormatOperandTypeSpecialCases(GetOpcodeType())) {
                        FormatOperandType(text, GetOperandType(i), GetOperandDecodeMode());
                    }
                }
                m_pimpl->FormatPrefix(text, PG_SEG_BRANCH);
                switch (value.Value.ma.ma1) {
                    case MA1_DISP16:
                        sprintf(buf, "[%04X]", value.Value.ma.disp);
                        text += buf;
                        break;
                    case MA1_DISP32:
                        sprintf(buf, "[%08X]", value.Value.ma.disp);
                        text += buf;
                        break;
                    case MA1_SIB:
                        text += FormatSIB(1, value.Value.ma.sib, value.Value.ma.disp);
                        break;
                    default:
                        text += MemAddr1TextTable[value.Value.ma.ma1];
                        break;
                }
                break;
            case OVT_MEM_ADDR_2:
                {
                if (!(i == 0 && operandCount > 1 && GetOperandValue(1).type == OVT_REGISTER)) {
                    if (!(i == 1 && GetOperandValue(0).type == OVT_REGISTER) || FormatOperandTypeSpecialCases(GetOpcodeType())) {
                        FormatOperandType(text, GetOperandType(i), GetOperandDecodeMode());
                    }
                }
                m_pimpl->FormatPrefix(text, PG_SEG_BRANCH);
                if (value.Value.ma.ma2 == MA2_SIB_DISP8) {
                    text += FormatSIB(2, value.Value.ma.sib, value.Value.ma.disp);
                } else {
                    sprintf(buf, MemAddr2TextTable[value.Value.ma.ma2], FormatDisplacement(value.Value.ma.disp, DT_8BIT).c_str());
                    text += buf;
                }
                }
                break;
            case OVT_MEM_ADDR_3:
                {
                if (!(i == 0 && operandCount > 1 && GetOperandValue(1).type == OVT_REGISTER)) {
                    if (!(i == 1 && GetOperandValue(0).type == OVT_REGISTER) | FormatOperandTypeSpecialCases(GetOpcodeType())) {
                        FormatOperandType(text, GetOperandType(i), GetOperandDecodeMode());
                    }
                }
                m_pimpl->FormatPrefix(text, PG_SEG_BRANCH);
                if (value.Value.ma.ma3 == MA3_SIB_DISP32) {
                    text += FormatSIB(3, value.Value.ma.sib, value.Value.ma.disp);
                } else {
                    sprintf(buf, MemAddr3TextTable[value.Value.ma.ma3], FormatDisplacement(value.Value.ma.disp, GetAddressDecodeMode() == DM_16BIT ? DT_16BIT : DT_32BIT).c_str());
                    text += buf;
                }
                }
                break;
            case OVT_DIRECT:
                if (GetAddressDecodeMode() == DM_16BIT) {
                    sprintf(buf, "%04X:%04X", value.Value.dir.seg, value.Value.dir.off);
                    text += buf;
                } else {
                    sprintf(buf, "%04X:%08X", value.Value.dir.seg, value.Value.dir.off);
                    text += buf;
                }
                break;
            case OVT_OFF:
                m_pimpl->FormatPrefix(text, PG_SEG_BRANCH);
                if (GetAddressDecodeMode() == DM_16BIT) {
                    sprintf(buf, "[%04X]", (unsigned short)value.Value.off);
                    text += buf;
                } else {
                    sprintf(buf, "[%08X]", value.Value.off);
                    text += buf;
                }
                break;
            case OVT_REL_OFF:
                {
                m_pimpl->FormatPrefix(text, PG_SEG_BRANCH);
                OperandType ot = GetOperandType(i);
                if (ot == OT_BYTE_WORD) {
                    ot = GetOperandDecodeMode() == DM_16BIT ? OT_ABS_BYTE : OT_ABS_WORD;
                } else if (ot == OT_WORD_DWORD) {
                    ot = GetOperandDecodeMode() == DM_16BIT ? OT_ABS_WORD : OT_ABS_DWORD;
                }
                address += GetInstructionLength();
                switch (ot) {
                    case OT_ABS_BYTE:
                        if (GetOperandDecodeMode() == DM_16BIT) {
                            sprintf(buf, "%04X", (unsigned short)((signed char)value.Value.relOff + (unsigned short)address));
                            text += buf;
                        } else {
                            sprintf(buf, "%08X", (unsigned int)((signed char)value.Value.relOff + (unsigned int)address));
                            text += buf;
                        }
                        break;
                    case OT_ABS_WORD:
                        if (GetOperandDecodeMode() == DM_16BIT) {
                            sprintf(buf, "%04X", (unsigned short)((signed short)value.Value.relOff + (unsigned short)address));
                            text += buf;
                        } else {
                            sprintf(buf, "%08X", (unsigned int)((signed short)value.Value.relOff + (unsigned int)address));
                            text += buf;
                        }
                        break;
                    case OT_ABS_DWORD:
                        sprintf(buf, "%08X", (unsigned int)((signed int)value.Value.relOff + (unsigned int)address));
                        text += buf;
                        break;
                    default:
                        break;
                }
                }
                break;
            case OVT_IMM8:
                sprintf(buf, "%02X", (unsigned char)value.Value.imm);
                text += buf;
                break;
            case OVT_IMM16:
                sprintf(buf, "%04X", (unsigned short)value.Value.imm);
                text += buf;
                break;
            case OVT_IMM32:
                sprintf(buf, "%08X", (unsigned int)value.Value.imm);
                text += buf;
                break;
            case OVT_SOURCE:
                FormatOperandType(text, GetOperandType(i), GetOperandDecodeMode());
                if (GetAddressDecodeMode() == DM_16BIT) {
                    text += "DS:[SI]";
                } else {
                    text += "DS:[ESI]";
                }
                break;
            case OVT_DESTINATION:
                FormatOperandType(text, GetOperandType(i), GetOperandDecodeMode());
                if (GetAddressDecodeMode() == DM_16BIT) {
                    text += "ES:[DI]";
                } else {
                    text += "ES:[EDI]";
                }
                break;
            case OVT_NONE:
            default:
                text += "???";
                break;
        }

        m_pimpl->operands.push_back(text);
    }
}

const char *Disassembler::GetFormattedPrefix() const
{
    return m_pimpl->prefix.c_str();
}

const char *Disassembler::GetFormattedOpcode() const
{
    return m_pimpl->opcode.c_str();
}

const char *Disassembler::GetFormattedOperand(std::size_t index) const
{
    assert(index < m_pimpl->operands.size());
    return m_pimpl->operands[index].c_str();
}

bool Disassembler::Impl::FormatPrefix(std::string & text, PrefixGroup group) const
{
    std::size_t numPrefixes = self->GetPrefixCount();

    for (std::size_t i = 0; i < numPrefixes; i++) {
        const Prefix & prefix = self->GetPrefix(i);
        if (prefix.group == group) {
            text += GetPrefixText(prefix);
            return true;
        }
    }

    return false;
}

}

// Internal functions
namespace {

const char *GetPrefixText(const Prefix & prefix)
{
    return PrefixTextTable[prefix.index];
}

const char **GetRegisterTextTable(DecodeMode dm)
{
    return dm == DM_16BIT ? RegisterTextTable16 : RegisterTextTable32;
}

const char *GetOpcodeText(OpcodeType op, DecodeMode dm)
{
    // Special cases for 32bit mnemonics
    if (dm == DM_32BIT) {
        switch (op) {
            case O_PUSHA:
                return "PUSHAD";
            case O_POPA:
                return "POPAD";
            case O_CBW:
                return "CWDE";
            case O_CWD:
                return "CDQ";
            case O_PUSHF:
                return "PUSHFD";
            case O_POPF:
                return "POPFD";
            case O_JCXZ:
                return "JECXZ";
            default:
                break;
        }
    }

    return OpcodeTextTable[op];
}

std::string FormatDisplacement(unsigned int disp, DisplacementType dt)
{
    char fmt[64];

    switch (dt) {
        case DT_8BIT:
            if (disp >= 0x80)
                sprintf(fmt, "-%02X", 0x100 - disp);
            else
                sprintf(fmt, "+%02X", disp);
            break;
        case DT_16BIT:
            sprintf(fmt, "+%04X", disp);
            break;
        case DT_32BIT:
            sprintf(fmt, "+%08X", disp);
            break;
        default:
            fmt[0] = '\0';
            break;
    }

    return fmt;
}

void FormatOperandType(std::string & text, OperandType ot, DecodeMode dm)
{
    if (ot == OT_BYTE_WORD) {
        ot = dm == DM_16BIT ? OT_ABS_BYTE : OT_ABS_WORD;
    } else if (ot == OT_WORD_DWORD) {
        ot = dm == DM_16BIT ? OT_ABS_WORD : OT_ABS_DWORD;
    }

    bool addPostfix = true;

    switch (ot) {
        case OT_ABS_BYTE:
            text += "BYTE";
            break;
        case OT_ABS_WORD:
            text += "WORD";
            break;
        case OT_ABS_DWORD:
            text += "DWORD";
            break;
        case OT_32_48_PTR:
            if (dm == DM_16BIT)
                text += "DWORD";
            else
                text += "FWORD";
            break;
        case OT_PDESC:
            text += "FWORD";
            break;
        case OT_ABS_QWORD:
            text += "QWORD";
            break;
        case OT_FPU_SINGLE:
            text += "REAL4";
            break;
        case OT_FPU_DOUBLE:
            text += "REAL8";
            break;
        case OT_FPU_EXTENDED:
            text += "REAL10";
            break;
        case OT_FPU_BCD:
            text += "TBYTE";
            break;
        case OT_FPU_ENV:
        case OT_FPU_STATE:
            addPostfix = false;
            break;
        default:
            assert(!"Invalid operand type");
            addPostfix = false;
            break;
    }

    if (addPostfix)
        text += " PTR ";
}

bool FormatOperandTypeSpecialCases(OpcodeType op)
{
    switch (op) {
        case O_MOVZX:
        case O_MOVSX:
            return true;
        default:
            break;
    }

    return false;
}

std::string FormatSIB(unsigned int ma, const SIB & sib, unsigned int disp)
{
    char buf[64];
    char buf2[64];
    int scale = 1 << sib.scale;

    const char **RegisterTextTable32 = GetRegisterTextTable(DM_32BIT);

    if (sib.index == REG_ESP) {
        strcpy(buf, "[");
    } else if (scale == 1) {
        sprintf(buf, "[%s", RegisterTextTable32[sib.index]);
    } else {
        sprintf(buf, "[%s*%d", RegisterTextTable32[sib.index], scale);
    }

    switch (ma) {
        case 1:
            // General register (except EBP) or Disp32
            if (sib.base != REG_EBP) {
                sprintf(buf2, sib.index == REG_ESP ? "%s]" : "+%s]", RegisterTextTable32[sib.base]);
            } else {
                // Disp32
                sprintf(buf2, "%s]", FormatDisplacement(disp, DT_32BIT).c_str());
            }
            strcat(buf, buf2);
            break;
        case 2:
        case 3:
            {
            sprintf(buf2, sib.index == REG_ESP ? "%s%s]" : "+%s%s]", RegisterTextTable32[sib.base], FormatDisplacement(disp, ma == 2 ? DT_8BIT : DT_32BIT).c_str());
            strcat(buf, buf2);
            }
            break;
            break;
        default:
            assert(!"Invalid memory addressing mode");
            buf[0] = '\0';
            break;
    }

    return buf;
}

}
