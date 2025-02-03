#include "stack_with_list.h"

/**
 * @brief Default constructor for StackWithList
 */
template <typename T>
StackWithList<T>::StackWithList() {}

/**
 * @brief Constructor with initial value for StackWithList
 * @param val Initial value to be stored in the stack
 */
template <typename T>
StackWithList<T>::StackWithList(T val) : data(val), next(nullptr) {}

/**
 * @brief Push a new value onto the stack
 * @param node Pointer to the top of the stack
 * @param val Value to be pushed onto the stack
 */
template <typename T>
void StackWithList<T>::push(StackWithList **node, T val)
{
  StackWithList *new_node = new StackWithList(val);
  new_node->next = *node;
  *node = new_node;
}

/**
 * @brief Pop the top value from the stack
 * @param node Pointer to the top of the stack
 * @throws std::underflow_error if the stack is empty
 */
template <typename T>
void StackWithList<T>::pop(StackWithList **node)
{
  if (isEmpty(*node))
  {
    throw std::underflow_error("stack is empty");
  }
  StackWithList *temp_node = *node;
  *node = temp_node->next;
  delete temp_node;
}

/**
 * @brief Get the top value of the stack
 * @param node Pointer to the top of the stack
 * @return The top value of the stack
 * @throws std::underflow_error if the stack is empty
 */
template <typename T>
T StackWithList<T>::top(StackWithList *node)
{
  if (isEmpty(node))
  {
    throw std::underflow_error("stack is empty");
  }
  return node->data;
}

/**
 * @brief Check if the stack is empty
 * @param node Pointer to the top of the stack
 * @return true if the stack is empty, false otherwise
 */
template <typename T>
bool StackWithList<T>::isEmpty(StackWithList *node)
{
  if (node == nullptr)
    return true;
  else
    return false;
}

// Explicit template instantiation
template class StackWithList<int>;
template class StackWithList<std::string>;