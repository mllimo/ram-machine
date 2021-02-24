#ifndef READ_H
#define READ_H

#include "instruction.h"

class Read : public Instruction {
 public:
  using Instruction::Instruction;
  ~Read();

  virtual void Execute();
  virtual void SetOperand(const std::string& operand);

 protected:
  virtual void InitName();
};

#endif