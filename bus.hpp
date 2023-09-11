/* the CPU accesses memory using buses. The memory is divided into
three parts, ROM inside the cartridges, the CPU’s RAM and the I/O registers. The address
bus is used to set the address of the required location. The control bus is used to inform the
components whether the request is a read or a write. The data bus is used to read or write
the byte to the selected address. Note that ROM is read-only and is accessed via a MMC, to
allow bank switching to occur. The I/O registers are used to communicate with the other
components of the system, the PPU and the control devices */

#include <_types/_uint16_t.h>
#include <stdint.h>
#include <vector>

#ifndef BUS_HPP_
#define BUS_HPP_

//using Byte = uint8_t;
// using Address = uint16_t;

class Bus
{ 
  public:
    // constr and destr
    Bus();
    ~Bus();

    /* Bus should have RAM and the ability to write read, 2048 std::vect full of 0 first. Init as std::vect<2048, 0>
     * also good idea to abstract uint8_t to Byte, to ease readability */
    uint16_t read(uint16_t addr);
    void write(uint16_t addr, uint8_t data);

    private:
    
    // miror
    // check if read/write
    // setting address?
};

#endif
