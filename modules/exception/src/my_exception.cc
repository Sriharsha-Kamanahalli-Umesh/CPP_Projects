#include "my_exception.h"

namespace exception {

/**
 * @brief Constructor for RuntimeException.
 * @param str Error message.
 */
RuntimeException::RuntimeException(const char *str) : string_(str) {}

/**
 * @brief Constructor for InvalidArgumentsException.
 * @param str Error message.
 */
InvalidArgumentsException::InvalidArgumentsException(const char *str)
    : string_(str) {}

/**
 * @brief Constructor for OutofRangeException.
 * @param str Error message.
 */
OutofRangeException::OutofRangeException(const char *str) : string_(str) {}

/**
 * @brief Get the error message for RuntimeException.
 * @return const char* Error message.
 */
const char *RuntimeException::what() const noexcept { return string_.c_str(); }

/**
 * @brief Get the error message for InvalidArgumentsException.
 * @return const char* Error message.
 */
const char *InvalidArgumentsException::what() const noexcept {
  return string_.c_str();
}

/**
 * @brief Get the error message for OutofRangeException.
 * @return const char* Error message.
 */
const char *OutofRangeException::what() const noexcept {
  return string_.c_str();
}

} // namespace exception
