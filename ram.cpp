#include "ram.hpp"

// WIP
// TODO
// 1. Finish memory map when doing rest of the parts
// 2. Write address read/write for PPU, APU and cartdriges

uint8_t Ram::read(uint16_t address) {
  return wram[address];
}

void Ram::write(uint16_t address, uint8_t data) {
  data = wram[address];
}

