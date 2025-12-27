
#include <iostream>
#include <list>
using namespace std;

// Function to print the elements of a list
void printList(const list<int>& lst) {
    for (const auto& elem : lst) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    // Initializing lists
    list<int> lst1 = {2, 3, 8, 4, 7, 4};

    list<int> lst2(5, 10); // list of size 5, all elements initialized to 10

    // Adding elements
    lst1.push_back(6);
    lst2.emplace_back(20);
    lst1.push_front(0);
    lst2.emplace_front(5);

    // Accessing elements
    cout << "First element of lst1: " << lst1.front() << endl;
    cout << "Last element of lst2: " << lst2.back() << endl;

    cout << "Elements in lst1: ";    printList(lst1);

    cout << "Elements in lst2: ";    printList(lst2);

    // Modifying elements
    auto it = lst1.begin();
    advance(it, 2); // Move iterator to the third element
    *it = 9;

    // Removing elements
    lst1.pop_back(); // removes last element
    lst2.pop_front(); // removes first element

    // Iterating over elements
    cout << "Elements in lst1: ";
    printList(lst1);

    cout << "Elements in lst2: ";
    printList(lst2);

    // Capacity functions
    cout << "Size of lst1: " << lst1.size() << endl;
    cout << "Is lst1 empty? " << (lst1.empty() ? "Yes" : "No") << endl;

    // Clearing list
    lst1.clear();
    cout << "Size of lst1 after clear: " << lst1.size() << endl;

    // Swapping lists
    lst1.swap(lst2);
    cout << "Elements in lst1 after swap: ";
    printList(lst1);

    // Other operations
    lst1.reverse();
    cout << "Elements in lst1 after reverse: ";
    printList(lst1);

    lst1.sort();
    cout << "Elements in lst1 after sort: ";
    printList(lst1);

    lst1.unique();
    cout << "Elements in lst1 after unique: ";
    printList(lst1);

    return 0;
}
