#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>

class Ram;

class Instruction {
 public:
  Instruction(Ram* mediator);
  Instruction(Ram* mediator, const std::string& operand);
  virtual ~Instruction();

  virtual void Execute() = 0;
  virtual void SetOperand(const std::string& operand);

 protected:
  Ram* mediator_;
  std::string name_;
  std::string operand_;

  virtual void InitName();
};

#endif