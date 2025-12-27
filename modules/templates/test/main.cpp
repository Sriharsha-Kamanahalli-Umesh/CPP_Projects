#include "my_vector.h"

int main() {
    Myvector<int> vec = {1, 2, 3, 4, 5};
    const Myvector<int> const_vec = {10, 20, 30, 40, 50};

    // Accessing front element of non-const vector
    int front_elem = vec.front();
    front_elem = 100; // Modifying the front element
    std::cout << "Front element of vec: " << vec.front() << std::endl;

    // Accessing front element of const vector
    const int& const_front_elem = const_vec.front();
    std::cout << "Front element of const_vec: " << const_front_elem << std::endl;

    auto *ptr = vec.begin();
    std::cout << "Front element of vec: " << ptr[2] << std::endl;

    auto *ptr_end = const_vec.end();
    std::cout << "last element of vec: " << *(ptr_end-1) << std::endl;

    return 0;
}