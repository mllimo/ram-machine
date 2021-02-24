#ifndef SUB_H
#define SUB_H

#include "instruction.h"

class Sub : public Instruction {
 public:
  using Instruction::Instruction;
  ~Sub();

  void Execute();
  void SetOperand(const std::string& operand);

};

#endif