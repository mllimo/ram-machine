#ifndef STORE_H
#define STORE_H

#include "instruction.h"

class Store : public Instruction {
 public:
  using Instruction::Instruction;
  ~Store();

  void Execute();
  void SetOperand(const std::string& operand);

 protected:
  void InitName();
};

#endif