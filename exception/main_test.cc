#include "my_exception.h"
#include <vector>
#include <memory>

int main() {
  std::vector<std::unique_ptr<exception::Myexception>> vec_container;

  vec_container.emplace_back(new exception::RuntimeException("Runtime exception"));
  vec_container.emplace_back(new exception::InvalidArgumentsException("Invalid arrguments exception"));
  vec_container.emplace_back(new exception::OutofRangeException("Out of range xception"));

  for(const auto &ptr : vec_container){
    std::cout<<ptr->what()<<"\n";
  }
  return 0;
}