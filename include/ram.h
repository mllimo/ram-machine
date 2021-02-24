#ifndef RAM_H
#define RAM_H

#include <fstream>
#include <iostream>
#include <string>

#include "instructions/instruction.h"
#include "memory.h"
#include "tape.h"

class Ram {
 public:
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
  size_t program_counter_;
  Tape input_tape_;
  Tape output_tape_;
};

#endif