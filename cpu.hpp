#include <cstdint>
#include <bitset>
#include "memory.hpp"
#include "ram.hpp"

#ifndef CPU_HPP
#define CPU_HPP

// WIP
// TODO
// 1. Finish CPU instructions
// 2. Implement addressing modes
// 3. Test

class chip2A03 
{
  private:
    /* registers */
    uint8_t a;    // accumulator
    uint8_t x;    // index x
    uint8_t y;    // index y

    uint16_t pc;  // program counter
    uint8_t sp = 0xFF;   // stack pointer
   
    uint8_t flagRegisterStatus;

    int cycle;    // for cycle counting??

    // memory and memory access
    Ram ram;

    enum memAccessMode {
      read,
      write
    };

    uint8_t bus(memAccessMode mode, uint16_t address, uint8_t data);
    uint8_t readCpu(uint16_t address);
    void writeCpu(uint16_t address, uint8_t data);

    // for checking specific bits in instructions
    typedef std::bitset<sizeof(uint8_t)>Bits;
    
    // check position 7 in registers
    bool isASet = Bits(a).test(7);
    bool isXset = Bits(x).test(7);
    bool isYSet = Bits(y).test(7);
    
    enum class statusFlag {
      carry = 1 << 0,   // carry
      zero = 1 << 1,   // zerO
      interrupt = 1 << 2,   // interrupt disable
      decimal = 1 << 3,   // decimal
      break4 = 1 << 4,   // break
      unused = 1 << 5,   // unused
      overflow = 1 << 6,   // overflow
      negative = 1 << 7    // negative
    };

    /* previous entry: check the 1 and 0 in the future, NOTE there might be a problem here
     current: changed function but kept this to continue previous use. */
    enum flagStatus {
      unsetFlag,
      setFlag
    };

    // funcs to set flags
    void setStatusFlag(statusFlag sf, uint8_t value);
    void setCarry(uint8_t value);
    void setZero(uint8_t value);
    void setInterrupt(uint8_t value);
    void setDecimal(uint8_t value);
    void setBreak(uint8_t value);
    void setOverflow(uint8_t value);
    void setNegative(uint8_t value);

    // stack
    void popStack(uint8_t data);
    void pushStack(uint8_t data);

    /* addressing modes */
    enum addressingMode {
      implicit,
      accumulator,
      immediate,
      zeropage,
      zeropageX,
      zeropageY,
      absolute,
      absoluteX,
      absoluteY,
      relative,
      indirect,
      indirectX,
      indirectY
    };
   
    /* instructions */
    /* Option 1: make funcs of all instructions, and just match them
     * Option 2: store them in array like chip8, check architecture
     * Option 3: make struct and feed a decoder what it needs */
    void ADC();
    void AND(uint8_t data);   // done
    void ASL(uint8_t data);   // done
    void BCC();   // NOTE HOW DOES THIS WORK
    void BCS();
    void BEQ();
    void BIT(uint8_t data);   // done
    void BMI();
    void BNE();
    void BPL();
    void BRK();   // wip
    void BVC();    
    void BVS();
    void CLC();   // done
    void CLD();   // done
    void CLI();   // done
    void CLV();   // done
    void CMP(uint8_t data);   // done
    void CPX(uint8_t data);   // done
    void CPY(uint8_t data);   // done
    void DEC(uint8_t data);   // done
    void DEX();   // done
    void DEY();   // done
    void EOR(uint8_t data);   // done
    uint8_t INC(uint8_t data);    // done
    void INX();   // done
    void INY();   // done
    void JMP();
    void JSR();
    void LDA(uint8_t data);   // done 
    void LDX(uint8_t data);   // done
    void LDY(uint8_t data);   // done
    void LSR();
    void NOP();   // done
    void ORA(uint8_t data);   // done
    void PHA();
    void PHP();
    void PLA();
    void PLP();
    void ROL();
    void ROR();
    void RTI();
    void RTS();
    void SBC();
    void SEC();   // done
    void SED();   // done
    void SEI();   // done
    void STA();
    void STX();
    void STY();
    void TAX();   // done
    void TAY();   // done
    void TSX();   // done
    void TXA();   // done
    void TXS();   // done
    void TYA();   // done

  public:
    // both of these need work
    chip2A03();
    ~chip2A03();

};

#endif
