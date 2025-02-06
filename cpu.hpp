 - 1;
 write(address, temp);#include <cstdint>
#include "tools.hpp"

#ifndef CPU_HPP
#define CPU_HPP

// WIP

class chip2A03 
{
private:
  /* registers */ 
  uint8_t A;
  uint8_t X;
  uint8_t Y;
  uint8_t PC;
  uint8_t SP;
  nes::Register SR;

  enum sFlags {
    carry = 0,
    zero = 1,
    interrupt = 2,
    decimal = 3,
    brk = 4,
    na = 5,
    overflow = 6,
    negative = 7
  }; // blue note: access them with SR[sFlags::carry]
  
    // memory and memory access
  nes::Memory ram;
  
  public:
 // memory methods
  uint8_t read(const uint16_t address) {
    return ram[address];
  };

  void write(const uint16_t address, uint8_t data) {
    ram[address] = data;
  }
    // stack
  // LIFO, 0x0100 - 0x01FF, grows down as values are pushed
  // blue when value is pushed: stored in address pointed by sp
  // then sp -1
  // when value is pulled, sp+1
    uint8_t popStack();
    void pushStack(uint8_t data);

    /* instructions */
    /* Option 1: make funcs of all instructions, and just match them
     * Option 2: store them in array like chip8, check architecture
     * Option 3: make struct and feed a decoder what it needs */
    void ADC(uint8_t data);   // done
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
    void DEC(uint16_t address);   // done
    void DEX();   // done
    void DEY();   // done
    void EOR(uint8_t data);   // done
    void INC(uint16_t address);    // done
    void INX();   // done
    void INY();   // done  
    void JMP(uint16_t address);
    void JSR();
    void LDA(uint16_t address);   // done 
    void LDX(uint16_t address);   // done
    void LDY(uint16_t address);   // done
    void LSR();
    void NOP();   // done
    void ORA(uint8_t data);   // done
    void PHA();   // done
    void PHP();   // done
    void PLA();   // done
    void PLP();   // done
    void ROL();
    void ROR();
    void RTI();
    void RTS();
    void SBC();
    void SEC();   // done
    void SED();   // done
    void SEI();   // done
    void STA(uint16_t address);
    void STX(uint16_t address);
    void STY(uint16_t address);
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
