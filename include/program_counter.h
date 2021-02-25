#ifndef PROGRAM_COUNTER_H
#define PROGRAM_COUNTER_H

#include <iostream>
#include <utility>

class ProgramCounter {
 public:
  ProgramCounter();
  ~ProgramCounter();

  void Set(size_t adress);
  size_t Get();
  void operator++(int);

 private:
  std::pair<size_t, bool> adress_;  // direccion de instruccion, si se ha de incrementar el salto
};

#endif