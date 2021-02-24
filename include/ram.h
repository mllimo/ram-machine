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
  Ram();
  Ram(const std::string& program_path);
  ~Ram();

  void Run();
  friend std::istream& operator>>(std::istream& is, const Ram& ram);

 private:
  Memory<int> registers_;
  Memory<Instruction> program_;
  size_t program_counter_;
  Tape input_tape_;
  Tape output_tape_;
};

#endif