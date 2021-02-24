#include <iostream>
#include "../include/program_ram.h"

int main(int argc, char const *argv[]) {
  ProgramRam program(argc, argv);
  return program.Run();
}
