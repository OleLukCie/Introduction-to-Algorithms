#include <vector>
#include <iostream>
using namespace std;

/* Binary search insertion point (no duplicate elements) */
int binarySearchInsertionSimple(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1; // Initialize closed interval [0, n-1]
    while (i <= j) {
        int m = i + (j - i) / 2; // Calculate midpoint index m
        if (nums[m] < target) {
            i = m + 1; // Target is in interval [m+1, j]
        }
        else if (nums[m] > target) {
            j = m - 1; // Target is in interval [i, m-1]
        }
        else {
            return m; // Found target, return insertion point m
        }
    }
    // Target not found, return insertion point i
    return i;
}

/* Binary search insertion point (with duplicate elements) */
int binarySearchInsertion(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1; // Initialize closed interval [0, n-1]
    while (i <= j) {
        int m = i + (j - i) / 2; // Calculate midpoint index m
        if (nums[m] < target) {
            i = m + 1; // Target is in interval [m+1, j]
        }
        else if (nums[m] > target) {
            j = m - 1; // Target is in interval [i, m-1]
        }
        else {
            j = m - 1; // First element less than target is in [i, m-1]
        }
    }
    // Return insertion point i
    return i;
}

int main() {
    // Test case 1: Array without duplicates
    vector<int> nums1 = { 1, 3, 5, 7, 9 };
    int target1 = 6;
    int result1 = binarySearchInsertionSimple(nums1, target1);
    cout << "Test case 1 (no duplicates):" << endl;
    cout << "Array: [1, 3, 5, 7, 9], Target: " << target1 << endl;
    cout << "Insertion position: " << result1 << endl << endl;

    // Test case 2: Array with duplicates
    vector<int> nums2 = { 1, 2, 2, 2, 3 };
    int target2 = 2;
    int result2 = binarySearchInsertion(nums2, target2);
    cout << "Test case 2 (with duplicates):" << endl;
    cout << "Array: [1, 2, 2, 2, 3], Target: " << target2 << endl;
    cout << "First insertion position: " << result2 << endl << endl;

    // Test case 3: Target smaller than all elements
    vector<int> nums3 = { 2, 4, 6, 8 };
    int target3 = 1;
    int result3 = binarySearchInsertionSimple(nums3, target3);
    cout << "Test case 3 (target smaller than all):" << endl;
    cout << "Array: [2, 4, 6, 8], Target: " << target3 << endl;
    cout << "Insertion position: " << result3 << endl << endl;

    // Test case 4: Target larger than all elements
    vector<int> nums4 = { 3, 6, 9, 12 };
    int target4 = 15;
    int result4 = binarySearchInsertion(nums4, target4);
    cout << "Test case 4 (target larger than all):" << endl;
    cout << "Array: [3, 6, 9, 12], Target: " << target4 << endl;
    cout << "Insertion position: " << result4 << endl;

    return 0;
}
