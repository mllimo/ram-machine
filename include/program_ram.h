#ifndef PROGRAM_RAM_H
#define PROGRAM_RAM_H

#include "program.h"
#include "ram.h"

class ProgramRam : public Program {
 public:
  friend class Instruction;
  using Program::Program;
  ~ProgramRam();

  int Run();
  void ShowUsage() const;
};

#endif