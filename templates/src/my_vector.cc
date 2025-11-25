#include "my_vector.h"

/**
 * @brief Default constructor.
 */
template <typename T>
Myvector<T>::Myvector() : ptr(nullptr), size_(0), capacity_(0) {}

/**
 * @brief Initializer list constructor.
 * @param list Initializer list to initialize the vector.
 */
template <typename T>
Myvector<T>::Myvector(std::initializer_list<T> list) : Myvector()
{
  for (const T &elem : list)
  {
    push_back(elem);
  }
}

/**
 * @brief Copy constructor.
 * @param other Another Myvector object to copy from.
 */
template <typename T>
Myvector<T>::Myvector(const Myvector& other) {
  std::cout << "Copy constructor called\n" << "\n";
  ptr = new T[other.capacity_];
  size_ = other.size_;
  capacity_ = other.capacity_;
  std::copy(other.ptr, other.ptr + other.size_, ptr);
}

/**
 * @brief Move constructor.
 * @param other Another Myvector object to move from.
 */
template <typename T>
Myvector<T>::Myvector(Myvector&& other) noexcept {
  std::cout << "Move constructor called\n" << "\n";
  ptr = other.ptr;
  size_ = other.size_;
  capacity_ = other.capacity_;
  other.ptr = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

/**
 * @brief Copy assignment operator.
 * @param other Another Myvector object to move from.
 * @return Reference to the assigned object.
 */
template <typename T>
Myvector<T>& Myvector<T>::operator=(const Myvector& other) {
  std::cout << "Copy assignment operator called\n" << "\n";
  if(this != &other) {
    delete[] ptr;
    ptr = new T[other.capacity_];
    size_ = other.size_;
    capacity_ = other.capacity_;
    std::copy(other.ptr, other.ptr + other.size_, ptr);
  }
  return *this;
}

/**
 * @brief Move assignment operator.
 * @param other Another Myvector object to move from.
 * @return Reference to the assigned object.
 */
template <typename T>
Myvector<T>& Myvector<T>::operator=(Myvector&& other) noexcept {
  std::cout << "Move assignment operator called\n" << "\n";
  if(this != &other){
    delete[] ptr;
    ptr = other.ptr;
    size_ = other.size_;
    capacity_ = other.capacity_;
    other.ptr = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }
  return *this;
}

/**
 * @brief Destructor.
 */
template <typename T>
Myvector<T>::~Myvector()
{
  delete[] ptr;
}

/**
 * @brief Element access operator.
 * @param index Index of the element to access.
 * @return Reference to the element at the specified index.
 */
template <typename T>
T &Myvector<T>::operator[](std::size_t index)
{
  if (index >= size_) {
    throw std::out_of_range("Index out of bounds");
  }

  return ptr[index];
}

/**
 * @brief Const element access operator.
 * @param index Index of the element to access.
 * @return Const reference to the element at the specified index.
 */
template <typename T>
const T &Myvector<T>::operator[](std::size_t index) const
{
  if (index >= size_) {
    throw std::out_of_range("Index out of bounds");
  }
  return ptr[index];
}

/**
 * @brief Add element to the end of the vector.
 * @param value Element to add.
 */
template <typename T>
void Myvector<T>::push_back(const T &value)
{
  if (size_ == capacity_)
  {
    resize(capacity_ == 0 ? 1 : 2 * capacity_);
  }
  ptr[size_++] = value;
}

/**
 * @brief Remove the last element of the vector.
 */
template <typename T>
void Myvector<T>::pop_back()
{
  if (size_ > 0)
  {
    --size_;
  }
}

/**
 * @brief Get the first element of the vector.
 * @return Reference to the first element of the vector.
 */
template <typename T>
const T& Myvector<T>::front() const
{
  if(size_ == 0) 
  {
    throw std::out_of_range("Vector is empty");
  }
  return ptr[0];
}

/**
 * @brief Get the last element of the vector.
 * @return Reference to the last element of the vector.
 */
template <typename T>
const T& Myvector<T>::back() const
{
  if(size_ == 0) 
  {
    throw std::out_of_range("Vector is empty");
  }
  return ptr[size_ - 1];
}

/**
 * @brief Insert an element at a specific index.
 * @param index Index to insert the element at.
 * @param value Element to insert.
 */
template <typename T>
void Myvector<T>::insert(std::size_t index, const T& value) 
{
  if (index > size_) {
      throw std::out_of_range("Insert index out of bounds");
  }
  if(size_ == capacity_)
  {
    resize(capacity_ == 0 ? 1 : 2 * capacity_);
  }
  for(std::size_t i = size_; i > index; --i) 
  {
    ptr[i] = ptr[i-1];
  }
  ptr[index] = value;
  ++size_;
}

/**
 * @brief Remove an element at a specific index.
 * @param index Index to remove the element from.
 */
template <typename T>
void Myvector<T>::erase(std::size_t index)
{
  if(index >= size_)
  {
    throw std::out_of_range("Erase index out of bounds");
  }
  if(index < size_)
  {
    for(std::size_t i = index; i < size_-1; ++i)
    {
      ptr[i] = ptr[i+1];
    }
    --size_;
  }
}

/**
 * @brief Clear the vector.
 */
template <typename T>
void Myvector<T>::clear() 
{
  delete[] ptr;
  ptr = nullptr;
  size_ = 0;
}

/**
 * @brief Get the size of the vector.
 * @return Size of the vector.
 */
template <typename T>
std::size_t Myvector<T>::size() const
{
  return size_;
}

/**
 * @brief Get the capacity of the vector.
 * @return Capacity of the vector.
 */
template <typename T>
std::size_t Myvector<T>::capacity() const
{
  return capacity_;
}

/**
 * @brief Get the begin iterator of the vector.
 * @return Pointer to the first element of the vector.
 */
template <typename T>
T *Myvector<T>::begin() const
{
  return ptr;
}

/**
 * @brief Get the end iterator of the vector.
 * @return Pointer to the element past the last element of the vector.
 */
template <typename T>
T *Myvector<T>::end() const
{
  return ptr + size_;
}

template <typename T>
T* Myvector<T>::data() const
{
  return ptr;
}

/**
 * @brief Resize the vector to a new capacity.
 * @param new_capacity New capacity of the vector.
 */
template <typename T>
void Myvector<T>::resize(std::size_t new_capacity)
{
  if (new_capacity == 1)
  {
    T *new_data = new T[new_capacity];
    ptr = new_data;
    capacity_ = new_capacity;
    return;
  }
  T *new_data = new T[new_capacity];
  for (std::size_t i = 0; i < size_; i++)
  {
    new_data[i] = ptr[i];
  }
  delete[] ptr;
  ptr = new_data;
  capacity_ = new_capacity;
  
}

// Explicit instantiation of template classes
template class Myvector<int>;
template class Myvector<std::string>;