/**
 * @file test_runtime_poly.cc
 * @brief Test file for the Shape class hierarchy.
 */

#include "runtime_poly.h"
#include <memory>
#include <vector>

/**
 * @brief Main function to test the Shape class hierarchy.
 * 
 * This function creates a vector of unique pointers to Shape objects,
 * adds different shapes to the vector, and calls the draw method on each shape.
 * 
 * @return int Returns 0 on successful execution.
 */
int main()
{
  std::vector<std::unique_ptr<Shape>> vec_container;

  vec_container.emplace_back(std::make_unique<Square>());
  vec_container.emplace_back(std::make_unique<Rectangle>());
  vec_container.emplace_back(std::make_unique<Triangle>());

  for (const auto &ptr : vec_container)
  {
    ptr->draw();
  }
  return 0;
}