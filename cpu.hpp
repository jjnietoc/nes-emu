#ifndef cpu_hpp
#define cpu_hpp

#include <iostream>
#include <stdint.h>
#include "bus.hpp"

enum AdressingModes {
      Implicit,
      Accumulator,
      Immediate,
      ZeroPage,
      ZeroPageX,
      ZeroPageY,
      Absolute,
      AbsoluteX,
      AbsoluteY,
      Relative,
      Indirect,
      IndirectX,
      IndirectY
    };

class Bus;

class CPU
{
private:
    Bus *bus;

public:
    /* --- registers --- */
    uint16_t pc;     // program counter
    uint8_t sp;      // stack pointer
    uint8_t A;       // accumulator
    uint8_t X;       // index register X
    uint8_t Y;       // index register Y
    uint8_t P;    // Status Register

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

    /* --- addressing modes --- */
    void AM_IMP();
    void AM_ACC();
    void AM_IMM();
    void AM_ZP();
    void AM_ZPX();
    void AM_ZPY();
    void AM_ABS();
    void AM_ABSX();
    void AM_ABSY();
    void AM_REL();
    void AM_IND();
    void AM_INDX();
    void AM_INDY();


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
