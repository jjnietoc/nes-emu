#include "cpu.hpp"



chip2A03::chip2A03() {
  // ram from ram.hpp?
  // i/o
  // audio
  // mappers?
  // init registers, pc, sp
}

chip2A03::~chip2A03() {
  // delete?
}

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

void chip2A03::memoryMirroring(uint16_t address, uint8_t data) {
  // how to implement this? 
}

// WIP
// needs to implement rest of the parts
// NOTE some of the gaps in memory are mirrored from other parts,
// if in the future this doesn't work, try and mirror them.
void chip2A03::memoryMap(addressingMode ad, uint16_t address, uint8_t data) {
  if(address >= 0x0 & address < 0x07FF) {
    if(ad == readMode) {
      ram.read(address);
    } else {
      ram.write(address, data);
    };
  }
  // cpu wram mirroring
  if(address >= 0x0800 & address < 0x0FFF)
    return;
  if(address >= 0x1000 & address < 0x17FF)
    return;
  if(address >= 0x1800 & address < 0x1FFF)
    return;

  // PPU
  if(address >= 0x2000 & address < 0x2007)
    return;

  // sound, joypads, sprites
  if(address >= 0x4000 & address < 0x401F)

  // cartdrige ram if present, wram
    return;
  if(address >= 0x6000 & address < 0x7FFF)
    return;

  // cartridge rom
  if(address >= 0x8000 & address < 0xFFFF)
    return;
}

///////////////////////////////////////////////

//////* addressing modes *//////
// instructionExec(instruction ins, addresssingMode md) {
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


