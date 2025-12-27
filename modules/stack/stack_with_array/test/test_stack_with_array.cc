#include "my_stack.h"

/**
 * @brief Main function to test the Stack class.
 * 
 * This function creates a stack, pushes elements onto it, and then pops elements from it.
 * 
 * @return int Returns 0 on successful execution.
 */
int main()
{
  Stack<std::string> st;

  // Push elements onto the stack
  for (int i = 0; i < 6; i++)
  {
    st.push("10+i");
  }

  std::cout << "the size is:" << st.stackSize() << "\n";

  // Pop elements from the stack
  for (int i = 0; i < 6; i++)
  {
    std::cout << "the top value is:" << st.top() << "\n";
    st.pop();
  }

  std::cout << "the top value is:" << st.top() << "\n";
  std::cout << "the size is:" << st.stackSize() << "\n";
}