#include "../../include/instructions/div.h"

#include "../../include/ram.h"

Div::~Div() {
}

void Div::Execute() {
  int value;
  switch (mode_) {
    case LITERAL:
      value = stoi(std::string(operand_.begin() + 1, operand_.end()));
      break;

    case POINTER:
      value = stoi(std::string(operand_.begin() + 1, operand_.end()));
      value = mediator_->registers_[value];
      value = mediator_->registers_[value];
      break;

    case REGISTER:
      value = stoi(operand_);
      value = mediator_->registers_[value];
      break;
  }

  if (value == 0) throw "DIVISION ENTRE CERO";
  mediator_->registers_[0] /= value;
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
