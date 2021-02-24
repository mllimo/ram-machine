#include "../include/ram.h"

Ram::Ram() {
  program_counter_ = 0;
  stop_ = true;
}

Ram::Ram(const std::string& program_path) {
  program_counter_ = 0;
  stop_ = true;
  std::fstream input(program_path, std::ios_base::in);
  if (!input.is_open()) throw;
  input >> *this;
  input.close();
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
  input.close();
}

void Ram::ExportOutputTape(const std::string& output_path) {
  std::fstream output(output_path, std::ios_base::out);
  if (!output.is_open()) throw;
  output << output_tape_;
  output.close();
}

void Ram::ParseInstruction(const std::string& instruction) {
  std::cout << instruction << std::endl;
}

std::istream& operator>>(std::istream& is, Ram& ram) {
  std::string line;
  std::string label;
  Regex regex;
  size_t lines = 0;
  while (std::getline(is, line)) {
    label = "";
    std::smatch matchC;
    std::smatch matchL;
    std::regex_search(line, matchC, regex.comments);  // Eliminamos comentarios
    line.erase(line.begin() + matchC.position(), line.begin() + matchC.position() + matchC.length());
    std::regex_search(line, matchL, regex.label);
    line.erase(line.begin() + matchL.position(), line.begin() + matchL.position() + matchL.length());
    if (matchL.size() > 0) {
      label = matchL[0];
      label.pop_back();
    }
    ram.label_index_.insert({label, lines++});
    ram.ParseInstruction(line);
  }

  return is;
}

std::ostream& operator<<(std::ostream& os, const Ram& ram) {
  return os;
}
