#ifndef BUS_HPP_
#define BUS_HPP_

#include <memory>
#include <stdint.h>
#include "cpu.hpp"
#include "memory.hpp"
#include <vector>

class Bus: public Memory    // inherited from memory
{
  private: 
    chip2A03 cpu;
    /* also should have:
     * chipXXXX ppu
     * chipXXXX apu */
    
    std::array<uint8_t, 2048> wRAM;   // cpu ram

    int memory_size = 0;

    // create and fill array of pointer to Mem objects
    // to set them dyanmically depending on what cartdrige is in
    std::vector<std::unique_ptr<Memory>> handler;
    
    
    
  public:
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t data);

    void fillMemory();

    void writeMemory(uint16_t address, uint8_t data);
    void readMemory(uint16_t address);
};

#endif
