#include "../include/memory.h"

#include <gtest/gtest.h>

TEST(Memory, Constructor) {
  MemoryI memory_int;
  EXPECT_EQ(true, true);  // Si llega a esta linea funciona
}

TEST(Memory, Acceso) {
  MemoryI memory_int;
  memory_int[10] = 123;
  EXPECT_EQ(true, memory_int[10] == 123);  // Si llega a esta linea funciona
}

TEST(Memory, Pantalla) {
  MemoryI memory_int;
  memory_int[10] = 123;
  memory_int[1] = 13;
  std::cout << memory_int << std::endl;
}
