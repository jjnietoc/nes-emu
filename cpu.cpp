#include "cpu.hpp"



chip2A03::chip2A03() {
  // ram from ram.hpp?
  // i/o
  // audio
  // mappers?
}

chip2A03::~chip2A03() {
  // delete?
};

//////* status flags functions and all *//////
void chip2A03::setStatusFlag(statusFlag sf, flagSet fs) {
  if(fs == UNSET)
    flagRegisterStatus &= ~int(sf);   // unset
  else
    flagRegisterStatus |= int(sf);    // set
};

void chip2A03::setCarry(flagSet fs) {
  setStatusFlag(statusFlag::CARRY, fs);
};

void chip2A03::setZero(flagSet fs) {
  setStatusFlag(statusFlag::ZERO, fs);
};

void chip2A03::setInterrupt(flagSet fs) {
  setStatusFlag(statusFlag::INTERRUPT, fs);
};

void chip2A03::setDecimal(flagSet fs) {
  setStatusFlag(statusFlag::DECIMAL, fs);
};

void chip2A03::setBreak(flagSet fs) {
  setStatusFlag(statusFlag::BREAK, fs);
};

void chip2A03::setOverflow(flagSet fs) {
  setStatusFlag(statusFlag::OVERFLOW, fs);
};

void chip2A03::setNegative(flagSet fs) {
  setStatusFlag(statusFlag::NEGATIVE, fs);
};

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
  setDecimal(UNSET);
}

// Clear Interrupt Disable
void chip2A03::CLI() {
  setInterrupt(UNSET);
};

// Clear Overflow flag
void chip2A03::CLV() {
  setOverflow(UNSET);
};

// Decrement X Register
void chip2A03::DEX() {
  x--;
  if(x == 0)
    setZero(SET);

  if(isXset)
    setNegative(SET);
};

// Decrement Y Register
void chip2A03::DEY() {
  y--;
  if(y == 0)
    setZero(SET);

  if(isYSet)
    setNegative(SET);
};

// Increment X Register
void chip2A03::INX() {
  x++;
  if(x == 0)
    setZero(SET);

  if(isXset)
    setNegative(SET);
};

// Increment Y Register
void chip2A03::INY() {
  y++;
  if(y == 0)
    setZero(SET);

  if(isYSet)
    setNegative(SET);
};

// Set Carry Flag
void chip2A03::SEC() {
  setCarry(SET);
};

// Set Decimal Flag
void chip2A03::SED() {
  setDecimal(SET);
};

// Set Interrupt Disable
void chip2A03::SEI() {
  setInterrupt(SET);
};

// Transfer Accumulator to X
void chip2A03::TAX() {
  x = a;
  if(x == 0)
    setNegative(SET);

  if(isXset)
    setNegative(SET);
};

// Transfer Accumulator to Y
void chip2A03::TAY() {
  y = a;
  if(y == 0)
    setZero(SET);

  if(isYSet)
    setNegative(SET);
}

// Transfer Stack Pointer to X
void chip2A03::TSX() {
  sp = x;
  if(x == 0)
    setZero(SET);

  if(isXset)
    setNegative(SET);

}

// Transfer X to Accumulator
void chip2A03::TXA() {
  a = x;
  if(a == 0)
    setZero(SET);
  if(isASet)
    setNegative(SET);
};

// transfer X to Stack Pointer
void chip2A03::TXS() {
  x = sp;
};

// transfer Y to Accumulator
void chip2A03::TYA() {
  a = y;
  if(a == 0)
    setZero(SET);
  if(isASet)
    setNegative(SET);
};


