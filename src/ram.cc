#include "../include/ram.h"

Ram::Ram(const std::string& program_path) {
  program_counter_ = 0;
}

Ram::~Ram() {
  for (auto& instruction : program_.GetTable())
    if (instruction.second != NULL) {
      delete instruction.second;
      instruction.second = NULL;
    }
}

void Ram::Run() {
}

void Ram::ImportInputTape(const std::string& input_path) {
  std::fstream input(input_path, std::ios_base::in);
  if (!input.is_open()) throw;
  input >> input_tape_;
}

void Ram::ExportOutputTape(const std::string& output_path) {
  std::fstream output(output_path, std::ios_base::out);
  if (!output.is_open()) throw;
  output << output_tape_;
}

std::istream& operator>>(std::istream& is, Ram& ram) {
  return is;
}

std::ostream& operator<<(std::ostream& os, const Ram& ram) {
  return os;
}
