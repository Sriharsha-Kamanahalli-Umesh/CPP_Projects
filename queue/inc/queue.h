/**
 * @file queue.h
 * @brief Header file defining the Queue class template.
 */

#include <iostream>

/**
 * @brief Template class for a Queue data structure.
 * 
 * @tparam T The type of elements stored in the queue.
 */
template <typename T>
class Queue
{
public:
  /**
   * @brief Constructs a new Queue object.
   */
  Queue();

  /**
   * @brief Adds an element to the end of the queue.
   * 
   * @param value The value to be added to the queue.
   */
  void enqueue(const T &value);

  /**
   * @brief Removes and returns the front element of the queue.
   * 
   * @return T The front element of the queue.
   * @throws std::underflow_error if the queue is empty.
   */
  T dequeue();

  /**
   * @brief Returns the front element of the queue without removing it.
   * 
   * @return T The front element of the queue.
   * @throws std::underflow_error if the queue is empty.
   */
  T front() const;

  /**
   * @brief Returns the number of elements in the queue.
   * 
   * @return size_t The size of the queue.
   */
  size_t queueSize();

private:
  /**
   * @brief Checks if the queue is empty.
   * 
   * @return true if the queue is empty, false otherwise.
   */
  bool isEmpty() const;

  /**
   * @brief Checks if the queue is full.
   * 
   * @return true if the queue is full, false otherwise.
   */
  bool isFull() const;

  /**
   * @brief Resizes the queue to a new capacity.
   * 
   * @param new_capacity The new capacity of the queue.
   */
  void resize(size_t new_capacity);

  T *arr_; ///< Pointer to the array storing the queue elements.
  size_t rear_; ///< Index of the rear element.
  size_t front_; ///< Index of the front element.
  size_t capacity_; ///< Capacity of the queue.
};