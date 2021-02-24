#ifndef READ_H
#define READ_H

#include "instruction.h"

class Read : public Instruction {
 public:
  using Instruction::Instruction;
  ~Read();

  void Execute();
  void SetOperand(const std::string& operand);

};

#endif