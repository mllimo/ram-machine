#ifndef JUMP_H
#define JUMP_H

#include "instruction.h"

class Jump : public Instruction {
 public:
  Jump(Ram* ram);
  ~Jump();

  void Execute();
  void SetOperand(const std::string& operand);

 protected:
  void InitName();
};

#endif