#include "../../include/instructions/jzero.h"

#include "../../include/ram.h"

Jzero::~Jzero() {
}

void Jzero::Execute() {
  if (mediator_->registers_[0] != 0) return;
  auto it = mediator_->tag_index_.find(operand_);
  if (it == mediator_->tag_index_.end()) throw "NO SE ENCUENTRA LA ETIQUETA";
  mediator_->program_counter_.Set(it->second);
}

void Jzero::SetOperand(const std::string& operand) {
  if (std::regex_match(operand, Regex::Get().tag_operand))
    mode_ = TAG;
  else
    throw "MAL OPERANDO";

  operand_ = operand;
}

void Jzero::InitName() {
  name_ = "jzero";
}