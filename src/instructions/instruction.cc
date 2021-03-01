#include "../../include/instructions/instruction.h"
#include "../../include/ram.h"

Instruction::Instruction(Ram* mediator) {
  mediator_ = mediator;
}

Instruction::~Instruction() {
}

std::ostream& operator<<(std::ostream& os, const Instruction& instruction) {
  os << instruction.name_ << " " << instruction.operand_;
  return os;
}