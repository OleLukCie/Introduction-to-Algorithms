#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

/* Bubble Sort */
void bubbleSort(std::vector<int>& nums) {
    // Outer loop: unsorted interval is [0, i]
    for (int i = nums.size() - 1; i > 0; i--) {
        // Inner loop: move the largest element in [0, i] to the end of this interval
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1]) {
                // Swap nums[j] and nums[j + 1]
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
}

/* Bubble Sort with optimization (flag) */
void bubbleSortWithFlag(std::vector<int>& nums) {
    // Outer loop: unsorted interval is [0, i]
    for (int i = nums.size() - 1; i > 0; i--) {
        bool swapped = false; // Initialize flag
        // Inner loop: move the largest element in [0, i] to the end of this interval
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1]) {
                // Swap nums[j] and nums[j + 1]
                std::swap(nums[j], nums[j + 1]);
                swapped = true; // Record that a swap occurred
            }
        }
        if (!swapped)
            break; // No swaps in this pass, array is sorted
    }
}

// Helper function to print the vector
void printVector(const std::vector<int>& nums) {
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test array
    std::vector<int> nums1 = { 64, 34, 25, 12, 22, 11, 90 };
    std::vector<int> nums2 = { 64, 34, 25, 12, 22, 11, 90 };

    std::cout << "Original array: ";
    printVector(nums1);

    // Test basic bubble sort
    bubbleSort(nums1);
    std::cout << "After basic bubble sort: ";
    printVector(nums1);

    // Test optimized bubble sort
    bubbleSortWithFlag(nums2);
    std::cout << "After optimized bubble sort: ";
    printVector(nums2);

    // Test with already sorted array
    std::vector<int> sortedNums = { 1, 2, 3, 4, 5, 6 };
    std::cout << "\nOriginal sorted array: ";
    printVector(sortedNums);

    bubbleSortWithFlag(sortedNums);
    std::cout << "After optimized bubble sort (should remain same): ";
    printVector(sortedNums);

    return 0;
}
