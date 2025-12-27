/**
 * @file runtime_poly.cc
 * @brief Implementation file for the Shape class hierarchy.
 */

#include "runtime_poly.h"


/**
 * @brief Draws the shape of a square.
 * 
 * This function outputs a message indicating that the shape is a square.
 * It is marked as noexcept, meaning it does not throw any exceptions.
 */
void Square::draw() noexcept
{
  std::cout << "The shape is square:" << "\n";
}

/**
 * @brief Draws the shape of the rectangle.
 * 
 * This function outputs a message indicating that the shape is a rectangle.
 * It is a noexcept function, meaning it guarantees not to throw any exceptions.
 */
void Rectangle::draw() noexcept
{
  std::cout << "The shape is Rectangle" << "\n";
}

/**
 * @brief Draws the shape of a Triangle.
 * 
 * This function outputs a message indicating that the shape is a Triangle.
 * It is a noexcept function, meaning it does not throw any exceptions.
 */
void Triangle::draw() noexcept
{
  std::cout << "The shape is Triangle" << "\n";
}