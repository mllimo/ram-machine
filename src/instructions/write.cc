#include "../../include/instructions/write.h"

#include "../../include/ram.h"

Write::Write(Ram* ram) : Instruction(ram) {
  InitName();
}

Write::~Write() {
}

void Write::Execute() {
  int value;
  switch (mode_) {
    case LITERAL:
      value = stoi(std::string(operand_.begin() + 1, operand_.end()));
      break;

    case POINTER:
      value = stoi(std::string(operand_.begin() + 1, operand_.end()));
      value = mediator_->registers_[value];
      if (value == 0) throw BadOperandException();
      value = mediator_->registers_[value];
      break;

    case REGISTER:
      value = stoi(operand_);
      if (value == 0) throw BadOperandException();
      value = mediator_->registers_[value];
      break;

    default:
      throw BadOperandException();
      break;
  }

  mediator_->output_tape_.Add(value);
  mediator_->output_tape_.MoveRight();
}

void Write::SetOperand(const std::string& operand) {
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

void Write::InitName() {
  name_ = "write";
}