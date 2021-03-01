#ifndef PROGRAM_RAM_H
#define PROGRAM_RAM_H

#include "program.h"
#include "exceptions/instruction_exception.h"
#include "exceptions/ram_exception.h"
#include "exceptions/io_exception.h"
#include "ram.h"

class ProgramRam : public Program {
 public:
  using Program::Program;
  ~ProgramRam();

  int Run();
  void ShowUsage() const;
};

#endif