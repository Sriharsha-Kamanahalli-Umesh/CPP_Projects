#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initializing vectors
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2(5, 10); // vector of size 5, all elements initialized to 10

    // Adding elements
    vec1.push_back(6);
    vec2.emplace_back(20);

    // Accessing elements
    cout << "Element at index 0 in vec1: " << vec1[0] << endl;
    cout << "Element at index 2 in vec2: " << vec2.at(2) << endl;

    // Modifying elements
    vec1[1] = 9;
    vec2.at(3) = 15;

    // Removing elements
    vec1.pop_back(); // removes last element
    vec2.erase(vec2.begin() + 1); // removes element at index 1

    // Iterating over elements
    cout << "Elements in vec1: ";
    for (const auto& elem : vec1) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Elements in vec2: ";
    for (auto it = vec2.begin(); it != vec2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Capacity functions
    cout << "Size of vec1: " << vec1.size() << endl;
    cout << "Capacity of vec1: " << vec1.capacity() << endl;
    cout << "Is vec1 empty? " << (vec1.empty() ? "Yes" : "No") << endl;

    // Clearing vector
    vec1.clear();
    cout << "Size of vec1 after clear: " << vec1.size() << endl;

    // Swapping vectors
    vec1.swap(vec2);
    cout << "Elements in vec1 after swap: ";
    for (const auto& elem : vec1) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
