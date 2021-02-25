#include "../../include/instructions/jump.h"

Jump::~Jump() {
}

void Jump::Execute() {
}

void Jump::SetOperand(const std::string& operand) {
  if (std::regex_match(operand, Regex::Get().tag_operand))
    mode_ = TAG;
  else
    throw "MAL OPERANDO";

  operand_ = operand;
}

void Jump::InitName() {
  name_ = "jump";
}