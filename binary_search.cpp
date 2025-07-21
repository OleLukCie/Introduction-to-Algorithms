#include <iostream>
#include <vector>
using namespace std;

/* Binary search (closed interval) */
int binarySearch(vector<int>& nums, int target) {
    // Initialize closed interval [0, n-1]
    int i = 0, j = nums.size() - 1;
    // Loop until the search interval is empty (when i > j)
    while (i <= j) {
        int m = i + (j - i) / 2;  // Calculate midpoint index m
        if (nums[m] < target)     // Target is in interval [m+1, j]
            i = m + 1;
        else if (nums[m] > target) // Target is in interval [i, m-1]
            j = m - 1;
        else                      // Target found, return its index
            return m;
    }
    // Target not found, return -1
    return -1;
}

/* Binary search (left-closed right-open interval) */
int binarySearchLCRO(vector<int>& nums, int target) {
    // Initialize left-closed right-open interval [0, n)
    int i = 0, j = nums.size();
    // Loop until the search interval is empty (when i == j)
    while (i < j) {
        int m = i + (j - i) / 2;  // Calculate midpoint index m
        if (nums[m] < target)     // Target is in interval [m+1, j)
            i = m + 1;
        else if (nums[m] > target) // Target is in interval [i, m)
            j = m;
        else                      // Target found, return its index
            return m;
    }
    // Target not found, return -1
    return -1;
}

int main() {
    // Create a sorted vector for testing
    vector<int> nums = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int target1 = 23;
    int target2 = 15;

    // Test closed interval binary search
    int result1 = binarySearch(nums, target1);
    int result2 = binarySearch(nums, target2);

    cout << "Testing closed interval binary search:\n";
    if (result1 != -1) {
        cout << "Target " << target1 << " found at index " << result1 << endl;
    }
    else {
        cout << "Target " << target1 << " not found in the array\n";
    }

    if (result2 != -1) {
        cout << "Target " << target2 << " found at index " << result2 << endl;
    }
    else {
        cout << "Target " << target2 << " not found in the array\n";
    }

    // Test left-closed right-open interval binary search
    int result3 = binarySearchLCRO(nums, target1);
    int result4 = binarySearchLCRO(nums, target2);

    cout << "\nTesting left-closed right-open interval binary search:\n";
    if (result3 != -1) {
        cout << "Target " << target1 << " found at index " << result3 << endl;
    }
    else {
        cout << "Target " << target1 << " not found in the array\n";
    }

    if (result4 != -1) {
        cout << "Target " << target2 << " found at index " << result4 << endl;
    }
    else {
        cout << "Target " << target2 << " not found in the array\n";
    }

    return 0;
}
