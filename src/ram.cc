#include "../include/ram.h"

Ram::Ram() {
  BuildInstructionSet();
  program_counter_ = 0;
  stop_ = true;
}

Ram::Ram(const std::string& program_path) {
  BuildInstructionSet();
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

void Ram::BuildInstructionSet() {
  instruction_set_ = {
      {"load", [=]() -> Instruction* { return new Load(this); }},
      {"store", [=]() -> Instruction* { return new Store(this); }},
      {"add", [=]() -> Instruction* { return new Add(this); }},
      {"sub", [=]() -> Instruction* { return new Sub(this); }},
      {"div", [=]() -> Instruction* { return new Div(this); }},
      {"mult", [=]() -> Instruction* { return new Mult(this); }},
      {"write", [=]() -> Instruction* { return new Write(this); }},
      {"read", [=]() -> Instruction* { return new Read(this); }},
      {"jump", [=]() -> Instruction* { return new Jump(this); }},
      {"jzero", [=]() -> Instruction* { return new Jzero(this); }},
      {"jgtz", [=]() -> Instruction* { return new Jgtz(this); }},
      {"halt", [=]() -> Instruction* { return new Halt(this); }}};
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

void Ram::AddInstruction(std::pair<std::string, std::string> parsed, size_t counter) {
}

std::pair<std::string, std::string> Ram::ParseInstruction(const std::string& dirty_instruction) {
  std::smatch matchI;
  std::smatch matchO;
  std::string aux = dirty_instruction;
  std::string clean_instruction = dirty_instruction;
  std::string operand;
  Regex regex;

  std::regex_search(dirty_instruction, matchI, regex.instruction);
  aux.erase(aux.begin() + matchI.position(), aux.begin() + matchI.position() + matchI.length());
  clean_instruction = matchI[0];

  std::regex_search(aux, matchO, regex.operand);
  if (matchO.size() > 0)
    operand = matchO[0];

  return {clean_instruction, operand};
}

std::istream& operator>>(std::istream& is, Ram& ram) {
  std::string line;
  std::string label;
  Regex regex;
  size_t instruction_counter = 0;

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

    if (line.size() == 0) continue;
    ram.label_index_.insert({label, instruction_counter});
    ram.AddInstruction(ram.ParseInstruction(line), instruction_counter);
    ++instruction_counter;
  }

  return is;
}

std::ostream& operator<<(std::ostream& os, const Ram& ram) {
  return os;
}
