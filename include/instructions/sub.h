#ifndef SUB_H
#define SUB_H

#include "instruction.h"

class Sub : public Instruction {
 public:
  using Instruction::Instruction;
  ~Sub();

  virtual void Execute();
  virtual void SetOperand(const std::string& operand);

 protected:
  virtual void InitName();
};

#endif