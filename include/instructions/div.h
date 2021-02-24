#ifndef DIV_H
#define DIV_H

#include "instruction.h"

class Div : public Instruction {
 public:
  using Instruction::Instruction;
  ~Div();

  virtual void Execute();
  virtual void SetOperand(const std::string& operand);

 protected:
  virtual void InitName();
};

#endif