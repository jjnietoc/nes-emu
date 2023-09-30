#ifndef BUS_HPP_
#define BUS_HPP_

#include <stdint.h>
#include "cpu.hpp"
#include "memory.hpp"

class Bus: public Memory    // inherited from memory
{
  private: 
    chip2A03 cpu;
    /* also should have:
     * chipXXXX ppu
     * chipXXXX apu */
    
    std::array<uint8_t, 2048> wRAM;   // cpu ram
    
  public:
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t data);

    void writeMemory(uint16_t address, uint8_t data);
    void readMemory(uint16_t address);
};

#endif
