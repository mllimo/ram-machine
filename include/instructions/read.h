#ifndef READ_H
#define READ_H

#include "instruction.h"

class Read : public Instruction {
 public:
  Read(Ram* ram);
  ~Read();

  void Execute();
  void SetOperand(const std::string& operand);

 protected:
  void InitName();
};

#endif