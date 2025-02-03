#include <iostream>
#include <initializer_list>

/**
 * @brief A simple vector class template.
 * 
 * @tparam T Type of elements stored in the vector.
 */
template <typename T>
class Myvector
{
public:
  /**
   * @brief Default constructor.
   */
  Myvector();
  
  /**
   * @brief Initializer list constructor.
   * @param list Initializer list to initialize the vector.
   */
  Myvector(std::initializer_list<T> list);

  /**
   * @brief Element access operator.
   * @param index Index of the element to access.
   * @return Reference to the element at the specified index.
   */
  T &operator[](std::size_t index);

  /**
   * @brief Const element access operator.
   * @param index Index of the element to access.
   * @return Const reference to the element at the specified index.
   */
  const T &operator[](std::size_t index) const;

  /**
   * @brief Add element to the end of the vector.
   * @param value Element to add.
   */
  void push_back(const T &value);

  /**
   * @brief Get the size of the vector.
   * @return Size of the vector.
   */
  std::size_t getSize() const;

  /**
   * @brief Get the capacity of the vector.
   * @return Capacity of the vector.
   */
  std::size_t getCapacity() const;

  /**
   * @brief Get the begin iterator of the vector.
   * @return Pointer to the first element of the vector.
   */
  T *begin();

  /**
   * @brief Get the end iterator of the vector.
   * @return Pointer to the element past the last element of the vector.
   */
  T *end();

  /**
   * @brief Destructor.
   */
  ~Myvector();

private:
  T *data; ///< Pointer to the data array
  std::size_t size; ///< Current size of the vector
  std::size_t capacity; ///< Current capacity of the vector

  /**
   * @brief Resize the vector to a new capacity.
   * @param new_capacity New capacity of the vector.
   */
  void resize(std::size_t new_capacity);
};