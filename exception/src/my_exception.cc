#include "my_exception.h"

namespace exception {

RuntimeException::RuntimeException(const char *str) : string_(str) {}

InvalidArgumentsException::InvalidArgumentsException(const char *str)
    : string_(str) {}

OutofRangeException::OutofRangeException(const char *str) : string_(str) {}

const char *RuntimeException::what() const noexcept { return string_.c_str(); }

const char *InvalidArgumentsException::what() const noexcept {
  return string_.c_str();
}

const char *OutofRangeException::what() const noexcept {
  return string_.c_str();
}

} // namespace exception
