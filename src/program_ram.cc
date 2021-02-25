#include "../include/program_ram.h"

ProgramRam::~ProgramRam() {}

int ProgramRam::Run() {
  Ram ram(arg_[1]);
  ram.ImportInputTape(arg_[2]);
  ram.Run();
  ram.ImportInputTape(arg_[3]);
  std::cout << ram << std::endl;
  return 0;
}

void ProgramRam::ShowUsage() const {
  std::cout << "Forma de uso: ./ram_sim ram_program.ram input_tape.in output_tape.out debug\n"
            << "  - ram_program.ram: fichero con el programa RAM.\n"
            << "  - input_tape.in: fichero con el contenido de la cinta de entrada.\n"
            << "  - output_tape.out: fichero con el contenido de la cinta de salida\n"
            << "  - debug: Si el valor de este parámetro es 1, se presentará un menú de "
            << "características similares al siguiente figura y, permitirá ejecutar cada una de sus "
            << "opciones, mostrando en cada paso de ejecución la instrucción ejecutada y el estado de la máquina.\n";
}