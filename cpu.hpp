#include <stdint.h>
#include <array>
#include <bitset>
#include "ram.hpp"

#ifndef CPU_HPP
#define CPU_HPP

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

    // work ram for cpu
    RAM ram;

    // for checking specific bits in instructions
    typedef std::bitset<sizeof(uint8_t)>Bits;
    // check position 7 in registers
    bool isASet = Bits(a).test(7);
    bool isXset = Bits(x).test(7);
    bool isYSet = Bits(y).test(7);
    
    enum class statusFlag {
      CARRY = 1 << 0,   // carry
      ZERO = 1 << 1,   // zerO
      INTERRUPT = 1 << 2,   // interrupt disable
      DECIMAL = 1 << 3,   // decimal
      BREAK = 1 << 4,   // break
      U = 1 << 5,   // unused
      OVERFLOW = 1 << 6,   // overflow
      NEGATIVE = 1 << 7    // negative
    };

    // check the 1 and 0 in the future, NOTE there might be a problem here
    enum flagSet {
      SET = 1,
      UNSET = 0
    };

    // funcs to set flags
    void setStatusFlag(statusFlag sf, flagSet fs);
    void setCarry(flagSet fs);
    void setZero(flagSet fs);
    void setInterrupt(flagSet fs);
    void setDecimal(flagSet fs);
    void setBreak(flagSet fs);
    void setOverflow(flagSet fs);
    void setNegative(flagSet fs);

    enum memoryAccessMode {
      READ,
      WRITE
    };

    /* addressing modes */
    enum addressingMode {
      IMPLICIT,
      ACCUMULATOR,
      IMMEDIATE,
      ZEROPAGE,
      ZEROPAGEX,
      ZEROPAGEY,
      ABSOLUTE,
      ABSOLUTEX,
      ABSOLUTEY,
      RELATIVE,
      INDIRECT,
      INDIRECTX,
      INDIRECTY
    };

    // access memory map
    void memoryMap(addressingMode ad, uint16_t address, uint8_t data);

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


    //* ---- WIP ---- *//
    /* instructions */
    /* maybe create a struct for each instruction? 
     * containing the instruction, cycle, addressing mode
     * then a function can decode it and match it with whatever
     * NOTE consider this but not mandatory to implement. */
    struct instruction {
      
    };

    void decode(addressingMode am, instruction ins);    // ?????
    //* ------------- *//

  public:
    // both of these need work
    chip2A03();
    ~chip2A03();

};

#endif
