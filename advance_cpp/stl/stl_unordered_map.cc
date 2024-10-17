#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
 
int main() {
    // Declare an unordered_map with int as the key and string as the value
    std::unordered_map<int, std::string> umap;
 
    // 1. insert() - Insert key-value pairs
    umap.insert({1, "Apple"});
    umap.insert({2, "Banana"});
    umap.insert({3, "Orange"});
 
    // 2. operator[] - Insert or modify values using the subscript operator
    umap[4] = "Grapes";       // Inserting new pair
    umap[1] = "Green Apple";  // Modifying the value of key 1
 
    // 3. at() - Access elements with bounds checking
    std::cout << "Value at key 1: " << umap.at(1) << std::endl;
 
    // 4. find() - Find if a key exists
    auto it = umap.find(2);
    if (it != umap.end()) {
        std::cout << "Found key 2 with value: " << it->second << std::endl;
    } else {
        std::cout << "Key 2 not found!" << std::endl;
    }
 
    // 5. erase() - Remove elements by key
    umap.erase(3); // Removes key 3 ("Orange")
 
    // 6. size() - Get the number of elements in the unordered_map
    std::cout << "Size of unordered_map: " << umap.size() << std::endl;
 
    // 7. empty() - Check if the unordered_map is empty
    if (umap.empty()) {
        std::cout << "unordered_map is empty." << std::endl;
    } else {
        std::cout << "unordered_map is not empty." << std::endl;
    }
 
    // 8. count() - Check if a key is in the unordered_map (returns 1 if found, 0 otherwise)
    if (umap.count(4) > 0) {
        std::cout << "Key 4 is in the map with value: " << umap[4] << std::endl;
    } else {
        std::cout << "Key 4 is not in the map." << std::endl;
    }
 
    // 9. clear() - Remove all elements
    umap.clear();
    std::cout << "Size after clear: " << umap.size() << std::endl;
 
    // 10. Iterating through the unordered_map
    umap.insert({5, "Mango"});
    umap.insert({6, "Pineapple"});
    
    std::cout << "Elements in unordered_map:" << std::endl;
    for (const auto& pair : umap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
 
    return 0;
}