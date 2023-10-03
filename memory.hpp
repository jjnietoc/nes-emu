#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include <cstdint>

/* Trying out virtual classes  and make everything related to memory inherit from this */

class Memory 
{
  public:
    Memory();
    virtual ~Memory() {};

    virtual uint8_t read(uint16_t address) = 0;   // "= 0" makes the class abstract and the method pure virtual
    virtual void write(uint16_t address, uint8_t data) = 0;
};

#endif
