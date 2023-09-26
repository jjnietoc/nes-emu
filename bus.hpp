#ifndef RAM_HPP_
#define RAM_HPP_

#include <stdint.h>
#include "cpu.hpp"

class Bus 
{
  private: 
    chip2A03 cpu;
    /* also should have:
     * chipXXXX ppu
     * chipXXXX apu */
    
    std::array<uint8_t, 2048> wRAM;   // cpu ram
    enum memoryAccessMode {
      readMode,
      writeMode
    };
    
  public:
    uint8_t readCPU(uint16_t address);
    void writeCPU(uint16_t address, uint8_t data);

    void memoryMap(memoryAccessMode am, uint16_t address, uint8_t data);
};

#endif
