#include "cpu.hpp"
#include <cstdint>


chip2A03::chip2A03() {}

chip2A03::~chip2A03() {}

///////////////////////////////////////////////


/* red TODO:
* green Redo popstack, pushStack
 * green redo write and reads
 * instructions start/rewrite
 */
uint8_t chip2A03::popStack() {
  uint8_t temp;
  ram[SP] = temp;
  SP++;
  return temp;
}

void chip2A03::pushStack(uint8_t data) {
  // stack: 0x0100 - 0x01FF
  if(ram[SP] < ram[0x0100] || ram[SP] > ram[0x01FF]) {
    return;
  } else {
    data = ram[SP];
  }
  SP--;
}
//////* addressing modes *//////
// instructionExec(instruction ins, addressingMode md) {
// if(addressingMode == whatever) {
//    if(ins == INS) {
//      INS();
//    };
//   };
// };

//* instructions */////////////////////
// yellow NEW 
// stack instructions
void chip2A03::TSX() {
  SP = X;
  nes::setBit(SR, sFlags::negative);
  nes::setBit(SR, sFlags::zero);
}

void chip2A03::TXS() {
  X = SP;
}

void chip2A03::PHA() {
  pushStack(A);
}

void chip2A03::PHP() {
  nes::Register tempFlags;
  SR = tempFlags;
  nes::setBit(tempFlags, sFlags::brk);
  nes::setBit(tempFlags, sFlags::na);
  pushStack(uint8_t(tempFlags.to_ulong()));
}

void chip2A03::PLA() {
  A = popStack();
  nes::setBit(SR, sFlags::negative);
  nes::setBit(SR, sFlags::zero);
}

void chip2A03::PLP() {
  SR = popStack();
}

// NOTE what is going on here
void chip2A03::ADC(uint8_t data) {
  uint16_t sum = data + a + sflags[carry];
  sflags[carry] = sum & 0x100;
  sflags[overflow] = (a ^ sum) & (data ^ sum) & 0x80;
  a = sum;
  if(sflags[overflow] == x)
    sflags.set(carry, set);
  if(a == 0)
    sflags.set(zero, set);
  // missing overflow set
  if(isASet)
    sflags.set(negative, set);

}

// Logical AND
void chip2A03::AND(uint8_t data) {    // comes from memory
  a &= data;
  if(a == 0)
    sflags.set(zero, set);
  if(isASet)
    sflags.set(negative, set);
}

// Arithmetic shift left
void chip2A03::ASL(uint8_t data) {
  uint8_t dataBit7 = data & 0x80;
  data <<= 1;
  sflags.set(carry, dataBit7);
  if(a == 0)
    sflags.set(zero, set);
  if(isASet)
    sflags.set(negative, set);
}

// Bit Test: NOTE there might be a problem on how bits are being 
// delivered to the flag-set functions
void chip2A03::BIT(uint8_t data) {
  uint8_t bitTest;
  bitTest = a & data; 
  sflags.set(negative, (data & 0x80));
  sflags.set(overflow, (data & 0x70));
  if(bitTest == 0)
    sflags.set(zero, set);
}

void chip2A03::BRK() {
  pc++;
  // push pc to stack
  uint8_t registerStatusCopy = flagRegisterStatus;
  // push registerStatusCopy to stack
  // read and load IRQ into pc
}

void chip2A03::CLC() {
  sflags.set(carry, unset);
}

// Clear Decimal Mode
void chip2A03::CLD() {
  sflags.set(decimal, unset);
}

// Clear Interrupt Disable
void chip2A03::CLI() {
  sflags.set(interrupt, unset);
}

// Clear Overflow flag
void chip2A03::CLV() {
  sflags.set(overflow, unset);
}

void chip2A03::CMP(uint8_t data) {
  uint8_t result = a - data;
  if(a >= data) 
    sflags.set(carry, set);
  if(a == data)
    sflags.set(zero, set);
  if(result & 0x80)
    sflags.set(negative, set);
}

void chip2A03::CPX(uint8_t data) {
  uint8_t result = x - data;
  if(x >= data)
    sflags.set(carry, set);
  if(x == data)
    sflags.set(carry, set);
  if(result & 0x80)
    sflags.set(negative, set);
}

void chip2A03::CPY(uint8_t data) {
  uint8_t result = y - data;
  if(y >= data)
    sflags.set(carry, set);
  if(y == data)
    sflags.set(zero, set);
  if(result & 0x80)
    sflags.set(negative, set);
}

void chip2A03::DEC(uint8_t data) {
  data--;
  if(data == 0)
    sflags.set(zero, set);
  if(data & 0x80)
    sflags.set(negative, set);

}

// Decrement X Register
void chip2A03::DEX() {
  x--;
  if(x == 0)
    sflags.set(zero, set);
  if(isXset)
    sflags.set(negative, set);
}

// Decrement Y Register
void chip2A03::DEY() {
  y--;
  if(y == 0)
    sflags.set(zero, set);
  if(isYSet)
    sflags.set(negative, set);
}

void chip2A03::EOR(uint8_t data) {
  a ^= data;
  if(a == 0)
    sflags.set(zero, set);
  if(isASet)
    sflags.set(negative, set);
}

uint8_t chip2A03::INC(uint8_t data) {
  data++;
  if(data == 0) 
    sflags.set(zero, set);
  if(data & 0x80)
    sflags.set(negative, set);
  
  return data;
}

// Increment X Register
void chip2A03::INX() {
  x++;
  if(x == 0)
    sflags.set(zero, set);

  if(isXset)
    sflags.set(negative, set);
}

// Increment Y Register
void chip2A03::INY() {
  y++;
  if(y == 0)
    sflags.set(zero, set);

  if(isYSet)
    sflags.set(negative, set);
}

void chip2A03::JMP(uint16_t address) {
  pc = address;
}

void chip2A03::LDA(uint8_t data) {
  a = data;
  if(a == 0)
    sflags.set(zero, set);
  if(isASet)
    sflags.set(negative, set);
}

void chip2A03::LDX(uint8_t data) {
  x = data;
  if(x == 0)
    sflags.set(zero, set);
  if(isXset)
    sflags.set(negative, set);
}

void chip2A03::LDY(uint8_t data) {
  x = data;
  if(y == 0)
    sflags.set(zero, set);
  if(isYSet)
    sflags.set(negative, set);
}

void chip2A03::NOP() {
  pc++;
}

void chip2A03::ORA(uint8_t data) {
  a |= data;
  if(a == 0)
    sflags.set(zero, set);
  if(isASet)
    sflags.set(negative, set);
}

void chip2A03::RTS() {
  pc = popStack();
  pc |= popStack() << 8;
  ++pc;
}

// Set Carry Flag
void chip2A03::SEC() {
  sflags.set(carry, set);
}

// Set Decimal Flag
void chip2A03::SED() {
  sflags.set(decimal,set);
}

// Set Interrupt Disable
void chip2A03::SEI() {
  sflags.set(interrupt, set);
}

void chip2A03::STY() {
  
}

// Transfer Accumulator to X
void chip2A03::TAX() {
  x = a;
  if(x == 0)
    sflags.set(zero, set);

  if(isXset)
    sflags.set(negative, set);
}

// Transfer Accumulator to Y
void chip2A03::TAY() {
  y = a;
  if(y == 0)
    sflags.set(zero, set);

  if(isYSet)
    sflags.set(negative, set);
}

// Transfer Stack Pointer to X
void chip2A03::TSX() {
  sp = x;
  if(x == 0)
    sflags.set(zero, set);

  if(isXset)
    sflags.set(negative, set);

}

// Transfer X to Accumulator
void chip2A03::TXA() {
  a = x;
  if(a == 0)
    sflags.set(zero, set);
  if(isASet)
    sflags.set(negative, set);
}

// transfer X to Stack Pointer
void chip2A03::TXS() {
  x = sp;
}

// transfer Y to Accumulator
void chip2A03::TYA() {
  a = y;
  if(a == 0)
    sflags.set(zero, set);
  if(isASet)
    sflags.set(negative, set);
}


