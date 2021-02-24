#ifndef HALT_H
#define HALT_H

#include "instruction.h"

class Halt : public Instruction {
 public:
  using Instruction::Instruction;
  ~Halt();

  void Execute();
  void SetOperand(const std::string& operand);

};

#endif