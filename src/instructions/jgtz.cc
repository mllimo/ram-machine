#include "../../include/instructions/jgtz.h"
#include "../../include/ram.h"

Jgtz::~Jgtz() {
}

void Jgtz::Execute() {
  if (mediator_->registers_[0] <= 0) return;
  auto it = mediator_->tag_index_.find(operand_);
  if (it == mediator_->tag_index_.end()) throw "NO SE ENCUENTRA LA ETIQUETA";
  mediator_->program_counter_.Set(it->second);
}

void Jgtz::SetOperand(const std::string& operand) {
  if (std::regex_match(operand, Regex::Get().tag_operand))
    mode_ = TAG;
  else 
    throw "MAL OPERANDO";

  operand_ = operand;
}

void Jgtz::InitName() {
  name_ = "jgtz";
}