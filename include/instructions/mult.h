#ifndef MULT_H
#define MULT_H

#include "instruction.h"

class Mult : public Instruction {
 public:
  using Instruction::Instruction;
  ~Mult();

  virtual void Execute();
  virtual void SetOperand(const std::string& operand);

 protected:
  virtual void InitName();
};

#endif