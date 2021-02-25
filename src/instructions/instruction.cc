#include "../../include/instructions/instruction.h"
#include "../../include/ram.h"

Instruction::Instruction(Ram* mediator) {
  mediator_ = mediator;
  InitName();
}

Instruction::~Instruction() {
}

void Instruction::InitName() {
  name_ = "Unkwon";
}

std::ostream& operator<<(std::ostream& os, const Instruction& instruction) {
  os << instruction.name_ << " " << instruction.operand_;
  return os;
}