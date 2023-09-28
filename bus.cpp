#include "bus.hpp"

uint8_t Bus::readCPU(uint16_t address) {
  return wRAM[address];
}

void Bus::writeCPU(uint16_t address, uint8_t data) {
  data = wRAM[address];
}

// WIP
// TODO:
// - change this function to write only, this way we eliminate
//   the need to compare enums
// - create function for reading only
// needs to implement rest of the parts
void Bus::writeMemory(uint16_t address, uint8_t data) {
  if(address >= 0x0 & address < 0x07FF) {
      writeCPU(address, data);
    };

  // PPU
  if(address >= 0x2000 & address < 0x2007)
    return;

  // sound, joypads, sprites
  if(address >= 0x4000 & address < 0x401F)
    return;

  // cartdrige ram if present, wram
  if(address >= 0x6000 & address < 0x7FFF)
    return;

  // cartridge rom
  if(address >= 0x8000 & address < 0xFFFF)
    return;
}

void Bus::readMemory(uint16_t address) {
  if(address >= 0x0 & address < 0x07FF) {
    readCPU(address);
  }
  
  // PPU
  if(address >= 0x2000 & address < 0x2007)
    return;

  // sound, joypads, sprites
  if(address >= 0x4000 & address < 0x401F)
    return;

  // cartdrige ram if present, wram
  if(address >= 0x6000 & address < 0x7FFF)
    return;

  // cartridge rom
  if(address >= 0x8000 & address < 0xFFFF)
    return;

}
