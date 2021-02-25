#include "../../include/instructions/read.h"

Read::~Read() {
}

void Read::Execute() {
}

void Read::SetOperand(const std::string& operand) {
  if (std::regex_match(operand, Regex::Get().pointer_operand))
    mode_ = POINTER;
  else if (std::regex_match(operand, Regex::Get().register_operand))
    mode_ = REGISTER;
  else
    throw "MAL OPERANDO";

  operand_ = operand;
}

void Read::InitName() {
  name_ = "read";
}