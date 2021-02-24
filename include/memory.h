#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <string>
#include <unordered_map>

template <typename Type>
class Memory {
 public:
  Type& operator[](size_t register_index);

  template <typename Other>
  friend std::ostream& operator<<(std::ostream& os, const Memory<Other>& memory);

 private:
  std::unordered_map<size_t, Type> table_;
};

typedef Memory<int> MemoryI;
typedef Memory<float> MemoryF;
typedef Memory<std::string> MemoryS;

template <typename Type>
Type& Memory<Type>::operator[](size_t register_index) {
  auto it = table_.find(register_index);
  if (it == table_.end())
    it = table_.insert({register_index, Type()}).first;
  return it->second;
}

template <typename Type>
std::ostream& operator<<(std::ostream& os, const Memory<Type>& memory) {
  os << "{\n";
  for (auto& pair : memory.table_)
    os << "r" << std::to_string(pair.first) << ": " << pair.second << std::endl;
  os << "}";
  return os;
}

#endif