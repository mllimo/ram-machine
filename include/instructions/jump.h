#ifndef JUMP_H
#define JUMP_H

#include "instruction.h"

class Jump : public Instruction {
 public:
  using Instruction::Instruction;
  ~Jump();

  void Execute();
  void SetOperand(const std::string& operand);

};

#endif