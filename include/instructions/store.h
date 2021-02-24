#ifndef STORE_H
#define STORE_H

#include "instruction.h"

class Store : public Instruction {
 public:
  using Instruction::Instruction;
  ~Store();

  virtual void Execute();
  virtual void SetOperand(const std::string& operand);

 protected:
  virtual void InitName();
};

#endif