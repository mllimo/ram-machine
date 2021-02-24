#include "../../include/instructions/instruction.h"

Instruction::Instruction(Ram* mediator, const std::string& operand) {
  mediator_ = mediator;
  operand_ = operand;
  InitName();
}

Instruction::~Instruction() {
}

void Instruction::InitName() {
}