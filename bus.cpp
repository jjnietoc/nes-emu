#include "ram.hpp"

uint8_t Bus::readCPU(uint16_t address) {
  return cpu.wRAM[address];
}

void Bus::writeCPU(uint16_t address, uint8_t data) {
  data = cpu.wRAM[address];
}
