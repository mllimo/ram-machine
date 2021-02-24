#ifndef TAPE_H
#define TAPE_H

#include <iostream>
#include <string>
#include <vector>

class Tape {
 public:
  Tape();
  ~Tape();

  void Add(int value);
  void Insert(int value);
  int Get() const;
  void MoveRight();
  void MoveLeft();

  friend std::ostream& operator<<(std::ostream& os, const Tape& tape);
  friend std::istream& operator>>(std::istream& is, Tape& tape);

 private:
  size_t head_index_;
  std::vector<int> tape_;
};

#endif