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
   * @brief Copy constructor.
   * @param other Another Myvector object to copy from.
   */
  Myvector(const Myvector& other);


  /**
   * @brief Move constructor.
   * @param other Another Myvector object to move from.
   */
  Myvector(Myvector&& other) noexcept;


  /**
   * @brief Copy assignment operator.
   * @param other Another Myvector object to copy from.
   * @return Reference to the assigned object.
   */
  Myvector& operator=(const Myvector& other);

  /**
   * @brief Move assignment operator.
   * @param other Another Myvector object to move from.
   * @return Reference to the assigned object.
   */
  Myvector& operator=(Myvector&& other) noexcept;

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

  /**u
   * @brief Add element to the end of the vector.
   * @param value Element to add.
   */
  void push_back(const T &value);

  /**
   * @brief Remove the last element of the vector.
   */
  void pop_back();


  /**
   * @brief Get the first element of the vector.
   * @return Reference to the first element of the vector.
   */
  const T& front() const;

  /**
   * @brief Get the last element of the vector.
   * @return Reference to the last element of the vector.
   */
  const T& back() const;

  /**
   * @brief Get the size of the vector.
   * @return Size of the vector.
   */
  std::size_t size() const;

  /**
   * @brief Get the capacity of the vector.
   * @return Capacity of the vector.
   */
  std::size_t capacity() const;

  /**
   * @brief Get the begin iterator of the vector.
   * @return Pointer to the first element of the vector.
   */
  T *begin() const;

  /**
   * @brief Get the end iterator of the vector.
   * @return Pointer to the element past the last element of the vector.
   */
  T *end() const;

  /**
   * @brief Get the raw data pointer of the vector.
   * @return Pointer to the data array.
   */
  T* data() const;


  /**
   * @brief Insert an element at a specific index.
   * @param index Index to insert the element at.
   * @param value Element to insert.
   */
  void insert(std::size_t index, const T& value);

  /**
   * @brief Remove an element at a specific index.
   * @param index Index to remove the element from.
   */
  void erase(std::size_t index);
  
  /**
   * @brief Clear the vector.
   */
  void clear();

  /**
   * @brief Destructor.
   */
  ~Myvector();

private:
  T *ptr; ///< Pointer to the ptr array
  std::size_t size_; ///< Current size of the vector
  std::size_t capacity_; ///< Current capacity of the vector

  /**
   * @brief Resize the vector to a new capacity.
   * @param new_capacity New capacity of the vector.
   */
  void resize(std::size_t new_capacity);
};