#ifndef cpu_hpp
#define cpu_hpp

#include <iostream>
#include <stack>
#include <stdint.h>

class CPU
{
private:
    // parts
    uint16_t pc;     // program counter
    uint8_t sp;      // stack pointer
    uint8_t A;       // accumulator
    uint8_t X;       // index register X
    uint8_t Y;       // index register Y
    
    enum class ProcessorFlags // flags of processor status
    {
      C = 1 << 0,   // Carry Flag
      Z = 1 << 1,   // Zero Flag
      I = 1 << 2,   // Interrupt Disable
      D = 1 << 3,   // Decimal Mode
      B = 1 << 4,   // Break Command
      unused = 1 << 5,    // unused
      V = 1 << 6,   // Overflow Flag
      N = 1 << 7    // Negative Flag
    };

    struct ProcessorStatus    // struct for setting, unsetting and checking flags in P 
    {
      uint8_t FlagValue = 0;

      void SetFlagValue(ProcessorFlags flag)
      {
        FlagValue |= (int)flag;
      }

      void UnsetFlagValue(ProcessorFlags flag)
      {
        FlagValue &= ~(int)flag;
      }

      bool FlagValueIsSet(ProcessorFlags flag)
      {
        return (FlagValue & (int)flag) == (int)flag;
      }
    };

    
};

#endif /* cpu_hpp */
