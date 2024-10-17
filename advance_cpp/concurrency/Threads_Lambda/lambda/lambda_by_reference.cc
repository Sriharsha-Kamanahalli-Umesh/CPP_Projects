#include <iostream>
#include <vector>
#include <algorithm>


int a=20;

int main()
{
    std::vector<int> int_vec = {1, 2, 3, 4, 5};
    int discount = 50;
    // Capture by reference
    std::for_each(int_vec.begin(),
                  int_vec.end(),
                  [&](int x) {
                        std::cout << x << " ";
                        // We can modify 'discount' here since it's captured by reference.
                        discount += x;
                        std::cout<< " value of a is:" << a << "\n";
                  });
    std::cout << std::endl;
    std::cout << "discount Vaue: " << discount << std::endl;
    return 0;
}