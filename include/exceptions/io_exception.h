#ifndef IO_EXCEPTION_H
#define IO_EXCEPTION_H

#include <exception>
#include <string>

class IoException : public std::exception {
 public:
  IoException(const std::string& error) : std::exception(), error_(error) {}
  virtual const char* what() const noexcept override { return error_.c_str(); }

 protected:
  std::string error_;
};

class InputException : public IoException {
 public:
  using IoException::IoException;
  virtual const char* what() const throw() { return ("Error with " + error_ + " input file\n").c_str(); }
};

class OutputException : public IoException {
 public:
  using IoException::IoException;
  virtual const char* what() const throw() { return ("Error with " + error_ + " output file\n").c_str(); }
};

#endif