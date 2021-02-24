#ifndef JGTZ_H
#define JGTZ_H

#include "instruction.h"

class Jgtz : public Instruction {
 public:
  using Instruction::Instruction;
  ~Jgtz();

  virtual void Execute();
  virtual void SetOperand(const std::string& operand);

 protected:
  virtual void InitName();
};

#endif