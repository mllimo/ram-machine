#include "../../include/instructions/load.h"

#include "../../include/ram.h"

Load::Load(Ram* ram) : Instruction(ram) {
  InitName();
}

Load::~Load() {
}

void Load::Execute() {
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

    default:
      throw BadOperandException();
      break;
  }

  mediator_->registers_[0] = value;
}

void Load::SetOperand(const std::string& operand) {
  if (std::regex_match(operand, Regex::Get().literal_operand))
    mode_ = LITERAL;
  else if (std::regex_match(operand, Regex::Get().pointer_operand))
    mode_ = POINTER;
  else if (std::regex_match(operand, Regex::Get().register_operand))
    mode_ = REGISTER;
  else
    throw BadOperandException();

  operand_ = operand;
}

void Load::InitName() {
  name_ = "load";
}