#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include <stdint.h>

/* Trying out virtual classes  and make everything related to memory inherit from this */

class Memory 
{
  public:
    Memory();
    ~Memory();

    virtual uint8_t read(uint16_t address);
    virtual void write(uint16_t address, uint8_t data);
};

#endif
