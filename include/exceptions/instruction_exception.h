#ifndef INSTRUCTION_EXCEPTION_H
#define INSTRUCTION_EXCEPTION_H

#include <exception>
#include <string>

class InstructionException : public std::exception {
 public:
  InstructionException(const std::string& error) : std::exception(), error_(error) {}
  virtual const char* what() const noexcept override { return error_.c_str(); }

 protected:
  std::string error_;
};

class BadOperandException : public InstructionException {
 public:
  BadOperandException() : InstructionException(std::string()) {}
  virtual const char* what() const noexcept override { return "Bad operand"; }
};

class TagNotFoundException : public InstructionException {
 public:
  using InstructionException::InstructionException;
  virtual const char* what() const noexcept override {
    std::string error = "Tag " + error_ + " not found";
    return error.c_str();
  }
};

class BadNumberArgumentsException : public InstructionException {
 public:
  BadNumberArgumentsException(size_t current, size_t expected) : InstructionException("") {
    current_ = current;
    expected_ = expected;
  }
  virtual const char* what() const noexcept override {
    std::string error = "Bad number of arguments: Expected " + std::to_string(expected_) +
                        " had " + std::to_string(current_);
    return error.c_str();
  }

 private:
  size_t current_;
  size_t expected_;
};

#endif