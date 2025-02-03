
#include "my_stack.h"

template <typename T>
Stack<T>::Stack() : top_(0), capacity_(1)
{
  arr_ = new T[capacity_];
}

template <typename T>
void Stack<T>::push(const T &value)
{
  if (isFull())
  {
    resize(2 * capacity_);
  }
  arr_[top_++] = value;
}

template <typename T>
void Stack<T>::pop()
{
  if (isEmpty())
  {
    throw std::underflow_error("Stack is empty");
  }
  top_--;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
  return top_ == 0;
}

template <typename T>
bool Stack<T>::isFull() const
{
  return top_ == capacity_;
}

template <typename T>
size_t Stack<T>::stackSize() const
{
  return top_;
}

template <typename T>
T Stack<T>::top() const
{
  return arr_[top_ - 1];
}

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