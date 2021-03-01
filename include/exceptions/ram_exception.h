#ifndef RAM_EXCEPTION_H
#define RAM_EXCEPTION_H

#include <exception>
#include <string>

class RamException : public std::exception {
 public:
  RamException(const std::string& error) : std::exception(), error_(error) {}
  virtual const char* what() const noexcept override { return error_.c_str(); }

 protected:
  std::string error_;
};

#endif