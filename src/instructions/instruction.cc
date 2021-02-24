#include "../../include/instructions/instruction.h"

Instruction::Instruction(Ram& mediator) {
  mediator_ = &mediator;
  InitName();
}

Instruction::~Instruction() {
}