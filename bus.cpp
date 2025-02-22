#include "bus.hpp"

uint16_t nes::Bus::read(uint16_t const address) const {
  return ram[address];
} 

void nes::Bus::write(const uint16_t address, const uint8_t data) {
  ram[address] = data;
}


