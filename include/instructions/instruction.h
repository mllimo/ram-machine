#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>

class Ram;

class Instruction {
 public:
  Instruction(Ram* mediator);
  virtual ~Instruction();

  virtual void Execute() = 0;
  virtual void SetOperand(const std::string& operand) = 0;

 protected:
  Ram* mediator_;
  std::string name_;
  std::string operand_;
};

#endif