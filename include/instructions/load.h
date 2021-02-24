#ifndef LOAD_H
#define LOAD_H

#include "instruction.h"

class Load : public Instruction {
 public:
  using Instruction::Instruction;
  ~Load();

  virtual void Execute();
  virtual void SetOperand(const std::string& operand);

 protected:
  virtual void InitName();
};

#endif