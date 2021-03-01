#ifndef MULT_H
#define MULT_H

#include "instruction.h"

class Mult : public Instruction {
 public:
  Mult(Ram* ram);
  ~Mult();

  void Execute();
  void SetOperand(const std::string& operand);

 protected:
  void InitName();
};

#endif