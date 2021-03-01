#ifndef JZERO_H
#define JZERO_H

#include "instruction.h"

class Jzero : public Instruction {
 public:
  Jzero(Ram* ram);
  ~Jzero();

  void Execute();
  void SetOperand(const std::string& operand);

 protected:
  void InitName();
};

#endif