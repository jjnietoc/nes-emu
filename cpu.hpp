#include <_types/_uint8_t.h>
#include <stdint.h>
#include <array>

#ifndef CPU_HPP
#define CPU_HPP

class chip2A03 
{
  private:
  /* registers */
  uint8_t a;    // accumulator
  uint8_t x;    // index x
  uint8_t y;    // index y

  uint16_t pc;  // program counter
  uint8_t sp;   // stack pointer
    
  enum class statusFlags {
    c = 1 << 0,   // carry
    z = 1 << 1,   // zero
    i = 1 << 2,   // interrupt disable
    d = 1 << 3,   // decimal
    b = 1 << 4,   // break
    u = 1 << 5,   // unused
    v = 1 << 6,   // overflow
    n = 1 << 7    // negative
  };

  // funcs to set flags
    // basically set every flag for future execution

  enum memoryAccessMode {
      READ,
      WRITE
    };

  /* addressing modes */

  /* instructions */



};

#endif
