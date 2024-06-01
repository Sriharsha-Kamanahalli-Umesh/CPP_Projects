
#include <iostream>
#include <initializer_list>

template <typename T>
class Myvector {
  public:
    Myvector();
    Myvector(std::initializer_list<T> list);

    // Element acces
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    //Modifiers
    void push_back(const T& value);
    std::size_t getSize() const;
    std::size_t getCapacity() const;

    //Iteratos
    T* begin();
    T* end();

    ~Myvector();
  
  private:
    T* data;
    std::size_t size;
    std::size_t capacity;

    void resize(std::size_t new_capacity);
};