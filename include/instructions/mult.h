#ifndef MULT_H
#define MULT_H

#include "instruction.h"

class Mult : public Instruction {
 public:
  using Instruction::Instruction;
  ~Mult();

  void Execute();
  void SetOperand(const std::string& operand);

};

#endif