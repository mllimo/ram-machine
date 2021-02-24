#ifndef DIV_H
#define DIV_H

#include "instruction.h"

class Div : public Instruction {
 public:
  using Instruction::Instruction;
  ~Div();

  void Execute();
  void SetOperand(const std::string& operand);

};

#endif