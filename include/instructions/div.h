#ifndef DIV_H
#define DIV_H

#include "instruction.h"

class Div : public Instruction {
 public:
  Div(Ram* ram);
  ~Div();

  void Execute();
  void SetOperand(const std::string& operand);

 protected:
  void InitName();
};

#endif