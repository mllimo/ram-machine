#ifndef ADD_H
#define ADD_H

#include "instruction.h"

class Add : public Instruction {
 public:
  using Instruction::Instruction;
  ~Add();

  virtual void Execute();
  virtual void SetOperand(const std::string& operand);

 protected:
  virtual void InitName();
};

#endif