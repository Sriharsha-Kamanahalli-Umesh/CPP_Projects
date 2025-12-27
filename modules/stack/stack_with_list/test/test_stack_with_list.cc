#include "stack_with_list.h"

/**
 * @brief Test the StackWithList implementation
 * 
 * This function tests the push, pop, and top methods of the StackWithList class.
 * It pushes several strings onto the stack, displays the top element, pops the top element,
 * and then displays the new top element.
 * 
 * @return int 
 */
int main()
{
  StackWithList<std::string> st;
  StackWithList<std::string> *node = nullptr;

  // Push elements onto the stack
  st.push(&node, "hello");
  st.push(&node, "Sriharsha");
  st.push(&node, "how");
  st.push(&node, "are");
  st.push(&node, "you");
  st.push(&node, "young man");

  // Display the top element
  std::cout << "the top element is:" << st.top(node) << "\n";
  // Pop the top element
  st.pop(&node);
  // Display the new top element
  std::cout << "the top element is:" << st.top(node) << "\n";
}
