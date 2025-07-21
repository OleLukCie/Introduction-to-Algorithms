#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;

/* Counting Sort - Naive Implementation */
// Simple implementation, cannot be used to sort objects
void countingSortNaive(vector<int>& nums) {
    // 1. Find the maximum element m in the array
    int m = 0;
    for (int num : nums) {
        m = max(m, num);
    }
    // 2. Count the occurrences of each number
    // counter[num] represents the count of num
    vector<int> counter(m + 1, 0);
    for (int num : nums) {
        counter[num]++;
    }
    // 3. Traverse counter and fill elements back to original array nums
    int i = 0;
    for (int num = 0; num < m + 1; num++) {
        for (int j = 0; j < counter[num]; j++, i++) {
            nums[i] = num;
        }
    }
}

/* Counting Sort - Complete Implementation */
// Full implementation, can sort objects and is stable
void countingSort(vector<int>& nums) {
    // 1. Find the maximum element m in the array
    int m = 0;
    for (int num : nums) {
        m = max(m, num);
    }
    // 2. Count the occurrences of each number
    // counter[num] represents the count of num
    vector<int> counter(m + 1, 0);
    for (int num : nums) {
        counter[num]++;
    }
    // 3. Calculate prefix sum of counter, converting "count" to "last index"
    // counter[num]-1 is the last occurrence index of num in res
    for (int i = 0; i < m; i++) {
        counter[i + 1] += counter[i];
    }
    // 4. Traverse nums in reverse and place elements into result array res
    // Initialize result array res
    int n = nums.size();
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--) {
        int num = nums[i];
        res[counter[num] - 1] = num; // Place num at the corresponding index
        counter[num]--;              // Decrement prefix sum to get next index for num
    }
    // Overwrite original array with result
    nums = res;
}

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    // Create a test array
    vector<int> numbers1 = { 4, 2, 2, 8, 3, 3, 1 };
    vector<int> numbers2 = numbers1; // Make a copy for the second sort

    cout << "Original array: ";
    printVector(numbers1);

    // Demonstrate naive counting sort
    countingSortNaive(numbers1);
    cout << "After naive countingSortNaive: ";
    printVector(numbers1);

    // Demonstrate complete counting sort
    countingSort(numbers2);
    cout << "After countingSort (stable): ";
    printVector(numbers2);

    // Test with another array containing duplicates
    vector<int> numbers3 = { 5, 3, 5, 1, 5, 2, 5, 4 };
    cout << "\nAnother test array: ";
    printVector(numbers3);

    countingSort(numbers3);
    cout << "After countingSort: ";
    printVector(numbers3);

    return 0;
}
