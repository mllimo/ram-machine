#include "../../include/instructions/halt.h"

#include "../../include/ram.h"

Halt::Halt(Ram* ram) : Instruction(ram) {
  InitName();
}

Halt::~Halt() {
}

void Halt::Execute() {
  mediator_->stop_ = true;
}

void Halt::SetOperand(const std::string& operand) {
  if (operand.size() != 0) throw "NO NECESITA ARGUMENTOS";
}

void Halt::InitName() {
  name_ = "halt";
}
