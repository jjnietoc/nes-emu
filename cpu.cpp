#include "cpu.hpp"
#include <algorithm>
#include <cstdint>
  
// Constuctor:
chip2A03::chip2A03() {}

// Destructor:
chip2A03::~chip2A03() {}

// Access memory
uint8_t chip2A03::read(uint16_t address) {
  return memory[address];
}

void chip2A03::write(uint16_t address, uint8_t data) {
  memory[address] = data;
}

void chip2A03::setZero(uint8_t reg) {
    flags[sFlags::zero] = reg == 0;
}

void chip2A03::setNeg(uint8_t reg) {
  flags[sFlags::negative] = (reg >> 7) & 1;  
}

// Access memory according to Addressing Mode
uint8_t chip2A03::getMemData() {
  if(!(lookupMatrix[opcode].addressmode == &chip2A03::IMP))
    memData = read(memAddr);
  return memData;
}

// Intructions:
uint8_t chip2A03::LDA() { 
  getMemData();
  A = memData; 
  setZero(A);
  setNeg(A);
  return 0;
} 

uint8_t chip2A03::LDX() {
  getMemData();
  X = memData;

  setZero(X);
  setNeg(X);
  return 0;
} 

uint8_t chip2A03::LDY() {
  getMemData();
  Y = memData;
  setZero(Y);
  setNeg(Y);
  return 0;
} 

uint8_t chip2A03::STA() {
  getMemData();


  memData = A;
  return 0;
}

uint8_t chip2A03::STX() {
  getMemData();
  memData = X;
  return 0;
}

uint8_t chip2A03::STY() {

  getMemData();
  memData = Y;
  return 0;
}

uint8_t chip2A03::TAX() {
  X = A;
  setZero(X);
  setNeg(X);
  return 0;
}

uint8_t chip2A03::TAY() {
  Y = A;
  setZero(Y);
  setNeg(Y);
  return 0;
}

uint8_t chip2A03::TSX() {
  X = stack.top();
  setZero(X);
  setNeg(X);
  return 0;
} 

uint8_t chip2A03::TXA() {
  A = X;
  setZero(A);
  setNeg(A);
  return 0;
}

uint8_t chip2A03::TXS() {
  stack.top() = X;
  return 0;
}


uint8_t chip2A03::TYA() {
  A = Y;
  setZero(A);
  setNeg(A);
  return 0;
} 

// stack instructions
uint8_t chip2A03::PHA() {
  stack.push(A);
  return 0;
}

uint8_t chip2A03::PHP() {
  uint8_t tempFlags[8];
  std::copy(flags, flags + 1, tempFlags);
  flags[sFlags::brk] = flags[sFlags::na] = 1;
  for(int i; i < sizeof(tempFlags); i++) {
    stack.push(tempFlags[i]);
  };
  return 0;
}

uint8_t chip2A03::PLA() {
  A = stack.top();
  setZero(A);
  setNeg(A);
  return 0;
}

uint8_t chip2A03::PLP() {
  nes::Register temp = stack.top();
  for(int i = 0; i < sizeof(temp); i++) {
    flags[i] = temp[i];
  }
  return 0;
}

// decremnents and increments
uint8_t chip2A03::DEC() {
  getMemData();
  memData = memData - 1; 
  setZero(memData);
  setNeg(memData);
  return 0;
}

uint8_t chip2A03::DEX() {
  X--;
  setZero(X);
  setNeg(X);
  return 0;
}

uint8_t chip2A03::DEY() {
   Y--;
  setZero(Y);
  setNeg(Y);
  return 0;
}

uint8_t chip2A03::INC() { 
  getMemData();
  memData = memData + 1;
  setZero(memData);
  setNeg(memData);
  return 0;
}

uint8_t chip2A03::INX() {
  X++;
  setZero(X);
  setNeg(X);
  return 0;
}

uint8_t chip2A03::INY() {
  Y++;
  setZero(Y);
  setNeg(Y);
  return 0;
} 

// arithmetic instructions
uint8_t chip2A03::ADC() {
  getMemData();
  auto result = A + memData + flags[sFlags::carry];
  flags[sFlags::carry] = result > 0xFF;
  setZero(result);
  flags[sFlags::overflow] = (result ^ A) & (result ^ memData) & 0x80;
  setNeg(result & 0x80);
  A = result;
  return 1;
}

uint8_t chip2A03::SBC() {
  getMemData();
  auto result = A - memData - ~(flags[sFlags::carry]);
  flags[sFlags::carry] = ~(result < 0x00);
  setNeg(result == 0);
  flags[sFlags::overflow] = (result ^ A) & (result ^ ~memData) & 0x80;
  setNeg(result & 0x80);
  return 1;
}

// logical operation instructions
uint8_t chip2A03::AND() {
  getMemData();
  A &= memData;
  setZero(A);
  setNeg(A);
  return 0;
}

uint8_t chip2A03::EOR() {
  getMemData();
  A ^= memData;
  setZero(A);
  setNeg(A);
  return 0;
}

uint8_t chip2A03::ORA() {
  getMemData();
  A |= memData;
  setZero(A);
  setNeg(A);
  return 0;
}

// orange shift operation instructions
uint8_t chip2A03::ASL() {
  getMemData();
  auto result = memData << 1;
  write(memAddr, result);
  flags[sFlags::carry] = memData & 0x80;
  setZero(result);
  setNeg(result);
  return 1;
}

uint8_t chip2A03::LSR() {
  getMemData();
  auto result = memData >> 1;
  write(memAddr, result);
  flags[sFlags::carry] = memData & 0x80;
  setZero(result);
  setNeg(result);
  return 1;
}
// flag instructions 
uint8_t chip2A03::CLC() {
  flags[sFlags::carry] = 0;
  return 0;
}

uint8_t chip2A03::CLD() {
  flags[sFlags::decimal] = 0;
  return 0;
}

uint8_t chip2A03::CLI() {
  flags[sFlags::interrupt] = 0;
  return 0;
}

uint8_t chip2A03::CLV() {
  flags[sFlags::overflow] = 0;
  return 0;
}

uint8_t chip2A03::SEC() {
  flags[sFlags::carry] = 1;
  return 0;
}

uint8_t chip2A03::SED() {
  flags[sFlags::decimal] = 1;
  return 0;
}

uint8_t chip2A03::SEI() {
  flags[sFlags::interrupt] = 1;
  return 0;
} 

// comparison instructions
uint8_t chip2A03::CMP() {
  getMemData();
  auto diff = A - memData;
  flags[sFlags::carry] = diff >= memData;
  setZero(diff);
  setNeg(diff);
  return 0;
} 

uint8_t chip2A03::CPX() {
  getMemData();
  auto diff = X - memData;
  flags[sFlags::carry] = diff >= memData;
  setZero(diff);
  setNeg(diff);
  return 0;
} 

uint8_t chip2A03::CPY() {
  getMemData();
  auto diff = Y - memData;
  flags[sFlags::carry] = diff >= memData;
  setZero(diff);
  setNeg(diff);
  return 0;
} 

uint8_t chip2A03::BRK() {
  return 0;
}

uint8_t chip2A03::BIT() {
  getMemData();
  auto operand = memData;
  flags[sFlags::zero] = !(operand & A);
  flags[sFlags::overflow] = (operand >> 6) & 1;
  flags[sFlags::negative] = (operand >> 7) & 1;
  return 0;
}

