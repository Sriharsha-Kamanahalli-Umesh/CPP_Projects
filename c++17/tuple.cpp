// std::tuple is a fixed-size collection of heterogeneous values.
// It can hold elements of different types and provides a way to group related values together.
// Tuples are useful when you want to return multiple values from a function or group related data without creating a separate struct or class.
// Key Characteristics:
    // 1. Fixed Size: The size of a tuple is determined at compile-time and cannot be changed.
    // 2. Heterogeneous Types: Each element in a tuple can be of a different type.
    // 3. Access by Index: Elements in a tuple can be accessed using std::get with a zero-based index.
// ✅ Why Use std::tuple?
    // 1. Group Related Data: Tuples allow you to group related values together without creating a separate struct or class.
    // 2. Return Multiple Values: Functions can return multiple values using tuples.
    // 3. Type Safety: Tuples provide type safety by enforcing the types of their elements at compile-time.
// When to Use std::tuple?
// Use std::tuple when:
    // 1. You need to group a small number of related values of different types.
    // 2. You want to return multiple values from a function without creating a custom struct or class.
    // 3. You want to leverage type safety for grouped data.

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