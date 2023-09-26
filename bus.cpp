#include "bus.hpp"

uint8_t Bus::readCPU(uint16_t address) {
  return wRAM[address];
}

void Bus::writeCPU(uint16_t address, uint8_t data) {
  data = wRAM[address];
}


// WIP
// TODO:
// - change this function to write only, this way we eliminate the need to compare enums
// - create function for reading only
// needs to implement rest of the parts
void Bus::memoryMap(memoryAccessMode am, uint16_t address, uint8_t data) {
  if(address >= 0x0 & address < 0x07FF) {
    if(am == readMode) {
      readCPU(address % 2048);
    } else {
      writeCPU(address, data);
    };
  }
  // cpu wram mirroring
  if(address >= 0x0800 & address < 0x0FFF)
    return;
  if(address >= 0x1000 & address < 0x17FF)
    return;
  if(address >= 0x1800 & address < 0x1FFF)
    return;

  // PPU
  if(address >= 0x2000 & address < 0x2007)
    return;

  // sound, joypads, sprites
  if(address >= 0x4000 & address < 0x401F)

  // cartdrige ram if present, wram
    return;
  if(address >= 0x6000 & address < 0x7FFF)
    return;

  // cartridge rom
  if(address >= 0x8000 & address < 0xFFFF)
    return;
}
