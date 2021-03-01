#ifndef JGTZ_H
#define JGTZ_H

#include "instruction.h"

class Jgtz : public Instruction {
 public:
  Jgtz(Ram* ram);
  ~Jgtz();

  void Execute();
  void SetOperand(const std::string& operand);

 protected:
  void InitName();
};

#endif