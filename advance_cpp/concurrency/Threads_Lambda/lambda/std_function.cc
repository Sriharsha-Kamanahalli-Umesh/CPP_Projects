#include <iostream>
#include <functional>

void print_num(int i)
{
    std::cout << i << '\n';
}

int add(int a, int b) {
    return a+b;
}
 
int func(std::function<int(int, int)> add, int a, int b) {
    return add(a, b);
}
 
int main()
{
    // store a free function
    std::function<void(int)> f_display = print_num;
    f_display(-9);

    // store a lambda
    std::function<void()> f_display_42 = []() { print_num(42); };
    f_display_42();

    //passing function as argument
    auto res = func(add, 10, 20);
    std::cout << res << "\n";
}