#ifndef RAM_HPP
#define RAM_HPP

#include <cstdint>
class ram {
private:

public:
  uint16_t read(uint16_t const address) const;
  void write(const uint16_t address, const uint8_t data);
};

#endif
