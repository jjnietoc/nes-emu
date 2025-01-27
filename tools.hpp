#include <bitset>

#ifndef TOOLS_HPP
#define TOOLS_HPP

namespace nes {
  // registers 
  typedef std::bitset<8>Register;
  typedef std::bitset<16>PC;
  
  typedef std::bitset<2048>Memory;

  constexpr bool isBitSet(Register reg, int pos);
}

#endif

