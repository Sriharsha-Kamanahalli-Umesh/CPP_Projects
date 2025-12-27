/**
 * @file runtime_poly.h
 * @brief Header file defining the Shape class hierarchy for runtime polymorphism.
 */

#include <iostream>

/**
 * @brief Abstract base class representing a generic shape.
 */
class Shape
{
public:
  /**
   * @brief Pure virtual function to draw the shape.
   */
  virtual void draw() noexcept = 0;

  /**
   * @brief Virtual destructor for the Shape class.
   */
  virtual ~Shape()
  {
    std::cout << "Shape Destructor is called:" << "\n";
  }
};

/**
 * @brief Derived class representing a square.
 */
class Square : public Shape
{
public:
  /**
   * @brief Draws the square.
   */
  void draw() noexcept override;

  /**
   * @brief Destructor for the Square class.
   */
  ~Square() override
  {
    std::cout << "Square Destructor is called:" << "\n";
  }
};

/**
 * @brief Derived class representing a rectangle.
 */
class Rectangle : public Shape
{
public:
  /**
   * @brief Draws the rectangle.
   */
  void draw() noexcept override;

  /**
   * @brief Destructor for the Rectangle class.
   */
  ~Rectangle() override
  {
    std::cout << "Rectangle Destructor is called:" << "\n";
  }
};

/**
 * @brief Derived class representing a triangle.
 */
class Triangle : public Shape
{
public:
  /**
   * @brief Draws the triangle.
   */
  void draw() noexcept override;

  /**
   * @brief Destructor for the Triangle class.
   */
  ~Triangle() override
  {
    std::cout << "Triangle Destructor is called:" << "\n";
  }
};