#include "../../include/instructions/jzero.h"

Jzero::~Jzero() {
}

void Jzero::Execute() {
}

void Jzero::SetOperand(const std::string& operand) {
  if (std::regex_match(operand, Regex::Get().tag_operand))
    mode_ = TAG;
  else
    throw "MAL OPERANDO";

  operand_ = operand;
}

void Jzero::InitName() {
  name_ = "jzero";
}