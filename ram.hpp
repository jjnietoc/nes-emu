#ifndef RAM_HPP_
#define RAM_HPP_

#include <stdint.h>

//* NOTE this is RAM accessible only to CPU *//

class RAM 
{
  private: 
    uint8_t ram[2048] = {0};

  public:
    uint8_t read(uint16_t address);
    uint8_t write(uint16_t address, uint8_t data);
  };

#endif
