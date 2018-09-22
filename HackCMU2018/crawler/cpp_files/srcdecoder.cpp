/** @file decoder.cpp \brief Brizo instruction decoder implementation. */
// $Workfile: decoder.cpp $
//
// Brizo Disassembler by DEATH, 2003-2004
//
// Basic disassembler class.
//
// $Author: Death $
// $Revision: 31 $
// $Date: 11/22/04 1:54 $
//
// $NoKeywords: $
//
#include "stdafx.h"
#include <brizo/decoder.h>

using namespace Brizo_DE20041115;

// Internal function declarations
namespace
{

// Memory access functions
unsigned int GetMem16(const unsigned char *mem);
unsigned int GetMem32(const unsigned char *mem);
unsigned int GetMem(OperandType ot, const unsigned char **mem, std::size_t *length, DecodeMode dm);
// Register translation functions
Register GetGeneralRegister(std::size_t index, AddressingMode am, OperandType ot);
Register GetSegmentRegister(std::size_t index);
Register GetXmmRegister(std::size_t index);
Register GetControlRegister(std::size_t index);
Register GetDebugRegister(std::size_t index);
Register GetTestRegister(std::size_t index);
Register GetMmxRegister(std::size_t index, OperandType otype);

const std::size_t MaxOperandValueCount = 3;
const std::size_t MaxPrefixCount = 4;
const unsigned char FirstFPUOpcode = 0xD8;
const unsigned char LastFPUOpcode = 0xDF;

}

namespace Brizo_DE20041115
{

extern const Opcode OpcodeTable[];
extern const std::size_t OpcodeTableLength;
extern const Opcode FPUOpcodeTableLow[];
extern const std::size_t FPUOpcodeTableLowLength;
extern const Opcode FPUOpcodeTableHigh[];
extern const std::size_t FPUOpcodeTableHighLength;
extern const Prefix PrefixTable[];
extern const std::size_t PrefixTableLength;

/// Brizo instruction decoder implementation
struct Decoder::Impl
{
    typedef std::vector<const Prefix *> Prefixes; ///< A vector containing pointers to prefixes from Brizo::PrefixTable

    Impl()
    {
        Reset();
    }

    Impl(const Impl & other)
    : m_opcode(other.m_opcode)
    , m_dmAddress(other.m_dmAddress)
    , m_dmOperand(other.m_dmOperand)
    , m_prefixes(other.m_prefixes)
    , m_modrm(other.m_modrm)
    , m_sib(other.m_sib)
    , m_length(other.m_length)
    {
        std::copy(other.m_values, other.m_values + MaxOperandValueCount, m_values);
    }

    /// Reset decoder state
    void Reset();

    // Main decode functions

    /// Decode instruction prefixes
    /// @param mem The memory buffer holding the instruction bytes, starting from
    ///            prefixes if they exist
    /// @param length The buffer length
    /// @return A signed integer
    /// @return If positive, represents the number of bytes prefixes occupy.
    ///         If zero, no prefix was found.
    ///         If negative, the function failed to decode the prefixes, and the
    ///         absolute return value is the number of bytes that were read before
    ///         the decoding failed.
    int DecodePrefix(const unsigned char *mem, std::size_t length);

    /// Decode instruction opcode
    /// @param mem The memory buffer holding the instruction bytes, starting from
    ///            the opcode, if one exists
    /// @param length The buffer length
    /// @return A signed integer
    /// @return If positive, represents the number of bytes the opcode occupies.
    ///         If zero, no opcode was found (which is an error).
    ///         If negative, the function failed to decode the opcode, and the
    ///         absolute return value is the number of bytes that were read before
    ///         the decoding failed.
    /// @see DecodeFPUOpcode()
    int DecodeOpcode(const unsigned char *mem, std::size_t length);

    /// Decode instruction operand values
    /// @param mem The memory buffer holding the instruction bytes, starting from
    ///            the operand values, if they exist
    /// @param length The buffer length
    /// @return A signed integer
    /// @return If positive, represents the number of bytes the values occupy.
    ///         If zero, no values were found (which is an error if the instruction
    ///         is supposed to have them).
    ///         If negative, the function failed to decode the values, and the
    ///         absolute return value is the number of bytes that were read before
    ///         the decoding failed.
    /// @see DecodeValuesSpecialCases()
    /// @see DecodeValueByModRm()
    int DecodeValues(const unsigned char *mem, std::size_t length);

    // Specific decode functions

    /// Decode and special-case operand values
    /// @param mem A pointer to a pointer to the memory buffer to decode the
    ///            values from, on return, *mem will be adjusted to after the
    ///            values decoded
    /// @param length The buffer length
    /// @return true if a special-case operand value was decoded, false if not
    /// @see DecodeValues()
    /// @see DecodeValueByModRm()
    bool DecodeValuesSpecialCases(const unsigned char **mem, std::size_t length);

    /// Fills an operand value from Impl::m_values using the Impl::m_modrm byte
    /// and passed parameters
    /// @param mem The memory buffer holding the instruction bytes, starting from
    ///            the value, if one exist
    /// @param length The buffer length
    /// @param index Index that specifies which value of Impl::m_values to fill
    /// @param am The operand's addressing mode
    /// @param ot The operand's type
    /// @return If positive, represents the number of bytes the value occupies.
    ///         If zero, no value was found (which is an error if the instruction
    ///         is supposed to have it).
    ///         If negative, the function failed to decode the value, and the
    ///         absolute return value is the number of bytes that were read before
    ///         the decoding failed.
    /// @see DecodeValues()
    /// @see DecodeValuesSpecialCases()
    int DecodeValueByModRm(const unsigned char *mem, std::size_t length, std::size_t index, AddressingMode am, OperandType ot);

    /// Decode SIB (scale-index-base) byte
    /// @param mem A pointer to a pointer to the memory buffer to decode the
    ///            byte from, on return, *mem will be adjusted to after the
    ///            byte decoded
    /// @param length A pointer to the buffer length, on return, will be adjusted
    ///               to the current length in relation to the *mem returned
    /// @return true if SIB byte was decoded, false if not
    bool DecodeSIB(const unsigned char **mem, std::size_t *length);

    /// Decode ModR/M byte onto Impl::m_modrm
    /// @param b The ModR/M byte to be decoded
    void DecodeModRM(unsigned char b);

    /// Decode an FPU opcode
    /// @param mem The memory buffer holding the instruction bytes, starting from
    ///            the opcode, if one exists
    /// @param length The buffer length
    /// @return A signed integer
    /// @return If positive, represents the number of bytes the opcode occupies.
    ///         If zero, no opcode was found (which is an error).
    ///         If negative, the function failed to decode the opcode, and the
    ///         absolute return value is the number of bytes that were read before
    ///         the decoding failed.
    /// @see DecodeOpcode()
    int DecodeFPUOpcode(const unsigned char *mem, std::size_t length);

    // Prefix process functions

    /// Process decode mode prefixes in the instruction.
    /// Overrides default address/operand size decode modes
    void ProcessDecodeModePrefixes();

    // Prefix management functions

    /// Determine whether prefixes are valid before decoding opcode
    /// @return true if prefixes are valid, false if not
    /// @see ValidatePrefixesPostDecode()
    bool ValidatePrefixesPreDecode() const;

    /// Determine whether prefixes are valid after decoding opcode
    /// @return true if prefixes are valid, false if not
    /// @see ValidatePrefixesPostDecode()
    bool ValidatePrefixesPostDecode() const;

    /// Determine whether a prefix already exists in the instruction
    /// @param code The prefix code
    /// @return true if prefix exists, false if not
    bool PrefixExists(PrefixEnum code) const;

    /// Remove a prefix from instruction
    /// @param code The prefix code
    void RemovePrefix(PrefixEnum code);

    // Miscellaneous functions

    /// Check whether the MOD field of Impl::m_modrm matches against Brizo::OpcodeFlags
    /// @param flags A value or combined values from Brizo::OpcodeFlags
    /// @return true if the MOD field matches, false if not
    bool IsModValueMatching(unsigned int flags) const;

    /// Special case for SSE3 instructions MWAIT/MONITOR, which have the same
    /// opcode/MOD/REG bits. The only difference between them is the R/M
    /// bits value.
    /// @param mem The memory buffer holding the instruction bytes, starting from
    ///            the opcode
    /// @param length The buffer length (checked to be at least 3 bytes)
    /// @param opcode Default opcode if not SSE3/invalid instruction
    /// @return The SSE3 instruction, null pointer if it's not an SSE3
    ///         instruction
    const Opcode *DecodeOpcodeSSE3SpecialCase(const unsigned char *mem, std::size_t length, const Opcode *opcode) const;

    /// Stupid lookup for an opcode in the opcodes tables
    /// @param op The opcode to look up
    /// @return The opcode entry
    const Opcode *LookupOpcode(OpcodeType op) const;

public:
    const Opcode *m_opcode; ///< The instruction's opcode
    DecodeMode m_dmAddress; ///< Actual address size decoding mode used
    DecodeMode m_dmOperand; ///< Actual operand size decoding mode used

    Prefixes m_prefixes; ///< The instruction's prefixes
    ModRm m_modrm; ///< The instruction's ModR/M byte
    OperandValue m_values[MaxOperandValueCount]; ///< The instruction's operand values
    SIB m_sib; ///< The instruction's SIB byte
    int m_length; ///< The instruction's length
};

Decoder::Decoder()
: m_pimpl(new Impl)
{
}

Decoder::Decoder(const Decoder & other)
: m_pimpl(new Impl(*other.m_pimpl))
{
}

Decoder::~Decoder()
{
}

Decoder & Decoder::operator= (const Decoder & rhs)
{
    if (this != &rhs) {
        Decoder temp(rhs);
        std::swap(m_pimpl, temp.m_pimpl);
    }
    return *this;
}

int Decoder::Decode(const unsigned char *mem, std::size_t length, DecodeMode dmDefaultAddress, DecodeMode dmDefaultOperand)
{
    m_pimpl->Reset();

    m_pimpl->m_dmAddress = dmDefaultAddress;
    m_pimpl->m_dmOperand = dmDefaultOperand;

    int processed = 0;

    processed += m_pimpl->DecodePrefix(mem, length);

    if (m_pimpl->ValidatePrefixesPreDecode() == false)
        return -processed;

    m_pimpl->ProcessDecodeModePrefixes();

    processed += m_pimpl->DecodeOpcode(&mem[processed], length - processed);
    if (m_pimpl->m_opcode == 0)
        return -processed;

    if (m_pimpl->ValidatePrefixesPostDecode() == false)
        return -processed;

    processed += m_pimpl->DecodeValues(&mem[processed], length - processed);
    if (m_pimpl->m_opcode == 0)
        return -processed;

    m_pimpl->m_length = processed;
    return processed;
}

int Decoder::Impl::DecodePrefix(const unsigned char *mem, std::size_t length)
{
    if (length == 0)
        return 0;

    int processed = 0;

    do {
        const unsigned char byte = *mem;
        std::size_t i;
        for (i = 0; i < PrefixTableLength; i++) {
            if (byte == PrefixTable[i].code) {
                // Maximum of 4 prefixes per instruction
                if (m_prefixes.size() == MaxPrefixCount)
                    return processed;

                m_prefixes.push_back(&PrefixTable[i]);
                processed++;
                break;
            }
        }

        if (i == PrefixTableLength)
            break;

        length--;
        mem++;
    } while (length != 0);

    return processed;
}

bool Decoder::Impl::ValidatePrefixesPreDecode() const
{
    bool occ[MaxPrefixCount] = {false};

    for (Prefixes::const_iterator i = m_prefixes.begin(); i != m_prefixes.end(); ++i) {
        const Prefix *prefix = *i;

        // Did a prefix from that group already occured?
        if (occ[prefix->group - 1] == true)
            return false;

        occ[prefix->group - 1] = true;
    }

    return true;
}

bool Decoder::Impl::ValidatePrefixesPostDecode() const
{
    const Opcode *opcode = m_opcode;

    for (Prefixes::const_iterator i = m_prefixes.begin(); i != m_prefixes.end(); ++i) {
        const Prefix *prefix = *i;

        switch (prefix->group) {
            case PG_LOCK_REP:
                // LOCK/REP m_prefixes
                if (prefix->code == P_LOCK) {
                    // LOCK
                    // TODO: Validate lock prefix
                } else {
                    if (opcode->IsStringOperation() == false)
                        return false;
                }
                break;
            case PG_SEG_BRANCH:
                // Segment override/Branch expectators
                if (prefix->code != P_BRANCH_NOT_TAKEN && prefix->code != P_BRANCH_TAKEN) {
                    // Must not be used with Jcc instructions
                    if (opcode->IsJccOperation() == true)
                        return false;
                }
                break;
            case PG_OP_OVERRIDE:
                // Operand size override
                break;
            case PG_ADDR_OVERRIDE:
                // Address size override
                break;
            default:
                break;
        }
    }

    return true;
}

void Decoder::Impl::ProcessDecodeModePrefixes()
{
    for (Prefixes::const_iterator i = m_prefixes.begin(); i != m_prefixes.end(); ++i) {
        const Prefix *prefix = *i;

        switch (prefix->code) {
            case P_OVERRIDE_OP:
                m_dmOperand = m_dmOperand == DM_16BIT ? DM_32BIT : DM_16BIT;
                break;
            case P_OVERRIDE_ADDR:
                m_dmAddress = m_dmAddress == DM_16BIT ? DM_32BIT : DM_16BIT;
                break;
            default:
                break;
        }
    }
}

int Decoder::Impl::DecodeOpcode(const unsigned char *mem, std::size_t length)
{
    m_opcode = 0;

    if (length == 0)
        return 0;

    if (*mem >= FirstFPUOpcode && *mem <= LastFPUOpcode)
        return DecodeFPUOpcode(mem, length);

    bool gotModRm = false;
    const unsigned char *base = mem;
    std::size_t i;

    for (i = 0; i < OpcodeTableLength; i++) {
        if (*mem == (OpcodeTable[i].code & 0xFF)) {
            if (OpcodeTable[i].flags & OF_1BYTE) {
                // One-byte opcodes
                // Check prefix
                if (OpcodeTable[i].flags & OF_USEPREFIX) {
                    if (PrefixExists(OpcodeTable[i].prefix) == false)
                        continue;
                }
                if (OpcodeTable[i].flags & OF_MRMBITS) {
                    // Opcode is 1byte + 3bits of ModR/M
                    if (length <= 1)
                        continue;
                    // Decode ModR/M byte
                    if (!gotModRm) {
                        DecodeModRM(mem[1]);
                        gotModRm = true;
                    }
                    // Check ModR/M bits
                    if (IsModValueMatching(OpcodeTable[i].flags) && OpcodeTable[i].mrmbits == m_modrm.reg) {
                        m_opcode = &OpcodeTable[i];
                        mem += 2;
                        length -= 2;
                        break;
                    }
                } else {
                    // Opcode is 1 byte, this is it
                    m_opcode = &OpcodeTable[i];
                    mem++;
                    length--;
                    break;
                }
            } else if (OpcodeTable[i].flags & OF_2BYTE) {
                // Two-bytes opcodes
                if (length <= 1)
                    continue;
                // Check second byte
                if (mem[1] == (OpcodeTable[i].code >> 8)) {
                    // Check ModR/M g/leq 0xBF flags
                    if ((OpcodeTable[i].flags & OF_MRM_G_BF) || (OpcodeTable[i].flags & OF_MRM_LEQ_BF)) {
                        if (length <= 2)
                            continue;
                        if ((mem[2] > 0xBF) && (OpcodeTable[i].flags & OF_MRM_LEQ_BF))
                            continue;
                        if ((mem[2] <= 0xBF) && (OpcodeTable[i].flags & OF_MRM_G_BF))
                            continue;

                        // Decode ModR/M byte
                        if (!gotModRm) {
                            DecodeModRM(mem[2]);
                            gotModRm = true;
                        }
                    }
                    // Check prefix
                    if (OpcodeTable[i].flags & OF_USEPREFIX) {
                        if (PrefixExists(OpcodeTable[i].prefix) == false)
                            continue;
                    }
                    // Check ModR/M bits
                    if (OpcodeTable[i].flags & OF_MRMBITS) {
                        if (length <= 2)
                            continue;
                        // Decode ModR/M byte
                        if (!gotModRm) {
                            DecodeModRM(mem[2]);
                            gotModRm = true;
                        }
                        // Check ModR/M bits
                        if (IsModValueMatching(OpcodeTable[i].flags) && OpcodeTable[i].mrmbits == m_modrm.reg) {
                            m_opcode = DecodeOpcodeSSE3SpecialCase(mem, length, &OpcodeTable[i]);
                            mem += 3;
                            length -= 3;
                            break;
                        }
                    } else {
                        // Opcode is 2 bytes, this is it
                        m_opcode = &OpcodeTable[i];
                        mem += 2;
                        length -= 2;
                        if (gotModRm) {
                            mem++;
                            length--;
                        }
                        break;
                    }
                }
            }
        }
    }

    // No such opcode
    if (m_opcode == 0)
        return static_cast<int>(mem - base);

    const Opcode *opcode = m_opcode;

    // Remove opcode prefix if necessary
    if (opcode->flags & OF_USEPREFIX)
        RemovePrefix(opcode->prefix);

    // Get ModR/M byte if necessary
    std::size_t operandCount = opcode->GetOperandCount();
    for (i = 0; (i < operandCount) && (gotModRm == false); i++) {
        const Operand & operand = opcode->operands[i];
        if (operand.reg == REG_NONE) {
            switch (operand.amode) {
                case AM_CONTROL_REGISTER:
                case AM_DEBUG_REGISTER:
                case AM_MODRM:
                case AM_GENERAL_REGISTER:
                case AM_MODRM_MEMORY:
                case AM_MODRM_MMX:
                case AM_MODRM_MMX_MEMORY:
                case AM_MODRM_GENERAL_REGISTER:
                case AM_MODRM_SEGMENT:
                case AM_MODRM_TEST:
                case AM_MODRM_XMM:
                case AM_MODRM_XMM_MEMORY:
                    if (length == 0) {
                        m_opcode = 0;
                        return static_cast<int>(mem - base);
                    }
                    DecodeModRM(*mem);
                    length--;
                    mem++;
                    gotModRm = true;
                    break;
                case AM_NO_MODRM:
                case AM_NONE:
                case AM_DIRECT_ADDRESS:
                case AM_EFLAGS:
                case AM_IMMEDIATE_DATA:
                case AM_RELATIVE_OFFSET:
                case AM_DSSI:
                case AM_ESDI:
                default:
                    break;
            }
        }
    }

    return static_cast<int>(mem - base);
}

int Decoder::Impl::DecodeValues(const unsigned char *mem, std::size_t length)
{
    const unsigned char *base = mem;

    if (DecodeValuesSpecialCases(&mem, length))
        return static_cast<int>(mem - base);

    const Opcode *opcode = m_opcode;
    std::size_t operandCount = opcode->GetOperandCount();
    bool usedReg = opcode->flags & OF_MRMBITS ? true : false;
    for (std::size_t i = 0; i < operandCount; i++) {
        const Operand & operand = opcode->operands[i];
        if (operand.reg != REG_NONE) {
            m_values[i].type = OVT_REGISTER;
            m_values[i].Value.reg = operand.reg;
            usedReg = true;
        } else {
            switch (operand.amode) {
                case AM_MODRM_SEGMENT:
                    m_values[i].type = OVT_REGISTER;
                    m_values[i].Value.reg = GetSegmentRegister(m_modrm.reg);
                    usedReg = true;
                    break;
                case AM_GENERAL_REGISTER:
                    m_values[i].type = OVT_REGISTER;
                    m_values[i].Value.reg = GetGeneralRegister(m_modrm.reg, operand.amode, operand.otype);
                    usedReg = true;
                    break;
                case AM_RELATIVE_OFFSET:
                    m_values[i].type = OVT_REL_OFF;
                    m_values[i].Value.relOff = GetMem(operand.otype, &mem, &length, m_dmOperand);
                    break;
                case AM_IMMEDIATE_DATA:
                    switch (operand.otype) {
                        case OT_ABS_BYTE:
                            m_values[i].type = OVT_IMM8;
                            break;
                        case OT_ABS_DWORD:
                            m_values[i].type = OVT_IMM32;
                            break;
                        case OT_ABS_WORD:
                            m_values[i].type = OVT_IMM16;
                            break;
                        case OT_BYTE_WORD:
                            m_values[i].type = m_dmOperand == DM_16BIT ? OVT_IMM8 : OVT_IMM16;
                            break;
                        case OT_WORD_DWORD:
                            m_values[i].type = m_dmOperand == DM_16BIT ? OVT_IMM16 : OVT_IMM32;
                            break;
                        default:
                            break;
                    }
                    m_values[i].Value.imm = 0;
                    switch (m_values[i].type) {
                        case OVT_IMM8:
                            m_values[i].Value.imm = GetMem(OT_ABS_BYTE, &mem, &length, m_dmOperand);
                            break;
                        case OVT_IMM16:
                            m_values[i].Value.imm = GetMem(OT_ABS_WORD, &mem, &length, m_dmOperand);
                            break;
                        case OVT_IMM32:
                            m_values[i].Value.imm = GetMem(OT_ABS_DWORD, &mem, &length, m_dmOperand);
                            break;
                        default:
                            break;
                    }
                    break;
                case AM_NO_MODRM:
                    m_values[i].type = OVT_OFF;
                    m_values[i].Value.off = GetMem(operand.otype, &mem, &length, m_dmAddress);
                    break;
                case AM_DSSI:
                    m_values[i].type = OVT_SOURCE;
                    break;
                case AM_ESDI:
                    m_values[i].type = OVT_DESTINATION;
                    break;
                case AM_DIRECT_ADDRESS:
                    m_values[i].type = OVT_DIRECT;
                    m_values[i].Value.dir.off = GetMem(OT_WORD_DWORD, &mem, &length, m_dmAddress);
                    m_values[i].Value.dir.seg = GetMem(OT_ABS_WORD, &mem, &length, m_dmAddress);
                    break;
                case AM_MODRM_XMM:
                    m_values[i].type = OVT_REGISTER;
                    if (usedReg) {
                        m_values[i].Value.reg = GetXmmRegister(m_modrm.rm);
                    } else {
                        m_values[i].Value.reg = GetXmmRegister(m_modrm.reg);
                        usedReg = true;
                    }
                    break;
                case AM_MODRM_MMX_MEMORY:
                case AM_MODRM_XMM_MEMORY:
                case AM_MODRM_MEMORY:
                case AM_MODRM:
                    {
                        int ret = DecodeValueByModRm(mem, length, i, operand.amode, operand.otype);
                        if (ret > 0) {
                            mem += ret;
                            length -= ret;
                        }
                    }
                    break;
                case AM_MODRM_GENERAL_REGISTER:
                    // NOTE: Intel IA32 specification volume 2 says that in this addressing
                    // mode the register is determined from the MOD bits, but all disassemblers
                    // I saw so far use the RM bits.
                    m_values[i].type = OVT_REGISTER;
                    m_values[i].Value.reg = GetGeneralRegister(m_modrm.rm, operand.amode, operand.otype);
                    break;
                case AM_CONTROL_REGISTER:
                    m_values[i].type = OVT_REGISTER;
                    m_values[i].Value.reg = GetControlRegister(m_modrm.reg);
                    usedReg = true;
                    break;
                case AM_DEBUG_REGISTER:
                    m_values[i].type = OVT_REGISTER;
                    m_values[i].Value.reg = GetDebugRegister(m_modrm.reg);
                    usedReg = true;
                    break;
                case AM_MODRM_TEST:
                    m_values[i].type = OVT_REGISTER;
                    m_values[i].Value.reg = GetTestRegister(m_modrm.reg);
                    usedReg = true;
                    break;
                case AM_MODRM_MMX:
                    m_values[i].type = OVT_REGISTER;
                    if (usedReg) {
                        m_values[i].Value.reg = GetMmxRegister(m_modrm.rm, operand.otype);
                    } else {
                        m_values[i].Value.reg = GetMmxRegister(m_modrm.reg, operand.otype);
                        usedReg = true;
                    }
                    break;
                case AM_NONE:
                case AM_EFLAGS:
                default:
                    break;
            }
        }
    }

    return static_cast<int>(mem - base);
}

int Decoder::Impl::DecodeValueByModRm(const unsigned char *mem, std::size_t length, std::size_t index, AddressingMode am, OperandType ot)
{
    const unsigned char *base = mem;

    switch (m_modrm.mod) {
        case 0:
            m_values[index].type = OVT_MEM_ADDR_1;

            if (m_dmAddress == DM_16BIT)
                m_values[index].Value.ma.ma1 = (MemAddr1Type)m_modrm.rm;
            else
                m_values[index].Value.ma.ma1 = (MemAddr1Type)(m_modrm.rm + 8);

            switch (m_values[index].Value.ma.ma1) {
                case MA1_DISP16:
                    m_values[index].Value.ma.disp = GetMem(OT_ABS_WORD, &mem, &length, DM_16BIT);
                    break;
                case MA1_DISP32:
                    m_values[index].Value.ma.disp = GetMem(OT_ABS_DWORD, &mem, &length, DM_32BIT);
                    break;
                case MA1_SIB:
                    if (DecodeSIB(&mem, &length) == true) {
                        m_values[index].Value.ma.sib = m_sib;
                        if (m_values[index].Value.ma.sib.base == REG_EBP) {
                            // No base, disp32 instead
                            m_values[index].Value.ma.disp = GetMem(OT_ABS_DWORD, &mem, &length, DM_32BIT);
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
        case 1:
            m_values[index].type = OVT_MEM_ADDR_2;

            if (m_dmAddress == DM_16BIT)
                m_values[index].Value.ma.ma2 = (MemAddr2Type)m_modrm.rm;
            else
                m_values[index].Value.ma.ma2 = (MemAddr2Type)(m_modrm.rm + 8);

            if (m_values[index].Value.ma.ma2 == MA2_SIB_DISP8) {
                if (DecodeSIB(&mem, &length) == true)
                    m_values[index].Value.ma.sib = m_sib;
            }

            m_values[index].Value.ma.disp = GetMem(OT_ABS_BYTE, &mem, &length, m_dmOperand);
            break;
        case 2:
            m_values[index].type = OVT_MEM_ADDR_3;

            if (m_dmAddress == DM_16BIT)
                m_values[index].Value.ma.ma3 = (MemAddr3Type)m_modrm.rm;
            else
                m_values[index].Value.ma.ma3 = (MemAddr3Type)(m_modrm.rm + 8);

            if (m_values[index].Value.ma.ma3 == MA3_SIB_DISP32) {
                if (DecodeSIB(&mem, &length) == true)
                    m_values[index].Value.ma.sib = m_sib;
            }

            m_values[index].Value.ma.disp = GetMem(m_dmAddress == DM_16BIT ? OT_ABS_WORD : OT_ABS_DWORD, &mem, &length, m_dmOperand);
            break;
        case 3:
            if (am == AM_MODRM_MEMORY) {
                // Register operands aren't allowed

                // NOTE: I don't know whether this is a good decision, but
                // reset m_opcode to zero so decoder fails
                m_opcode = 0;

                m_values[index].type = OVT_NONE;
                return static_cast<int>(mem - base);
            }

            // Register
            m_values[index].type = OVT_REGISTER;
            m_values[index].Value.reg = GetGeneralRegister(m_modrm.rm, am, ot);
            break;
        default:
            break;
    }

    return static_cast<int>(mem - base);
}

void Decoder::Impl::Reset()
{
    m_prefixes.clear();
    m_opcode = 0;
    memset(&m_modrm, 0, sizeof(ModRm));
    m_sib.base = REG_NONE;
    m_sib.index = REG_NONE;
    m_sib.scale = 0;
    for (std::size_t i = 0; i < MaxOperandValueCount; i++)
        m_values[i].type = OVT_NONE;
}

void Decoder::Impl::DecodeModRM(unsigned char b)
{
    m_modrm.rm = b & 7;
    m_modrm.reg = (b >> 3) & 7;
    m_modrm.mod = (b >> 6);
}

int Decoder::Impl::DecodeFPUOpcode(const unsigned char *mem, std::size_t length)
{
    if (length < 2)
        return -1;

    unsigned char mrm = mem[1];

    if (mrm <= 0xBF) {
        // Parse ModR/M and use 'reg' for opcode extension
        DecodeModRM(mrm);
        for (std::size_t i = 0; i < FPUOpcodeTableLowLength; i++) {
            if (FPUOpcodeTableLow[i].code == mem[0]) {
                if (FPUOpcodeTableLow[i].mrmbits == m_modrm.reg) {
                    // We found our opcode
                    m_opcode = &FPUOpcodeTableLow[i];
                    return 2;
                }
            }
        }
    } else {
        // ModR/M is used as opcode extension
        unsigned short v = mem[0] | (mrm << 8);
        for (std::size_t i = 0; i < FPUOpcodeTableHighLength; i++) {
            if (FPUOpcodeTableHigh[i].code == v) {
                m_opcode = &FPUOpcodeTableHigh[i];
                return 2;
            }
        }
    }

    return 0;
}

bool Decoder::Impl::DecodeSIB(const unsigned char **mem, std::size_t *length)
{
    if (*length < 1)
        return false;

    (*length)--;

    unsigned char base = **mem & 7;
    unsigned char index = (**mem >> 3) & 7;
    unsigned char scale = (**mem >> 6);

    m_sib.base = GetGeneralRegister(base, AM_GENERAL_REGISTER, OT_ABS_DWORD);
    m_sib.index = GetGeneralRegister(index, AM_GENERAL_REGISTER, OT_ABS_DWORD);
    m_sib.scale = scale;

    (*mem)++;

    return true;
}

bool Decoder::Impl::DecodeValuesSpecialCases(const unsigned char **mem, std::size_t length)
{
    const Opcode *opcode = m_opcode;
    std::size_t operandCount = opcode->GetOperandCount();

    if (operandCount == 2) {
        if (opcode->operands[0].amode == AM_MODRM_MMX_MEMORY && opcode->operands[1].amode == AM_MODRM_XMM_MEMORY) {
            // Register
            m_values[0].type = OVT_REGISTER;
            m_values[0].Value.reg = GetGeneralRegister(m_modrm.reg, opcode->operands[0].amode, opcode->operands[0].otype);
            int ret = DecodeValueByModRm(*mem, length, 1, opcode->operands[1].amode, opcode->operands[1].otype);
            if (ret > 0)
                *mem += ret;
            return true;
        }
    }

    return false;
}

bool Decoder::Impl::PrefixExists(PrefixEnum code) const
{
    for (Prefixes::const_iterator i = m_prefixes.begin(); i != m_prefixes.end(); ++i) {
        const Prefix *prefix = *i;

        if (prefix->code == code)
            return true;
    }

    return false;
}

void Decoder::Impl::RemovePrefix(PrefixEnum code)
{
    Prefixes::iterator i = m_prefixes.begin();

    while (i != m_prefixes.end()) {
        const Prefix *prefix = *i;

        if (prefix->code == code)
            break;

        ++i;
    }

    if (i != m_prefixes.end())
        m_prefixes.erase(i);
}

bool Decoder::Impl::IsModValueMatching(unsigned int flags) const
{
    if ((flags & OF_MODBOTH) == OF_MODBOTH)
        return true;

    if (flags & OF_MOD11)
        return m_modrm.mod == 3;

    assert(flags & OF_MODMEM);
    return m_modrm.mod != 3;
}

const Opcode *Decoder::Impl::LookupOpcode(OpcodeType op) const
{
    for (std::size_t i = 0; i < OpcodeTableLength; i++) {
        if (OpcodeTable[i].op == op)
            return &OpcodeTable[i];
    }

    return 0;
}

const Opcode *Decoder::Impl::DecodeOpcodeSSE3SpecialCase(const unsigned char *mem, std::size_t length, const Opcode *opcode) const
{
    assert(length >= 3);

    if (mem[0] == 0x0F && mem[1] == 0x01) {
        if (m_modrm.mod == 3 && m_modrm.reg == 1) {
            switch (m_modrm.rm) {
                case 0:
                    // 000
                    return LookupOpcode(O_MONITOR);
                case 1:
                    // 001
                    return LookupOpcode(O_MWAIT);
                default:
                    // Invalid
                    return 0;
            }
        }
    }

    return opcode;
}

// Protected helper functions

bool Decoder::CanFormat() const
{
    return m_pimpl->m_opcode != 0;
}

OpcodeType Decoder::GetOpcodeType() const
{
    return m_pimpl->m_opcode->op;
}

std::size_t Decoder::GetOperandCount() const
{
    return m_pimpl->m_opcode->GetOperandCount();
}

OperandType Decoder::GetOperandType(std::size_t index) const
{
    return m_pimpl->m_opcode->operands[index].otype;
}

DecodeMode Decoder::GetOperandDecodeMode() const
{
    return m_pimpl->m_dmOperand;
}

DecodeMode Decoder::GetAddressDecodeMode() const
{
    return m_pimpl->m_dmAddress;
}

const OperandValue & Decoder::GetOperandValue(std::size_t index) const
{
    assert(index < m_pimpl->m_opcode->GetOperandCount());
    return m_pimpl->m_values[index];
}

const Prefix & Decoder::GetPrefix(std::size_t index) const
{
    assert(index < m_pimpl->m_prefixes.size());
    return *(m_pimpl->m_prefixes[index]);
}

std::size_t Decoder::GetPrefixCount() const
{
    return m_pimpl->m_prefixes.size();
}

int Decoder::GetInstructionLength() const
{
    return m_pimpl->m_length;
}

}

// Internal functions
namespace
{

unsigned int GetMem16(const unsigned char *mem)
{
    return mem[0] + (mem[1] << 8);
}

unsigned int GetMem32(const unsigned char *mem)
{
    return mem[0] + (mem[1] << 8) + (mem[2] << 16) + (mem[3] << 24);
}

unsigned int GetMem(OperandType ot, const unsigned char **mem, std::size_t *length, DecodeMode dm)
{
    unsigned int i = 0;

    if (ot == OT_WORD_DWORD) {
        ot = dm == DM_16BIT ? OT_ABS_WORD : OT_ABS_DWORD;
    } else if (ot == OT_BYTE_WORD) {
        ot = dm == DM_16BIT ? OT_ABS_BYTE : OT_ABS_WORD;
    }

    switch (ot) {
        case OT_ABS_BYTE:
            if (*length >= 1) {
                i = **mem;
                (*mem)++;
                (*length)--;
            }
            break;
        case OT_ABS_DWORD:
            if (*length >= 4) {
                i = GetMem32(*mem);
                (*mem) += 4;
                (*length) -= 4;
            }
            break;
        case OT_ABS_WORD:
            if (*length >= 2) {
                i = GetMem16(*mem);
                (*mem) += 2;
                (*length) -= 2;
            }
            break;
        default:
            break;
    }

    return i;
}

Register GetGeneralRegister(std::size_t index, AddressingMode am, OperandType ot)
{
    static const Register regs_v[] = {
        REG_E_AX, REG_E_CX, REG_E_DX, REG_E_BX, REG_E_SP, REG_E_BP, REG_E_SI, REG_E_DI
    };
    static const Register regs_d[] = {
        REG_EAX, REG_ECX, REG_EDX, REG_EBX, REG_ESP, REG_EBP, REG_ESI, REG_EDI
    };
    static const Register regs_w[] = {
        REG_AX, REG_CX, REG_DX, REG_BX, REG_SP, REG_BP, REG_SI, REG_DI
    };
    static const Register regs_b[] = {
        REG_AL, REG_CL, REG_DL, REG_BL, REG_AH, REG_CH, REG_DH, REG_BH
    };
    static const Register regs_q1[] = {
        REG_XMM0, REG_XMM1, REG_XMM2, REG_XMM3,
        REG_XMM4, REG_XMM5, REG_XMM6, REG_XMM7
    };
    static const Register regs_q2[] = {
        REG_MM0, REG_MM1, REG_MM2, REG_MM3,
        REG_MM4, REG_MM5, REG_MM6, REG_MM7
    };

    switch (ot) {
        case OT_WORD_DWORD:
            return regs_v[index];
        case OT_ABS_DWORD:
            return regs_d[index];
        case OT_ABS_WORD:
            return regs_w[index];
        case OT_ABS_BYTE:
            return regs_b[index];
        case OT_128_DOUBLE:
        case OT_128_FLOAT:
        case OT_128_SCALAR:
        case OT_128_DOUBLE_SCALAR:
        case OT_ABS_QWORD:
        case OT_ABS_DQWORD:
            return am == AM_MODRM_MMX_MEMORY ? regs_q2[index] : regs_q1[index];
        default:
            break;
    }

    return REG_NONE;
}

Register GetSegmentRegister(std::size_t index)
{
    static const Register sreg[] = {
        REG_ES, REG_CS, REG_SS, REG_DS, REG_FS, REG_GS, REG_NONE, REG_NONE
    };
    return sreg[index];
}

Register GetXmmRegister(std::size_t index)
{
    static const Register xreg[] = {
        REG_XMM0, REG_XMM1, REG_XMM2, REG_XMM3, REG_XMM4, REG_XMM5, REG_XMM6, REG_XMM7
    };
    return xreg[index];
}

Register GetMmxRegister(std::size_t index, OperandType otype)
{
    static const Register mreg[] = {
        REG_MM0, REG_MM1, REG_MM2, REG_MM3, REG_MM4, REG_MM5, REG_MM6, REG_MM7
    };

    if (otype == OT_ABS_DQWORD)
        return GetXmmRegister(index);

    return mreg[index];
}

Register GetControlRegister(std::size_t index)
{
    static const Register creg[] = {
        REG_CR0, REG_CR1, REG_CR2, REG_CR3, REG_CR4, REG_CR5, REG_CR6, REG_CR7
    };
    return creg[index];
}

Register GetDebugRegister(std::size_t index)
{
    static const Register dreg[] = {
        REG_DR0, REG_DR1, REG_DR2, REG_DR3, REG_DR4, REG_DR5, REG_DR6, REG_DR7
    };
    return dreg[index];
}

Register GetTestRegister(std::size_t index)
{
    static const Register treg[] = {
        REG_TR0, REG_TR1, REG_TR2, REG_TR3, REG_TR4, REG_TR5, REG_TR6, REG_TR7
    };
    return treg[index];
}

}
