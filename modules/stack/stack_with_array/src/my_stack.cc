#include "my_stack.h"

/**
 * @brief Constructs a new Stack object.
 * 
 * Initializes the stack with a default capacity of 1.
 */
template <typename T>
Stack<T>::Stack() : top_(0), capacity_(1)
{
  arr_ = new T[capacity_];
}

/**
 * @brief Pushes an element onto the stack.
 * 
 * @param value The value to be pushed onto the stack.
 */
template <typename T>
void Stack<T>::push(const T &value)
{
  if (isFull())
  {
    resize(2 * capacity_);
  }
  arr_[top_++] = value;
}

/**
 * @brief Pops an element from the stack.
 * 
 * Throws an underflow error if the stack is empty.
 */
template <typename T>
void Stack<T>::pop()
{
  if (isEmpty())
  {
    throw std::underflow_error("Stack is empty");
  }
  top_--;
}

/**
 * @brief Checks if the stack is empty.
 * 
 * @return true If the stack is empty.
 * @return false If the stack is not empty.
 */
template <typename T>
bool Stack<T>::isEmpty() const
{
  return top_ == 0;
}

/**
 * @brief Checks if the stack is full.
 * 
 * @return true If the stack is full.
 * @return false If the stack is not full.
 */
template <typename T>
bool Stack<T>::isFull() const
{
  return top_ == capacity_;
}

/**
 * @brief Returns the size of the stack.
 * 
 * @return size_t The number of elements in the stack.
 */
template <typename T>
size_t Stack<T>::stackSize() const
{
  return top_;
}

/**
 * @brief Returns the top element of the stack.
 * 
 * @return T The top element of the stack.
 */
template <typename T>
T Stack<T>::top() const
{
  return arr_[top_ - 1];
}

/**
 * @brief Resizes the stack to a new capacity.
 * 
 * @param new_capacity The new capacity of the stack.
 */
template <typename T>
void Stack<T>::resize(std::size_t new_capacity)
{
  T *new_arr = new T[new_capacity];
  for (size_t i = 0; i < top_; i++)
  {
    new_arr[i] = arr_[i];
  }
  delete[] arr_;
  arr_ = new_arr;
  capacity_ = new_capacity;
}

// Added template class for integer data
template class Stack<int>;
template class Stack<std::string>;