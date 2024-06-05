#include <iostream>

template<typename T>
class Queue {
  public:
    Queue();

    void enqueue(const T& value);
    T dequeue();
    T front() const;
    size_t queueSize();

  private:
    bool isEmpty() const;
    bool isFull() const;
    void resize(size_t new_capacity);
    T* arr_;
    size_t rear_;
    size_t front_;
    size_t capacity_;

};