#include <iostream>

/**
 * @brief A class that implements a stack using a dynamic array.
 * 
 * @tparam T The type of the elements in the stack.
 */
template <typename T>
class Stack
{
public:
  /**
   * @brief Constructs a new Stack object.
   */
  Stack();

  /**
   * @brief Pushes an element onto the stack.
   * 
   * @param value The value to be pushed onto the stack.
   */
  void push(const T &value);

  /**
   * @brief Pops an element from the stack.
   */
  void pop();

  /**
   * @brief Returns the size of the stack.
   * 
   * @return size_t The number of elements in the stack.
   */
  size_t stackSize() const;

  /**
   * @brief Returns the top element of the stack.
   * 
   * @return T The top element of the stack.
   */
  T top() const;

private:
  /**
   * @brief Checks if the stack is empty.
   * 
   * @return true If the stack is empty.
   * @return false If the stack is not empty.
   */
  bool isEmpty() const;

  /**
   * @brief Checks if the stack is full.
   * 
   * @return true If the stack is full.
   * @return false If the stack is not full.
   */
  bool isFull() const;

  /**
   * @brief Resizes the stack to a new capacity.
   * 
   * @param new_capacity The new capacity of the stack.
   */
  void resize(std::size_t new_capacity);

  size_t top_;       ///< The index of the top element in the stack.
  T *arr_;           ///< The dynamic array to store the elements.
  size_t capacity_;  ///< The capacity of the stack.
};