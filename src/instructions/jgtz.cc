#include "../../include/instructions/jgtz.h"

Jgtz::~Jgtz() {
}

void Jgtz::Execute() {
}

void Jgtz::SetOperand(const std::string& operand) {
  if (std::regex_match(operand, Regex::Get().tag_operand))
    mode_ = TAG;
  else 
    throw "MAL OPERANDO";

  operand_ = operand;
}

void Jgtz::InitName() {
  name_ = "jgtz";
}