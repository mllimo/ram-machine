#include "../include/program_counter.h"

ProgramCounter::ProgramCounter() {
  adress_.first = 0;
  adress_.second = false;
}

ProgramCounter::~ProgramCounter() {}

void ProgramCounter::Set(size_t adress) {
  adress_.first = adress;
  adress_.second = true;
}

size_t ProgramCounter::Get() {
  return adress_.first;
}

void ProgramCounter::operator++(int) {
  if (adress_.second != true)
    ++adress_.first;
  else
    adress_.second = false;
}