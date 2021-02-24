#ifndef JUMP_H
#define JUMP_H

#include "instruction.h"

class Jump : public Instruction {
 public:
  using Instruction::Instruction;
  ~Jump();

  virtual void Execute();
  virtual void SetOperand(const std::string& operand);

 protected:
  virtual void InitName();
};

#endif