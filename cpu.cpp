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
