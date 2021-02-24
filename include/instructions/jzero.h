#ifndef JZERO_H
#define JZERO_H

#include "instruction.h"

class Jzero : public Instruction {
 public:
  using Instruction::Instruction;
  ~Jzero();

  void Execute();
  void SetOperand(const std::string& operand);

};

#endif