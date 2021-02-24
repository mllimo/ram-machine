#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>
#include "../ram.h"

class Instruction {
 public:
  Instruction(Ram& mediator);
  virtual ~Instruction();

 protected:
  class Ram* mediator_;
  std::string name_;

  virtual void InitName() = 0;
};

#endif