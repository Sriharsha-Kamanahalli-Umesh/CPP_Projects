#include <iostream>

template<typename T>
class StackWithList{
  public:
    StackWithList();
    StackWithList(T val);
    void push(StackWithList **node, T val);
    void pop(StackWithList **node);
    T top(StackWithList *node);
  private:
    T data;
    StackWithList *next;
    bool isEmpty(StackWithList *node);
};