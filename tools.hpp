#include <bitset>

#ifndef TOOLS_HPP
#define TOOLS_HPP

namespace nes {
  // registers 
  typedef std::bitset<8>Register;
  typedef std::bitset<16>PC;

  constexpr bool isBitSet(Register reg, int pos);
}

#endif // !TOOLS_HPP

