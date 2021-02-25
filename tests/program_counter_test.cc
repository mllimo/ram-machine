#include "../include/program_counter.h"

#include <gtest/gtest.h>

TEST(ProgramCounter, Constructor) {
  ProgramCounter program_counter;
  EXPECT_EQ(true, true);  // Si llega a esta linea funciona
}

TEST(ProgramCounter, OperatorMasMas) {
  ProgramCounter program_counter;
  program_counter++;
  program_counter++;

  EXPECT_EQ(true, program_counter.Get() == 2);

  program_counter.Set(0);
  program_counter++;
  EXPECT_EQ(true, program_counter.Get() == 0);

  program_counter++;
  EXPECT_EQ(true, program_counter.Get() == 1);
}
