#include "queue.h"

template<typename T>
Queue<T>::Queue() : rear_(0), front_(0), capacity_(1) {
  arr_ = new T[capacity_];
}

template<typename T>
void Queue<T>::enqueue(const T& value) {
  if(isFull()){
    resize(2*capacity_);
  }
  arr_[rear_++] = value;
}

template<typename T>
T Queue<T>::dequeue() {
  if(isEmpty()) {
    throw std::underflow_error("queue is empty");
  }
  auto que_ele = arr_[front_];
  for(size_t i = front_+1; i <rear_; i++) {
    arr_[i-1] = arr_[i];
  }
  rear_--;
  return que_ele;
}

template<typename T>
T Queue<T>::front() const {
  if(isEmpty()) {
    throw std::underflow_error("queue is empty");
  }
  return arr_[front_];
}

template<typename T>
size_t Queue<T>::queueSize() {
  return rear_;
}

template<typename T>
bool Queue<T>::isFull() const {
  return rear_ == capacity_;
}

template<typename T>
bool Queue<T>::isEmpty() const {
  return rear_ == front_;
}

template<typename T>
void Queue<T>::resize(size_t new_capacity) {
  T *new_arr = new T[new_capacity];
  for(size_t i=0; i<rear_; i++){
    new_arr[i] = arr_[i];
  }
  delete[] arr_;
  arr_ = new_arr;
  capacity_ = new_capacity;
}

// Added template class for integer data
template class Queue<int>;