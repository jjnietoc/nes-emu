#ifndef cpu_hpp
#define cpu_hpp

#include <iostream>
#include <stack>
#include <stdint.h>

class CPU
{
private:
    // parts
    uint16_t pc;     // program counter
    uint8_t sp;      // stack pointer
    uint8_t A;       // accumulator
    uint8_t X;       // index register X
    uint8_t Y;       // index register Y
    // TODO:
    // procesor status P
}

#endif /* cpu_hpp */
