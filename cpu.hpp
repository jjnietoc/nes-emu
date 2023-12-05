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
    uint8_t a = 0x00;    // accumulator
    uint8_t x = 0x00;    // index x
    uint8_t y = 0x00;    // index y

    uint16_t pc = 0x0000;  // program counter
    uint8_t sp = 0x00;   // stack pointer
   
    uint8_t flagRegisterStatus = 0x00; // this should be another bitset?

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

// for checking specific bits in instructions
    typedef std::bitset<sizeof(uint8_t)>Bits;
    
    // check position 7 in registers
    bool isASet = Bits(a).test(7);
    bool isXset = Bits(x).test(7);
    bool isYSet = Bits(y).test(7);

    std::bitset<sizeof(uint8_t)> sflags;
    
    enum statusFlag : char {
      carry,   // carry
      zero,   // zero
      interrupt,   // interrupt disable
      decimal,   // decimal
      brk,   // break
      unused,   // unused
      overflow,   // overflow
      negative    // negative
    };

    /* previous entry: check the 1 and 0 in the future, NOTE there might be a problem here
     current: changed function but kept this to continue previous use. */
    enum flagStatus {
      unset,
      set
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
