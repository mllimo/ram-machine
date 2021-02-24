#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>

class Ram;

class Instruction {
 public:
  Instruction(Ram* ram, const std::string& operand);
  virtual ~Instruction();

  virtual void Execute() = 0;

 protected:
  Ram* mediator_;
  std::string name_;
  std::string operand_;

  virtual void InitName();
};

#endif