
#include "my_stack.h"

int main() {
  Stack<std::string> st;

  for(int i=0; i<6; i++) {
    st.push("10+i");
  }

  std::cout<<"the size is:"<< st.stackSize() <<"\n";

  for(int i=0; i<6; i++) {
    std::cout<<"the top value is:"<< st.top() <<"\n";
    st.pop();
  }

  std::cout<<"the top value is:"<< st.top() <<"\n";
  std::cout<<"the size is:"<< st.stackSize() <<"\n";

}