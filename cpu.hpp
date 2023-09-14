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
   
    uint8_t flagRegisterStatus;
    
    enum class statusFlag {
      CARRY = 1 << 0,   // carry
      ZERO = 1 << 1,   // zerO
      INTERRUPT = 1 << 2,   // interrupt disable
      DECIMAL = 1 << 3,   // decimal
      BREAK = 1 << 4,   // break
      U = 1 << 5,   // unused
      OVERFLOW = 1 << 6,   // overflow
      NEGATIVE = 1 << 7    // negative
    };

    enum flagSet {
      SET = 0,
      UNSET = 1
    };


    // funcs to set flags
    // basically set every flag for future execution
    void setStatusFlag(statusFlag sf, flagSet fs);
    void setCarry(flagSet fs);
    void setZero(flagSet fs);
    void setInterrupt(flagSet fs);
    void setDecimal(flagSet fs);
    void setBreak(flagSet fs);
    void setOverflow(flagSet fs);
    void setNegative(flagSet fs);

    enum memoryAccessMode {
      READ,
      WRITE
    };

    /* addressing modes */

    /* instructions */



};

#endif
