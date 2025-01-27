
#include "stack_with_list.h"

int main() {
  StackWithList<std::string> st;
  StackWithList<std::string> *node = nullptr;

  st.push(&node, "hello");
  st.push(&node, "Sriharsha");
  st.push(&node, "how");
  st.push(&node, "are");
  st.push(&node, "you");
  st.push(&node, "young man");

  std::cout<<"the top element is:"<<st.top(node)<<"\n";
  st.pop(&node);
  std::cout<<"the top element is:"<<st.top(node)<<"\n";
}
