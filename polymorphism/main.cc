#include "runtime_poly.h"
#include <vector>
#include <memory>

int main() {
  std::vector<std::unique_ptr<Shape>> vec_container;

  vec_container.emplace_back(std::make_unique<Square>());
  vec_container.emplace_back(std::make_unique<Rectangle>());
  vec_container.emplace_back(std::make_unique<Triangle>());

  for(const auto &ptr : vec_container){
    ptr->draw();
  }
  return 0;
}