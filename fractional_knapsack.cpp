#include <iostream>
#include <vector>
#include <algorithm>

/* Item */
class Item {
public:
    int w; // Item weight
    int v; // Item value

    Item(int w, int v) : w(w), v(v) {}
};

/* Fractional Knapsack: Greedy Algorithm */
double fractionalKnapsack(std::vector<int>& wgt, std::vector<int>& val, int cap) {
    // Create item list with weight and value attributes
    std::vector<Item> items;
    for (int i = 0; i < wgt.size(); i++) {
        items.push_back(Item(wgt[i], val[i]));
    }
    // Sort by value-to-weight ratio in descending order
    std::sort(items.begin(), items.end(), [](Item& a, Item& b) {
        return (double)a.v / a.w > (double)b.v / b.w;
        });
    // Greedy selection loop
    double res = 0;
    for (auto& item : items) {
        if (item.w <= cap) {
            // Take the entire item if capacity allows
            res += item.v;
            cap -= item.w;
        }
        else {
            // Take a fraction of the item if capacity is insufficient
            res += (double)item.v / item.w * cap;
            // No remaining capacity, exit loop
            break;
        }
    }
    return res;
}

int main() {
    // Example: item weights
    std::vector<int> weights = { 10, 20, 30 };
    // Example: corresponding item values
    std::vector<int> values = { 60, 100, 120 };
    // Knapsack capacity
    int capacity = 50;

    // Calculate maximum value for the fractional knapsack
    double maxValue = fractionalKnapsack(weights, values, capacity);

    // Output results
    std::cout << "Fractional Knapsack Problem Demonstration" << std::endl;
    std::cout << "Item Weights: ";
    for (int w : weights) {
        std::cout << w << " ";
    }
    std::cout << std::endl;

    std::cout << "Item Values:  ";
    for (int v : values) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    std::cout << "Knapsack Capacity: " << capacity << std::endl;
    std::cout << "Maximum Value Achievable: " << maxValue << std::endl;

    return 0;
}
