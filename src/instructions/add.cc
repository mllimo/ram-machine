#include "../../include/instructions/add.h"

Add::~Add() {
}

void Add::Execute() {
}

void Add::SetOperand(const std::string& operand) {
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

void Add::InitName() {
  name_ = "add";
}
