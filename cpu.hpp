#include <_types/_uint8_t.h>
#include <iostream>
#include <stdint.h>
#include "bus.hpp"

#ifndef cpu_hpp
#define cpu_hpp

const auto MEMORY_SIZE = 0xFFFF;

class Bus;

class CPU
{
private:
    Bus *bus;

public:
    /* --- registers --- */
    uint16_t pc;     // program counter
    uint8_t sp;      // stack pointer
    uint8_t a;       // accumulator
    uint8_t x;       // index register X
    uint8_t y;       // index register Y
    uint8_t p;    // Status Register
    
    

    /* --- flags --- */
    enum class ProcessorFlags // flags of processor status, bit 5 is unused
    {
      C = 1 << 0,   // Carry Flag
      Z = 1 << 1,   // Zero Flag
      I = 1 << 2,   // Interrupt Disable
      D = 1 << 3,   // Decimal Mode
      B = 1 << 4,   // Break Command
      U = 1 << 5,   // Unused
      V = 1 << 6,   // Overflow Flag
      N = 1 << 7    // Negative Flag
    };

    enum class AddressingMode 
    {
      Accumulator,
      Relative,
      Immediate,
      ZeroPage,
      ZeroPageX,
      ZeroPageY,
      Absolute,
      AbsoluteX,
      AbsoluteY,
      IndirectX,
      IndirectY,
    }



    /* flag functions for setting, unsetting and checking P flags */
   /* struct
    {
      uint8_t FlagValue = 0;

      void setFlagValue(ProcessorFlags flag)
      {
        FlagValue |= (int)flag;
      }

      void unsetFlagValue(ProcessorFlags flag)
      {
        FlagValue &= ~(int)flag;
      }

      bool flagValueIsSet(ProcessorFlags flag)
      {
        return (FlagValue & (int)flag) == (int)flag;
      }
    } ProcessorStatus; */

    
};


#endif /* cpu_hpp */
