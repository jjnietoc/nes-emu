#include <bitset>

#ifndef TOOLS_HPP
#define TOOLS_HPP

namespace nes {
  // registers 
  typedef std::bitset<8>Register;
  typedef std::bitset<16>PC;
  typedef std::bitset<2048>Memory;

  inline constexpr bool isBitSet(const Register reg, const int pos) {
    return reg.test(pos);
  }  

  inline void setBit(Register reg, const int pos) {
    reg.set(pos, true);
  }

  inline void unsetBit(Register reg, const int pos) {
    reg.set(pos, false);
  }
  
  inline void shiftLeft(Register reg) {
    reg << 1;
  } 

  inline void shiftRight(Register reg) {
    reg >> 1;
  }

  // populate
}

#endif

