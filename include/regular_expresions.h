#ifndef REGULAR_EXPRESIONS_H
#define REGULAR_EXPRESIONS_H

#include <regex>
#include <string>

struct Regex {
  Regex() : instruction("load|store|add|sub|mult|div|head|read|write|jump|jgtz|jzero|halt"),
            comments(";.*[\r\n]*"),
            tag("(\\w|\\d)+:"),
            operand("(\\*|=)?\\d+|(\\w|\\d)+"),
            tag_operand("(\\w|\\d)+"),
            literal_operand("=(\\d+)"),
            register_operand("(\\d+)"),
            pointer_operand("\\*(\\d+)"){
  }

  static Regex Get() {
    static Regex THIS;
    return THIS;
  }

  std::regex instruction;
  std::regex comments;
  std::regex tag;
  std::regex operand;
  std::regex tag_operand;
  std::regex literal_operand;
  std::regex register_operand;
  std::regex pointer_operand;
};

#endif