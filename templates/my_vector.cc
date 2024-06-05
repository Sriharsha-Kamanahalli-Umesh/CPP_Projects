
#include "my_vector.h"
#include "exception/my_exception.h"

template<typename T>
Myvector<T>::Myvector() : data(nullptr), size(0), capacity(0) {}

template<typename T>
Myvector<T>::Myvector(std::initializer_list<T> list) : Myvector() {
  for(const T& elem : list) {
    push_back(elem);
  }
}

template<typename T>
Myvector<T>::~Myvector() {
  delete[] data;
}

template<typename T>
T& Myvector<T>::operator[](std::size_t index) {
  if(index >= size) {
    throw exception::OutofRangeException("Index out of range");
  }
  return data[index];
}

template<typename T>
const T& Myvector<T>::operator[](std::size_t index) const {
  if(index >= size) {
    throw exception::OutofRangeException("Index out of range");
  }
  return data[index];
}

template<typename T>
void Myvector<T>::push_back(const T& value){
  if(size == capacity){
    resize(capacity == 0 ? 1 : 2 * capacity);
  }
  data[size++] = value;
}

template<typename T>
std::size_t Myvector<T>::getSize() const {
  return size;
}

template<typename T>
std::size_t Myvector<T>::getCapacity() const {
  return capacity;
}

template<typename T>
T* Myvector<T>::begin() {
  return data;
}

template<typename T>
T* Myvector<T>::end() {
  return data+size;
}

template<typename T>
void Myvector<T>::resize(std::size_t new_capacity) {
  T* new_data = new T[new_capacity];
  for(std::size_t i = 0; i < size; i++) {
    new_data[i] = data[i];
  }
  delete[] data;
  data = new_data;
  capacity = new_capacity;
}

// Added template class for integer data
template class Myvector<int>;
template class Myvector<std::string>;