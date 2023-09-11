#include "bus.hpp"

uint16_t Bus::read(uint16_t addr) 
{
  return busRam[addr];
}

void Bus::write(uint16_t addr, uint8_t data)
{
  data = busRam[addr];
}


