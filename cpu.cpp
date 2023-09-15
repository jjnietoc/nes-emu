#include "cpu.hpp"

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

