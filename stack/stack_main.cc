
#include "my_stack.h"

int main() {
  Stack<int> st;

  for(int i=0; i<6; i++) {
    st.push(10+i);
  }

  std::cout<<"the top value is:"<< st.top() <<"\n";
  std::cout<<"the top value is:"<< st.stackSize() <<"\n";

  st.pop();

  std::cout<<"the top value is:"<< st.top() <<"\n";
  std::cout<<"the top value is:"<< st.stackSize() <<"\n";

}