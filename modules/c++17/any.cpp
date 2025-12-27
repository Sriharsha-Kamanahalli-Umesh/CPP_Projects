
// std::any was introduced in C++17 and is a type-safe container for single values of any type. 
// It allows you to store and retrieve values without knowing their type at compile time, but with runtime type checking.

#include <any>
#include <iostream>
#include <string>

int main() {
    std::any value;

    value = 42; // store int
    std::cout << "Type: " << value.type().name() << "\n";
    std::cout << "Value: " << std::any_cast<int>(value) << "\n";

    value = std::string("Hello");
    std::cout << "Type: " << value.type().name() << "\n";
    std::cout << "Value: " << std::any_cast<std::string>(value) << "\n";

    // Safe check before casting
    if (value.type() == typeid(std::string)) {
        std::cout << "String length: " << std::any_cast<std::string>(value).size() << "\n";
    }

    return 0;
}