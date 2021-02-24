#ifndef REGULAR_EXPRESIONS_H
#define REGULAR_EXPRESIONS_H

#include <regex>
#include <string>

struct Regex {
  Regex() : instruction("load|store|add|sub|mult|div|head|read|write|jump|jgtz|jzero|halt"),
            comments(";.*[\r\n]*"),
            label("(\\w|\\d)+:") {
  }
  std::regex instruction;
  std::regex comments;
  std::regex label;
};

#endif