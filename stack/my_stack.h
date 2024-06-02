
#include <iostream>

template<typename T>
class Stack {
  public:
    Stack();
    void push(const T &value);
    void pop();
    size_t stackSize() const;
    T top() const;
  private:
    bool isEmpty() const;
    bool isFull() const;
    void resize(std::size_t new_capacity);
    size_t top_;
    T *arr_;
    size_t capacity_;
};