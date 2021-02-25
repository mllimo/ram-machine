#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <regex>
#include <string>

#include "../regular_expresions.h"

enum OperandMode { LITERAL,
                   REGISTER,
                   POINTER,
                   TAG };


class Instruction {
 protected:
  class Ram* mediator_;

 public:
  Instruction(Ram* mediator);
  virtual ~Instruction();

  virtual void Execute() = 0;
  virtual void SetOperand(const std::string& operand) = 0;

  friend std::ostream& operator<<(std::ostream& os, const Instruction& instruction);

 protected:
  std::string name_;
  std::string operand_;
  OperandMode mode_;

  virtual void InitName();
};

#endif