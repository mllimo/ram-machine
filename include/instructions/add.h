#ifndef ADD_H
#define ADD_H

#include "instruction.h"

class Add : public Instruction {
 public:
  using Instruction::Instruction;
  ~Add();

  void Execute();
  void SetOperand(const std::string& operand);


};

#endif