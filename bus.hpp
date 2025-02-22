#include <cstdint>
#include <array>

#ifndef BUS_HPP
#define BUS_HPP

namespace nes {

class Bus {
private:
  std::array <uint8_t, 0xFFFF> ram;  

public:
  uint16_t read(uint16_t const address) const;
  void write(const uint16_t address, const uint8_t data);
  };
}

#endif
