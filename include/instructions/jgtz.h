#ifndef JGTZ_H
#define JGTZ_H

#include "instruction.h"

class Jgtz : public Instruction {
 public:
  using Instruction::Instruction;
  ~Jgtz();

  void Execute();
  void SetOperand(const std::string& operand);

};

#endif