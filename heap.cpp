#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Custom type example
struct Person {
    string name;
    int age;

    // Overload less than operator for max-heap (by age)
    bool operator<(const Person& other) const {
        return age < other.age; // Older people have higher priority
    }
};

// TopK problem: Find the k largest elements from an array
vector<int> findTopK(vector<int>& nums, int k) {
    // Use a min-heap to store the k largest elements, with the smallest of them at the top
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        if (minHeap.size() < k) {
            minHeap.push(num);
        }
        else if (num > minHeap.top()) {
            minHeap.pop();
            minHeap.push(num);
        }
    }

    // Convert heap elements to vector
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    reverse(result.begin(), result.end()); // Sort from largest to smallest
    return result;
}

int main() {
    // Heap traversal (priority_queue has no iterators, need to pop elements to traverse)
    priority_queue<int> maxHeap;
    for (int i = 1; i <= 5; ++i) {
        maxHeap.push(i);
    }
    cout << "Heap elements (from largest to smallest): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    // Heap with custom type
    priority_queue<Person> peopleHeap;
    peopleHeap.push({ "Alice", 25 });
    peopleHeap.push({ "Bob", 30 });
    peopleHeap.push({ "Charlie", 20 });
    cout << "Oldest person: " << peopleHeap.top().name << ", " << peopleHeap.top().age << " years old" << endl;

    // TopK example
    vector<int> nums = { 3, 1, 4, 1, 5, 9, 2, 6 };
    int k = 3;
    vector<int> topK = findTopK(nums, k);
    cout << "The " << k << " largest elements: ";
    for (int num : topK) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}