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

  friend std::ostream& operator<<(std::ostream& os, const Instruction& instruction);

 protected:
  Ram* mediator_;
  std::string name_;
  std::string operand_;

  virtual void InitName();
};

#endif