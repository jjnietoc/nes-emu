#include "cpu.hpp"
#include <algorithm>
#include <cstdint>

// Constuctor:
chip2A03::chip2A03() {}

// Destructor:
chip2A03::~chip2A03() {}

// Intructions:
uint8_t chip2A03::LDA() { 
  A = ram[PC];
  return 0;
} // red

uint8_t chip2A03::LDX() {
  X = ram[PC];
  return 0;
} // red

uint8_t chip2A03::LDY() {
  Y = ram[PC];
  return 0;
} // red

uint8_t chip2A03::STA() {
  ram[PC] = A;
  return 0;
} // red

uint8_t chip2A03::STX() {
  ram[PC] = X;
  return 0;
} // red

uint8_t chip2A03::STY() {
  ram[PC] = Y;
  return 0;
} // red

uint8_t chip2A03::TAX() {
  X = A;
  flags[sFlags::negative] = flags[sFlags::zero] = X;
  return 0;
}

uint8_t chip2A03::TAY() {
  Y = A;
  flags[sFlags::negative] = flags[sFlags::zero] = Y;
  return 0;
}

uint8_t chip2A03::TSX() {
  ram[SP] = X;
  flags[sFlags::negative] = flags[sFlags::zero] = X;
  return 0;
} // red

uint8_t chip2A03::TXA() {
  A = X;
  flags[sFlags::negative] = flags[sFlags::zero] = A;
  return 0;
}

uint8_t chip2A03::TXS() {
  X = ram[SP];
  flags[sFlags::negative] = flags[sFlags::zero] = X;
  return 0;
} // red

uint8_t chip2A03::TYA() {
  A = Y;
  flags[sFlags::negative] = flags[sFlags::zero] = A;
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
  flags[sFlags::brk] = flags[sFlags::na] = A;
  return 0;
}

uint8_t chip2A03::PLP() {
  // purple no error, but does this work?
  nes::Register temp = stack.top();
  for(int i = 0; i < sizeof(temp); i++) {
    flags[i] = temp[i];
  }
  return 0;
}

// decremnents and increments
uint8_t chip2A03::DEC() {
  PC--; 
  flags[sFlags::zero] = flags[sFlags::negative] = PC; // purple check
  return 0;
}

uint8_t chip2A03::DEX() {
  X--;
  flags[sFlags::zero] = flags[sFlags::negative] = X;
  return 0;
}

uint8_t chip2A03::DEY() {
   Y--;
  flags[sFlags::zero] = flags[sFlags::negative] = X;
  return 0;
}

uint8_t chip2A03::INC() {
  PC++;
  flags[sFlags::zero] = flags[sFlags::negative] = PC;
  return 0;
}

uint8_t chip2A03::INX() {
  X++;
  flags[sFlags::zero] = flags[sFlags::negative] = X;
  return 0;
}

uint8_t chip2A03::INY() {
  Y++;
  flags[sFlags::zero] = flags[sFlags::negative] = Y;
  return 0;
} 

// red todo: arithmetic instructions

// logical operation instructions
uint8_t chip2A03::AND() {
  A &= ram[PC];
  flags[sFlags::zero] = flags[sFlags::negative] = A;
  return 0;
} // red


uint8_t chip2A03::EOR() {
  A ^= ram[PC];
  flags[sFlags::zero] = flags[sFlags::negative] = A;
  return 0;
} // red

uint8_t chip2A03::ORA() {
  A |= ram[PC];
  flags[sFlags::zero] = flags[sFlags::negative] = A;
  return 0;
} // red

// red shift operation instructions

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
  auto diff = A - ram[PC];
  //  red how to set flags[sFlags::carry] 
  flags[sFlags::zero] = flags[sFlags::negative] = diff;
  return 0;
} // red

uint8_t chip2A03::CPX() {
  auto diff = X - ram[PC];
  // red set carry missing
  flags[sFlags::zero] = flags[sFlags::negative] = diff;
  return 0;
} // red

uint8_t chip2A03::CPY() {
  auto diff = Y - ram[PC];
  flags[sFlags::zero] = flags[sFlags::negative] = diff;
  return 0;
} // red

uint8_t chip2A03::BRK() {
  return 0;
}

uint8_t chip2A03::BIT() {
  auto operand = ram[PC];
  flags[sFlags::zero] = !(operand & A);
  flags[sFlags::overflow] = (operand >> 6) & 1;
  flags[sFlags::negative] = (operand >> 7) & 1;
  return 0;
} // red

