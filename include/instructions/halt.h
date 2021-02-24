#ifndef HALT_H
#define HALT_H

#include "instruction.h"

class Halt : public Instruction {
 public:
  using Instruction::Instruction;
  ~Halt();

  virtual void Execute();
  virtual void SetOperand(const std::string& operand);

 protected:
  virtual void InitName();
};

#endif