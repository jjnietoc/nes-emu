#include <cstdint>
#include <bitset>
#include "memory.hpp"
#include "ram.hpp"
#include "tools.hpp"

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
  // TODO how is their starting state?
  nes::Register A;
  nes::Register X;
  nes::Register Y;
  nes::Register SP;
  nes::PC PC;
  
  nes::Register Flags; 

  uint8_t fetchData = 0x00;    // for global data usage
  uint16_t temp = 0x0000;    // for global usage 
  uint16_t addr = 0x0000;    // for memory addresses
  uint16_t addr_brch = 0x00;    // for memory following branch
  uint8_t opcode = 0x00;   // instruction
  uint8_t cyle = 0;    // cycle count
  uint32_t clock = 0;   // number of clocks

    // memory and memory access
  Ram ram;

  enum memAccessMode {
      read,
      write
    };
  
  public:
    uint8_t fetchInstruction();

    uint8_t bus(memAccessMode mode, uint16_t address, uint8_t data);
    uint8_t readCpu(uint16_t address);
    void writeCpu(uint16_t address, uint8_t data);
    
    // stack
    uint8_t popStack();
    void pushStack(uint8_t data);

    // addressing modes
    uint16_t addrImmediate();
    uint16_t addrZeroPage();
    uint16_t addrZeroPageX();
    uint16_t addrZeroPageY();
    uint16_t addrRelative();
    uint16_t addrAbsolute();
    uint16_t addrAbsoluteX();
    uint16_t addrAbsoluteY();
    uint16_t addrIndirect();
    uint16_t addrIndexIndirect();
    uint16_t addrIndirectIndex();

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
    void DEC(uint8_t data);   // done
    void DEX();   // done
    void DEY();   // done
    void EOR(uint8_t data);   // done
    uint8_t INC(uint8_t data);    // done
    void INX();   // done
    void INY();   // done  
    void JMP(uint16_t address);
    void JSR();
    void LDA(uint8_t data);   // done 
    void LDX(uint8_t data);   // done
    void LDY(uint8_t data);   // done
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
