#include "../../include/instructions/halt.h"

Halt::~Halt() {
}

void Halt::Execute() {
}

void Halt::SetOperand(const std::string& operand) {
  if (operand.size() != 0) throw "NO NECESITA ARGUMENTOS";
}

void Halt::InitName() {
  name_ = "halt";
}
