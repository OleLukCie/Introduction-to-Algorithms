#include <iostream>
#include <unordered_map>

int main() {
    // Create a hash map (unordered_map)
    std::unordered_map<std::string, int> map;

    // Insert key-value pairs
    map["apple"] = 1;
    map["banana"] = 2;
    map["cherry"] = 3;

    // Range-based for loop traversal (C++11+)
    std::cout << "Range-based for loop traversal:" << std::endl;
    for (const auto& kv : map) {
        std::cout << kv.first << " -> " << kv.second << std::endl;
    }

    // Iterator-based traversal
    std::cout << "\nIterator-based traversal:" << std::endl;
    for (auto iter = map.begin(); iter != map.end(); ++iter) {
        std::cout << iter->first << " -> " << iter->second << std::endl;
    }

    // Traverse keys only
    std::cout << "\nTraverse keys only:" << std::endl;
    for (const auto& pair : map) {
        std::cout << pair.first << std::endl;
    }

    // Traverse values only
    std::cout << "\nTraverse values only:" << std::endl;
    for (const auto& pair : map) {
        std::cout << pair.second << std::endl;
    }

    return 0;
}