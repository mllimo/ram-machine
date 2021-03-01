#ifndef HALT_H
#define HALT_H

#include "instruction.h"

class Halt : public Instruction {
 public:
  Halt(Ram* ram);
  ~Halt();

  void Execute();
  void SetOperand(const std::string& operand);

 protected:
  void InitName();
};

#endif