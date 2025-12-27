#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> int_vec = {1, 2, 3, 4, 5};
    int discount = 50;
    // Capture by Value
    std::for_each(int_vec.begin(),
                  int_vec.end(),
                  [=](int x) mutable
                  {
                      std::cout << x << " ";
                      // Cannot modify 'discount' here since it's captured by value,
                      // unless 'mutable' is used.
                      discount = 20;
                  });
    std::cout << std::endl;
    std::cout << "discount Vaue: " << discount << std::endl;
    return 0;
}