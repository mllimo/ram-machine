#include "../include/tape.h"

#include <gtest/gtest.h>

TEST(Tape, Constructor) {
  Tape tape;
  EXPECT_EQ(true, true);  // Si llega a esta linea funciona
}

TEST(Tape, AddyGet) {
  Tape tape;
  tape.Add(2);
  EXPECT_EQ(true, 2 == tape.Get());
}

TEST(Tape, Insert) {
  Tape tape;
  tape.Add(2);
  tape.Insert(3);
  EXPECT_EQ(true, 3 == tape.Get());
}

TEST(Tape, MoveRight) {
  Tape tape;
  tape.Add(2);
  tape.Add(3);
  tape.MoveRight();
  EXPECT_EQ(true, 3 == tape.Get());
}

TEST(Tape, MoveLeft) {
  Tape tape;
  tape.Add(2);
  tape.Add(3);
  tape.MoveRight();
  tape.MoveLeft();
  EXPECT_EQ(true, 2 == tape.Get());
}

TEST(Tape, Pantalla) {
  Tape tape;
  tape.Add(2);
  tape.Add(3);
  tape.Add(5);
  tape.Add(6);
  std::cout << tape << std::endl;
  EXPECT_EQ(true, true);
}