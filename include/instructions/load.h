#ifndef LOAD_H
#define LOAD_H

#include "instruction.h"

class Load : public Instruction {
 public:
  using Instruction::Instruction;
  ~Load();

  void Execute();
  void SetOperand(const std::string& operand);

 protected:
  void InitName();
};

#endif