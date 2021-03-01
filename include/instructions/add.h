#ifndef ADD_H
#define ADD_H

#include "instruction.h"

class Add : public Instruction {
 public:
  Add(Ram* ram);
  ~Add();

  void Execute();
  void SetOperand(const std::string& operand);

 protected:
  void InitName();
};

#endif