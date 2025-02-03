#include "my_exception.h"
#include <memory>
#include <vector>

/**
 * @brief Main function to test custom exceptions.
 * 
 * @return int Exit status.
 */
int main() {
  std::vector<std::unique_ptr<exception::Myexception>> vec_container;

  vec_container.emplace_back(
      new exception::RuntimeException("Runtime exception"));
  vec_container.emplace_back(
      new exception::InvalidArgumentsException("Invalid arguments exception"));
  vec_container.emplace_back(
      new exception::OutofRangeException("Out of range exception"));

  for (const auto &ptr : vec_container) {
    std::cout << ptr->what() << "\n";
  }
  return 0;
}