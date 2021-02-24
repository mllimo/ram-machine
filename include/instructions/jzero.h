#ifndef JZERO_H
#define JZERO_H

#include "instruction.h"

class Jzero : public Instruction {
 public:
  using Instruction::Instruction;
  ~Jzero();

  virtual void Execute();
  virtual void SetOperand(const std::string& operand);

 protected:
  virtual void InitName();
};

#endif