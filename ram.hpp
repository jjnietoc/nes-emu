#ifndef BUS_HPP_
#define BUS_HPP_

#include <memory>
#include <cstdint>
#include "memory.hpp"
#include <vector>

class Ram: public Memory    // inherited from memory
{
  private: 
    uint8_t wram[2048];   // cpu ram

  public:
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t data);
};

#endif
