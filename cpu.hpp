#include <stdint.h>
#include <bitset>
// #include "bus.hpp"

#ifndef CPU_HPP
#define CPU_HPP

// WIP
// TODO
// 1. Finish CPU instructions
// 2. Implement addressing modes
// 3. Test

class Bus;

class chip2A03 
{
  private:
    /* registers */
    uint8_t a;    // accumulator
    uint8_t x;    // index x
    uint8_t y;    // index y

    uint16_t pc;  // program counter
    uint8_t sp;   // stack pointer
   
    uint8_t flagRegisterStatus;

    int cycle;

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

    // check the 1 and 0 in the future, NOTE there might be a problem here
    enum flagStatus {
      setFlag = 1,
      unsetFlag = 0
    };

    // funcs to set flags
    void setStatusFlag(statusFlag sf, flagStatus fs);
    void setCarry(flagStatus fs);
    void setZero(flagStatus fs);
    void setInterrupt(flagStatus fs);
    void setDecimal(flagStatus fs);
    void setBreak(flagStatus fs);
    void setOverflow(flagStatus fs);
    void setNegative(flagStatus fs);


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
    void AND();
    void ASL();
    void BCC();
    void BCS();
    void BEQ();
    void BIT();
    void BMI();
    void BNE();
    void BPL();
    void BRK();
    void BVC();
    void BVS();
    void CLC();
    void CLD();   // done
    void CLI();   // done
    void CLV();   // done
    void CMP();
    void CPX();
    void DEC();
    void DEX();   // done
    void DEY();   // done
    void EOR();
    void INC();
    void INX();   // done
    void INY();   // done
    void JMP();
    void JSR();
    void LDA();
    void LDX();
    void LDY();
    void LSR();
    void NOP();
    void ORA();
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
