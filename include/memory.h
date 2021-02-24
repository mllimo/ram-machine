#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

template <typename Type>
class Memory : std::vector<Type> {
 public:
  Memory();
  Memory(size_t size);
  ~Memory();
};

#endif