#include "../../include/instructions/store.h"

#include "../../include/ram.h"

Store::Store(Ram* ram) : Instruction(ram){
  InitName();
}

Store::~Store() {
}

void Store::Execute() {
  int value;
  switch (mode_) {
    case POINTER:
      value = stoi(std::string(operand_.begin() + 1, operand_.end()));
      value = mediator_->registers_[value];
      break;

    case REGISTER:
      value = stoi(operand_);
      break;
  }

  mediator_->registers_[value] = mediator_->registers_[0];
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