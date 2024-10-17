#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


std::function<void(int)> lambda = [](int x){
        std::cout<< x << " ";
    };
int main() {
    std::vector<int> int_vec={10, 20, 30, 40, 50, 60};
    std::for_each(int_vec.begin(), int_vec.end(), lambda);
}