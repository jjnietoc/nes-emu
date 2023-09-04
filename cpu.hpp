#ifndef cpu_hpp
#define cpu_hpp

#include <iostream>
#include <stdint.h>

class CPU
{
private:
    /* --- registers --- */
    uint16_t pc;     // program counter
    uint8_t sp;      // stack pointer
    uint8_t A;       // accumulator
    uint8_t X;       // index register X
    uint8_t Y;       // index register Y

    /* --- flags --- */
    enum class ProcessorFlags // flags of processor status, bit 5 is unused
    {
      Carry = 1 << 0,   // Carry Flag
      Zero = 1 << 1,   // Zero Flag
      InterruptDisable = 1 << 2,   // Interrupt Disable
      Ddecimal = 1 << 3,   // Decimal Mode
      Break = 1 << 4,   // Break Command
      Overflow = 1 << 6,   // Overflow Flag
      Negative = 1 << 7    // Negative Flag
    };


  public:
    /* flag functions for setting, unsetting and checking P flags */
    struct
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
    } ProcessorStatus;

    
};

#endif /* cpu_hpp */
