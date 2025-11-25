// Structural Binding is a feature introduced in C++17.
// Structural Binding allows you to unpack tuples, structs, and arrays into individual variables.
// It provides a more readable and convenient way to work with grouped data.
// Key Characteristics:
    // 1. Unpacking: You can unpack multiple values from a tuple, struct, or array into separate variables in a single statement.
    // 2. Auto Deduction: The types of the variables are automatically deduced.
    // 3. Works with Various Types: Structural Binding works with std::tuple, structs, and arrays.
// ✅ Why Use Structural Binding?
    // 1. Improved Readability: Code becomes more readable and expressive when unpacking multiple values.
    // 2. Convenience: Reduces boilerplate code when accessing elements of tuples or structs.
    // 3. Type Safety: Types are deduced at compile-time, ensuring type safety.
// When to Use Structural Binding?
// Use Structural Binding when:
    // 1. You need to unpack multiple values from a tuple, struct, or array.
    // 2. You want to improve code readability when working with grouped data.

#include <iostream>
#include <tuple>
#include <string>
#include <map>
#include <array>

std::tuple<int, std::string, double> createPersonTuple(int id, std::string name, double weight) {
    return std::make_tuple(id, name, weight);
}

int main() {
    std::tuple<int, std::string, double> person;
    person = std::make_tuple(8, "Alice", 72.5);

    std::cout << "ID: " << std::get<0>(person) << std::endl;
    std::cout << "Name: " << std::get<1>(person) << std::endl;
    std::cout << "Weight: " << std::get<2>(person) << std::endl;

    // structured binding with tuple
    auto [id, name, weight] = person;
    std::cout << "\nUsing Structured Binding:\n";
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Weight: " << weight << std::endl;

    // structured binding with function returning tuple
    auto [newId, newName, newWeight] = createPersonTuple(10, "Bob", 80.0);
    std::cout << "\nFrom Function Tuple:\n";
    std::cout << "ID: " << newId << std::endl;
    std::cout << "Name: " << newName << std::endl;
    std::cout << "Weight: " << newWeight << std::endl;

    // structured binding with array
    std::cout << "\nArray Structured Binding:\n";
    std::array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    for(auto [a, b, c, d, e, f] : {arr}) {
        std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << std::endl;
    }
    std::cout << "\nArray Structured Binding:\n";

    // structured binding with struct
    typedef struct {
        int x;
        int y;
    } Point;

    Point p = {10, 20};
    auto [x, y] = p;
    std::cout << "Point x: " << x << ", y: " << y   << std::endl;

    // structured binding with map
    std::cout << "\nMap Structured Binding:\n";
    std::map<std::string, int> ageMap = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};
    for(const auto& [name, age] : ageMap) {
        std::cout << name << " : " << age << std::endl;
    }

}