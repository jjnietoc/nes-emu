#include "cpu.hpp"
#include <cstdint>


chip2A03::chip2A03() {
  // ram from ram.hpp?
  // i/o
  // audio
  // mappers?
  // init registers, pc, sp
  
}

chip2A03::~chip2A03() {
  // delete?
  // should be deep delete
}

// Memory and memory access
uint8_t chip2A03::readCpu(uint16_t address) {
  return bus(memAccessMode::read, address, 0);
}

void chip2A03::writeCpu(uint16_t address, uint8_t data) {
  bus(memAccessMode::write, address, data);
}

uint8_t chip2A03::bus(memAccessMode mode, uint16_t address, uint8_t data) {
  uint8_t readData = 0;

  if(address >= 0 && address < 0x2000) {
    if(mode == memAccessMode::read) {
      readData = ram.read(address);
    } else {
      ram.write(address, data);
    }
  } else if(address >= 0x2000 && address < 0x4000) {
    if(mode == memAccessMode::read) {
      readData = 0;   // ppu read
    } else {
      readData = 0;  // ppu write
    }
  } else if(address >= 0x4000 && address < 0x4001) {
      if(mode == memAccessMode::read) {
        readData = 0;   // controller read
      } else {
        readData = 0;   // controller write
      }
  } else if(address >= 0x6000 && address < 0xFFFF) {
      if(mode == memAccessMode::read) {
      readData = 0;   // rom read
    } else {
      readData = 0;   // rom write
    }
  }
  return readData;
};

//////* status flags functions and all *//////
void chip2A03::setStatusFlag(statusFlag sf, flagStatus fs) {
  if(fs == unsetFlag)
    flagRegisterStatus &= ~int(sf);   // unset
  else
    flagRegisterStatus |= int(sf);    // set
}

void chip2A03::setCarry(flagStatus fs) {
  setStatusFlag(statusFlag::carry, fs);
}

void chip2A03::setZero(flagStatus fs) {
  setStatusFlag(statusFlag::zero, fs);
}

void chip2A03::setInterrupt(flagStatus fs) {
  setStatusFlag(statusFlag::interrupt, fs);
}

void chip2A03::setDecimal(flagStatus fs) {
  setStatusFlag(statusFlag::decimal, fs);
}

void chip2A03::setBreak(flagStatus fs) {
  setStatusFlag(statusFlag::break4, fs);
}

void chip2A03::setOverflow(flagStatus fs) {
  setStatusFlag(statusFlag::overflow, fs);
}

void chip2A03::setNegative(flagStatus fs) {
  setStatusFlag(statusFlag::negative, fs);
}




///////////////////////////////////////////////

//////* addressing modes *//////
// instructionExec(instruction ins, addressingMode md) {
// if(addressingMode == whatever) {
//    if(ins == INS) {
//      INS();
//    };
//   };
// };

//* instructions *//

// Clear Decimal Mode
void chip2A03::CLD() {
  setDecimal(unsetFlag);
}

// Clear Interrupt Disable
void chip2A03::CLI() {
  setInterrupt(unsetFlag);
}

// Clear Overflow flag
void chip2A03::CLV() {
  setOverflow(unsetFlag);
}

// Decrement X Register
void chip2A03::DEX() {
  x--;
  if(x == 0)
    setZero(setFlag);

  if(isXset)
    setNegative(setFlag);
}

// Decrement Y Register
void chip2A03::DEY() {
  y--;
  if(y == 0)
    setZero(setFlag);

  if(isYSet)
    setNegative(setFlag);
}

// Increment X Register
void chip2A03::INX() {
  x++;
  if(x == 0)
    setZero(setFlag);

  if(isXset)
    setNegative(setFlag);
}

// Increment Y Register
void chip2A03::INY() {
  y++;
  if(y == 0)
    setZero(setFlag);

  if(isYSet)
    setNegative(setFlag);
}

// Set Carry Flag
void chip2A03::SEC() {
  setCarry(setFlag);
}

// Set Decimal Flag
void chip2A03::SED() {
  setDecimal(setFlag);
}

// Set Interrupt Disable
void chip2A03::SEI() {
  setInterrupt(setFlag);
}

// Transfer Accumulator to X
void chip2A03::TAX() {
  x = a;
  if(x == 0)
    setNegative(setFlag);

  if(isXset)
    setNegative(setFlag);
}

// Transfer Accumulator to Y
void chip2A03::TAY() {
  y = a;
  if(y == 0)
    setZero(setFlag);

  if(isYSet)
    setNegative(setFlag);
}

// Transfer Stack Pointer to X
void chip2A03::TSX() {
  sp = x;
  if(x == 0)
    setZero(setFlag);

  if(isXset)
    setNegative(setFlag);

}

// Transfer X to Accumulator
void chip2A03::TXA() {
  a = x;
  if(a == 0)
    setZero(setFlag);
  if(isASet)
    setNegative(setFlag);
}

// transfer X to Stack Pointer
void chip2A03::TXS() {
  x = sp;
}

// transfer Y to Accumulator
void chip2A03::TYA() {
  a = y;
  if(a == 0)
    setZero(setFlag);
  if(isASet)
    setNegative(setFlag);
}


