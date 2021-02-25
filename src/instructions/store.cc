#include "../../include/instructions/store.h"

Store::~Store() {
}

void Store::Execute() {
}

void Store::SetOperand(const std::string& operand) {
  if (std::regex_match(operand, Regex::Get().pointer_operand))
    mode_ = POINTER;
  else if (std::regex_match(operand, Regex::Get().register_operand))
    mode_ = REGISTER;
  else
    throw "MAL OPERANDO";

  operand_ = operand;
}

void Store::InitName() {
  name_ = "store";
}