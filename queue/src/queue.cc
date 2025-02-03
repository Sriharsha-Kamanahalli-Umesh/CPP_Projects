/**
 * @file queue.cc
 * @brief Implementation file for the Queue class.
 */

#include "queue.h"

/**
 * @brief Constructs a new Queue object.
 */
template <typename T>
Queue<T>::Queue() : rear_(0), front_(0), capacity_(1)
{
  arr_ = new T[capacity_];
}

/**
 * @brief Adds an element to the end of the queue.
 * 
 * @param value The value to be added to the queue.
 */
template <typename T>
void Queue<T>::enqueue(const T &value)
{
  if (isFull())
  {
    resize(2 * capacity_);
  }
  arr_[rear_++] = value;
}

/**
 * @brief Removes and returns the front element of the queue.
 * 
 * @return T The front element of the queue.
 * @throws std::underflow_error if the queue is empty.
 */
template <typename T>
T Queue<T>::dequeue()
{
  if (isEmpty())
  {
    throw std::underflow_error("queue is empty");
  }
  auto que_ele = arr_[front_];
  for (size_t i = front_ + 1; i < rear_; i++)
  {
    arr_[i - 1] = arr_[i];
  }
  rear_--;
  return que_ele;
}

/**
 * @brief Returns the front element of the queue without removing it.
 * 
 * @return T The front element of the queue.
 * @throws std::underflow_error if the queue is empty.
 */
template <typename T>
T Queue<T>::front() const
{
  if (isEmpty())
  {
    throw std::underflow_error("queue is empty");
  }
  return arr_[front_];
}

/**
 * @brief Returns the number of elements in the queue.
 * 
 * @return size_t The size of the queue.
 */
template <typename T>
size_t Queue<T>::queueSize()
{
  return rear_;
}

/**
 * @brief Checks if the queue is full.
 * 
 * @return true if the queue is full, false otherwise.
 */
template <typename T>
bool Queue<T>::isFull() const
{
  return rear_ == capacity_;
}

/**
 * @brief Checks if the queue is empty.
 * 
 * @return true if the queue is empty, false otherwise.
 */
template <typename T>
bool Queue<T>::isEmpty() const
{
  return rear_ == front_;
}

/**
 * @brief Resizes the queue to a new capacity.
 * 
 * @param new_capacity The new capacity of the queue.
 */
template <typename T>
void Queue<T>::resize(size_t new_capacity)
{
  T *new_arr = new T[new_capacity];
  for (size_t i = 0; i < rear_; i++)
  {
    new_arr[i] = arr_[i];
  }
  delete[] arr_;
  arr_ = new_arr;
  capacity_ = new_capacity;
}

// Added template class for integer data
template class Queue<int>;