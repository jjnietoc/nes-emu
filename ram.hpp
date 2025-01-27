#ifndef RAM_HPP_
#define RAM_HPP_

#include <cstdint>
#include "tools.hpp"

class Ram
{
  private:
  nes::Memory RAM;
  uint8_t wram[2048];   // cpu ram
  
  public:
  Ram();
  ~Ram();

  uint8_t read(uint16_t address);
  void write(uint16_t address, uint8_t data);
};

#endif
