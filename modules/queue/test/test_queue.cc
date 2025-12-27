/**
 * @file test_queue.cc
 * @brief Test file for the Queue class.
 */

#include "queue.h"

/**
 * @brief Main function to test the Queue class.
 * 
 * This function creates a Queue of integers, enqueues elements, 
 * prints the front element, dequeues elements, and prints the size of the queue.
 * 
 * @return int Returns 0 on successful execution.
 */
int main()
{
  Queue<int> que;

  for (int i = 0; i < 6; i++)
  {
    que.enqueue(10 + i);
  }
  std::cout << "the size of Queue is:" << que.queueSize() << "\n";

  for (size_t i = 0; i < 6; i++)
  {
    std::cout << "the front element is:" << que.front() << "\n";
    std::cout << "the values are:" << que.dequeue() << " \n";
  }

  std::cout << "the size of Queue is:" << que.queueSize() << "\n";
  return 0;
}