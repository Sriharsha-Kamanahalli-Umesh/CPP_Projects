#include "queue.h"

int main() {
  Queue<int> que;

  for(int i=0; i<6; i++){
    que.enqueue(10+i);
  }
  std::cout<<"the size of Queue is:"<<que.queueSize()<<"\n";
  
  for(size_t i=0; i<6; i++) {
    std::cout<<"the front element is:"<<que.front()<<"\n";
    std::cout<<"the values are:"<<que.dequeue()<<" \n";
  }

  std::cout<<"the size of Queue is:"<<que.queueSize()<<"\n";
  return 0;
}