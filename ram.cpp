#include "ram.hpp"

uint8_t RAM::read(uint16_t address) {
  return ram[address];
}

uint8_t RAM::write(uint16_t address, uint8_t data) {
  return ram[address] = data;
}