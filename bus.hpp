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
    
  public:
    uint8_t readCPU(uint16_t address);
    void writeCPU(uint16_t address, uint8_t data);
};

#endif
