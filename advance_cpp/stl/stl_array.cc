#include <iostream>
#include <array>
#include <algorithm> // For std::sort, std::find
using namespace std;
 
// Function to print an array
template <size_t N>
void printArray(const array<int, N>& arr) {
    for (const auto& element : arr) {
        cout << element << " ";
    }
    cout << endl;
}
 
int main() {
    // 1. Initialization
    array<int, 5> arr = {10, 5, 8, 1, 7};
    
    cout << "Original array: ";
    printArray(arr);
 
    // 2. Size
    cout << "Array size: " << arr.size() << endl;
     
    // 3. Filling array with a specific value
    array<int, 5> arr2;
    arr2.fill(3);
    cout << "Array after filling with 3: ";
    printArray(arr2);
 
    // 4. Swapping arrays
    arr.swap(arr2);
    cout << "Array after swapping with another array: arr[]= ";
    printArray(arr);
    printArray(arr2);
 
    sort(arr2.begin(), arr2.end());
    cout << "Sorted array: ";
    printArray(arr2);
 
    // 5. Searching for an element
    auto it = find(arr2.begin(), arr2.end(), 8);
    if (it != arr2.end()) {
        cout << "Element 8 found at position: " << distance(arr2.begin(), it) << endl;
    } else {
        cout << "Element 8 not found" << endl;
    }
 
    // 6. Checking if the array is empty
    cout << "Is array empty? " << (arr2.empty() ? "Yes" : "No") << endl;

 
    return 0;
}
