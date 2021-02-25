#ifndef RAM_H
#define RAM_H

#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

#include "instructions/instruction_header.h"
#include "program_counter.h"
#include "memory.h"
#include "regular_expresions.h"
#include "tape.h"

class Ram {
 public:
  friend class Instruction;
  Ram();
  Ram(const std::string& program_path);
  ~Ram();

  void Run();
  void ImportInputTape(const std::string& input_path);
  void ExportOutputTape(const std::string& output_path);
  friend std::ostream& operator<<(std::ostream& os, const Ram& ram);
  friend std::istream& operator>>(std::istream& is, Ram& ram);

 private:
  Memory<int> registers_;
  Memory<Instruction*> program_;
  ProgramCounter program_counter_;
  Tape input_tape_;
  Tape output_tape_;
  bool stop_;
  size_t instructions_executed_;

  std::unordered_map<std::string, size_t> tag_index_;
  std::unordered_map<std::string, std::function<Instruction*(void)>> instruction_set_;

  void BuildInstructionSet();
  void AddInstructionProgram(std::pair<std::string, std::string> parsed, size_t counter);
  std::pair<std::string, std::string> ParseInstruction(const std::string& dirty_instruction);
};

#endif