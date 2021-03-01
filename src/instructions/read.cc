#include "../../include/instructions/read.h"

#include "../../include/ram.h"

Read::Read(Ram* ram) : Instruction(ram) {
  InitName();
}

Read::~Read() {
}

void Read::Execute() {
  int value;
  switch (mode_) {
    case POINTER:
      value = stoi(std::string(operand_.begin() + 1, operand_.end()));
      value = mediator_->registers_[value];
      break;

    case REGISTER:
      value = stoi(operand_);
      break;

    default:
      throw BadOperandException();
      break;
  }

  mediator_->registers_[value] = mediator_->input_tape_.Get();
  mediator_->input_tape_.MoveRight();
}

void Read::SetOperand(const std::string& operand) {
  if (std::regex_match(operand, Regex::Get().pointer_operand))
    mode_ = POINTER;
  else if (std::regex_match(operand, Regex::Get().register_operand))
    mode_ = REGISTER;
  else
    throw BadOperandException();

  operand_ = operand;
}

void Read::InitName() {
  name_ = "read";
}