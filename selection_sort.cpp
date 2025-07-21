#include <vector>
#include <iostream>
using namespace std;

/*
 * Selection Sort Algorithm
 * Time Complexity: O(n?) - quadratic time complexity
 * Space Complexity: O(1) - constant space complexity (in-place sorting)
 *
 * The algorithm works by dividing the array into a sorted and an unsorted region.
 * It repeatedly finds the minimum element from the unsorted region and swaps it
 * with the first element of the unsorted region, expanding the sorted region by one.
 */
void selectionSort(vector<int>& nums) {
    int n = nums.size();

    // Outer loop: the unsorted region is [i, n-1]
    for (int i = 0; i < n - 1; i++) {
        // Inner loop: find the minimum element in the unsorted region
        int minIndex = i;  // Index of the minimum element found so far
        for (int j = i + 1; j < n; j++) {
            // If current element is smaller than the found minimum, update minIndex
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted region
        swap(nums[i], nums[minIndex]);
    }
}

// Helper function to print a vector
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Example usage of selection sort
    vector<int> numbers = { 64, 25, 12, 22, 11 };

    cout << "Original array: ";
    printVector(numbers);

    // Perform selection sort
    selectionSort(numbers);

    cout << "Sorted array:   ";
    printVector(numbers);

    // Another test case with negative numbers
    vector<int> testCase = { 5, -3, 8, 0, 2, -1 };
    cout << "\nAnother test case - Original: ";
    printVector(testCase);

    selectionSort(testCase);
    cout << "Another test case - Sorted:   ";
    printVector(testCase);

    return 0;
}
