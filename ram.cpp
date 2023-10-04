#include "ram.hpp"

uint8_t Ram::read(uint16_t address) {
  return wram[address];
}

void Ram::write(uint16_t address, uint8_t data) {
  data = wram[address];
}

