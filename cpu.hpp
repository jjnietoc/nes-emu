#include <cstdint>
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

  nes::Register B;
  
  uint8_t flags[8]; 

  enum sFlags {
    carry = 0,
    zero = 1,
    interrupt = 2,
    decimal = 3,
    brk = 4,
    na = 5,
    overflow = 6,
    negative = 7
  };

    // memory and memory access
  nes::memory ram;
  nes::stack stack; 

  uint8_t memData;
  uint16_t memAddr;
  uint16_t memBrch;

  
  public:
  uint8_t popStack();
  void pushStack(uint8_t data);

  uint8_t getMemData();

  uint8_t ADC(); uint8_t AND(); uint8_t ASL(); uint8_t BCC();
  uint8_t BCS(); uint8_t BEQ(); uint8_t BIT(); uint8_t BMI();
  uint8_t BNE(); uint8_t BPL(); uint8_t BRK(); uint8_t BVC(); 
  uint8_t BVS(); uint8_t CLC(); uint8_t CLD(); uint8_t CLI();
  uint8_t CLV(); uint8_t CMP(); uint8_t CPX(); uint8_t CPY();
  uint8_t DEC(); uint8_t DEX(); uint8_t DEY(); uint8_t EOR();
  uint8_t INC(); uint8_t INX(); uint8_t INY(); uint8_t JMP();
  uint8_t JSR(); uint8_t LDA(); uint8_t LDX(); uint8_t LDY();
  uint8_t LSR(); uint8_t NOP(); uint8_t ORA(); uint8_t PHA();
  uint8_t PHP(); uint8_t PLA(); uint8_t PLP(); uint8_t ROL();
  uint8_t ROR(); uint8_t RTI(); uint8_t RTS(); uint8_t SBC();
  uint8_t SEC(); uint8_t SED(); uint8_t SEI(); uint8_t STA();
  uint8_t STX(); uint8_t STY(); uint8_t TAX(); uint8_t TAY();
  uint8_t TSX(); uint8_t TXA(); uint8_t TXS(); uint8_t TYA();
 
  // Addressing modes
  uint8_t IMP();	uint8_t IMM();	
	uint8_t ZP0();	uint8_t ZPX();	
	uint8_t ZPY();	uint8_t REL();
	uint8_t ABS();	uint8_t ABX();	
	uint8_t ABY();	uint8_t IND();	
	uint8_t IZX();	uint8_t IZY();

  public:
    // both of these need work
    chip2A03();
    ~chip2A03();

};

#endif
