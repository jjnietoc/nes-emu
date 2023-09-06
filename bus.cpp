#include "bus.hpp"

void Bus::read(uint16_t addr) 
{
//  return addr;     has to return a place in ram, maybe a <std::vector> or <std::array>
}

void Bus::write(uint16_t addr, uint8_t data)
{
  addr = data;    // same as before, has to return a place in ram memory
}
