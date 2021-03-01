#include "../../include/instructions/jzero.h"

#include "../../include/ram.h"

Jzero::Jzero(Ram* ram) : Instruction(ram){
  InitName();
}

Jzero::~Jzero() {
}

void Jzero::Execute() {
  if (mediator_->registers_[0] != 0) return;
  auto it = mediator_->tag_index_.find(operand_);
  if (it == mediator_->tag_index_.end()) throw TagNotFoundException(operand_);
  mediator_->program_counter_.Set(it->second);
}

void Jzero::SetOperand(const std::string& operand) {
  if (std::regex_match(operand, Regex::Get().tag_operand))
    mode_ = TAG;
  else
    throw BadOperandException();

  operand_ = operand;
}

void Jzero::InitName() {
  name_ = "jzero";
}