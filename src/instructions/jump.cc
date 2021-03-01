#include "../../include/instructions/jump.h"

#include "../../include/ram.h"

Jump::Jump(Ram* ram) : Instruction(ram){
  InitName();
}

Jump::~Jump() {
}

void Jump::Execute() {
  auto it = mediator_->tag_index_.find(operand_);
  if (it == mediator_->tag_index_.end()) throw "NO SE ENCUENTRA LA ETIQUETA";
  mediator_->program_counter_.Set(it->second);
}

void Jump::SetOperand(const std::string& operand) {
  if (std::regex_match(operand, Regex::Get().tag_operand))
    mode_ = TAG;
  else
    throw "MAL OPERANDO";

  operand_ = operand;
}

void Jump::InitName() {
  name_ = "jump";
}