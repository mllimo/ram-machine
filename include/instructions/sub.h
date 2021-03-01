#ifndef SUB_H
#define SUB_H

#include "instruction.h"

class Sub : public Instruction {
 public:

  Sub(Ram* ram);
  ~Sub();

  void Execute();
  void SetOperand(const std::string& operand);

 protected:
  void InitName();
};

#endif