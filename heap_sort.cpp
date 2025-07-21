#include <iostream>
#include <vector>
using namespace std;

/* Heapify from top to bottom starting at node i, with heap size n */
void siftDown(vector<int>& nums, int n, int i) {
    while (true) {
        // Determine the largest node among i, left child l, and right child r
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int maxIdx = i;
        if (l < n && nums[l] > nums[maxIdx])
            maxIdx = l;
        if (r < n && nums[r] > nums[maxIdx])
            maxIdx = r;
        // If current node is the largest or children are out of bounds, exit loop
        if (maxIdx == i) {
            break;
        }
        // Swap current node with the largest child
        swap(nums[i], nums[maxIdx]);
        // Continue heapifying from the new position
        i = maxIdx;
    }
}

/* Heap Sort algorithm */
void heapSort(vector<int>& nums) {
    // Build the heap by heapifying non-leaf nodes
    for (int i = nums.size() / 2 - 1; i >= 0; --i) {
        siftDown(nums, nums.size(), i);
    }
    // Extract the maximum element from the heap, repeat n-1 times
    for (int i = nums.size() - 1; i > 0; --i) {
        // Swap root (maximum) with the last element
        swap(nums[0], nums[i]);
        // Heapify the remaining elements
        siftDown(nums, i, 0);
    }
}

int main() {
    // Example array to be sorted
    vector<int> numbers = { 9, 3, 1, 7, 4, 8, 6, 2, 5 };

    cout << "Original array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Perform heap sort
    heapSort(numbers);

    cout << "Sorted array:   ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
