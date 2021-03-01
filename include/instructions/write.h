#ifndef WRITE_H
#define WRITE_H

#include "instruction.h"

class Write : public Instruction {
 public:
  Write(Ram* ram);
  ~Write();

  void Execute();
  void SetOperand(const std::string& operand);

 protected:
  void InitName();
};

#endif