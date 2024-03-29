#include "../include/tape.h"

Tape::Tape() {
  head_index_ = 0;
}

Tape::~Tape() {}

void Tape::Add(int value) {
  // Excepcion
  tape_.push_back(value);
}

void Tape::Insert(int value) {
  // Excepcion
  tape_.insert(tape_.begin() + head_index_, value);
}

int Tape::Get() const {
  // Excepcion
  return tape_[head_index_];
}

void Tape::MoveRight() {
  // Excepcion
  ++head_index_;
}

void Tape::MoveLeft() {
  // Excepcion
  --head_index_;
}

std::ostream& operator<<(std::ostream& os, const Tape& tape) {
  size_t index = 0;
  os << "{";
  for (auto& value : tape.tape_)
    os << value << (index++ != tape.tape_.size() - 1 ? ", " : "");

  os << "}";
  return os;
}

std::istream& operator>>(std::istream& is, Tape& tape) {
  int input_value;
  while (!is.eof()) {
    is >> input_value;
    tape.tape_.push_back(input_value);
  }
  return is;
}