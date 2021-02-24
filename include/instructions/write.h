#ifndef WRITE_H
#define WRITE_H

#include "instruction.h"

class Write : public Instruction {
 public:
  using Instruction::Instruction;
  ~Write();

  virtual void Execute();
  virtual void SetOperand(const std::string& operand);

 protected:
  virtual void InitName();
};

#endif