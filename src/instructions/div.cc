#include "../../include/instructions/div.h"

Div::~Div() {
}

void Div::Execute() {
}

void Div::SetOperand(const std::string& operand) {
  if (std::regex_match(operand, Regex::Get().literal_operand))
    mode_ = LITERAL;
  else if (std::regex_match(operand, Regex::Get().pointer_operand))
    mode_ = POINTER;
  else if (std::regex_match(operand, Regex::Get().register_operand))
    mode_ = REGISTER;
  else
    throw "MAL OPERANDO";

  operand_ = operand;
}

void Div::InitName() {
  name_ = "div";
}
