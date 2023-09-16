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
      SET,
      UNSET
    };

    // funcs to set flags
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
    enum addressingMode {
      IMPLICIT,
      ACCUMULATOR,
      IMMEDIATE,
      ZEROPAGE,
      ZEROPAGEX,
      ZEROPAGEY,
      ABSOLUTE,
      ABSOLUTEX,
      ABSOLUTEY,
      RELATIVE,
      INDIRECT,
      INDIRECTX,
      INDIRECTY
    };

    /* instructions */
    /* Option 1: make funcs of all instructions, and just match them
     * Option 2: store them in array like chip8, check architecture
     * Option 3: make struct and feed a decoder what it needs */

    //* ---- WIP ---- *//
    /* instructions */
    /* maybe create a struct for each instruction? 
     * containing the instruction, cycle, addressing mode
     * then a function can decode it and match it with whatever
     * NOTE consider this but not mandatory to implement. */
    struct instruction {
      
    };

    void decode(addressingMode am, instruction ins);    // ?????
    //* ------------- *//

  public:
    // both of these need work
    chip2A03();
    ~chip2A03();

};

#endif
