#include "stack_with_list.h"

template <typename T>
StackWithList<T>::StackWithList() {}

template <typename T>
StackWithList<T>::StackWithList(T val) : data(val), next(nullptr) {}

template <typename T>
void StackWithList<T>::push(StackWithList **node, T val)
{
  StackWithList *new_node = new StackWithList(val);
  new_node->next = *node;
  *node = new_node;
}

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

template <typename T>
T StackWithList<T>::top(StackWithList *node)
{
  if (isEmpty(node))
  {
    throw std::underflow_error("stack is empty");
  }
  return node->data;
}

template <typename T>
bool StackWithList<T>::isEmpty(StackWithList *node)
{
  if (node == nullptr)
    return true;
  else
    return false;
}

template class StackWithList<int>;
template class StackWithList<std::string>;