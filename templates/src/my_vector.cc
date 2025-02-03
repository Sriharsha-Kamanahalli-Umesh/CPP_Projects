#include "my_vector.h"

/**
 * @brief Default constructor.
 */
template <typename T>
Myvector<T>::Myvector() : data(nullptr), size(0), capacity(0) {}

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
 * @brief Destructor.
 */
template <typename T>
Myvector<T>::~Myvector()
{
  delete[] data;
}

/**
 * @brief Element access operator.
 * @param index Index of the element to access.
 * @return Reference to the element at the specified index.
 */
template <typename T>
T &Myvector<T>::operator[](std::size_t index)
{
  return data[index];
}

/**
 * @brief Const element access operator.
 * @param index Index of the element to access.
 * @return Const reference to the element at the specified index.
 */
template <typename T>
const T &Myvector<T>::operator[](std::size_t index) const
{
  return data[index];
}

/**
 * @brief Add element to the end of the vector.
 * @param value Element to add.
 */
template <typename T>
void Myvector<T>::push_back(const T &value)
{
  if (size == capacity)
  {
    resize(capacity == 0 ? 1 : 2 * capacity);
  }
  data[size++] = value;
}

/**
 * @brief Get the size of the vector.
 * @return Size of the vector.
 */
template <typename T>
std::size_t Myvector<T>::getSize() const
{
  return size;
}

/**
 * @brief Get the capacity of the vector.
 * @return Capacity of the vector.
 */
template <typename T>
std::size_t Myvector<T>::getCapacity() const
{
  return capacity;
}

/**
 * @brief Get the begin iterator of the vector.
 * @return Pointer to the first element of the vector.
 */
template <typename T>
T *Myvector<T>::begin()
{
  return data;
}

/**
 * @brief Get the end iterator of the vector.
 * @return Pointer to the element past the last element of the vector.
 */
template <typename T>
T *Myvector<T>::end()
{
  return data + size;
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
    data = new_data;
    capacity = new_capacity;
    return;
  }
  T *new_data = new T[new_capacity];
  for (std::size_t i = 0; i < size; i++)
  {
    new_data[i] = data[i];
  }
  delete[] data;
  data = new_data;
  capacity = new_capacity;
}

// Explicit instantiation of template classes
template class Myvector<int>;
template class Myvector<std::string>;