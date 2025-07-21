#include <iostream>
#include <vector>
using namespace std;

int medianThree(vector<int>& nums, int left, int mid, int right) {
    int l = nums[left], m = nums[mid], r = nums[right];
    if ((l <= m && m <= r) || (r <= m && m <= l))
        return mid; // m is the median
    if ((m <= l && l <= r) || (r <= l && l <= m))
        return left; // l is the median
    return right; // r is the median
}

int partition(vector<int>& nums, int left, int right) {
    // Select median of three as pivot
    int med = medianThree(nums, left, (left + right) / 2, right);
    // Swap median to leftmost position
    swap(nums[left], nums[med]);

    // Use nums[left] as pivot
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left])
            j--;                // Find first element less than pivot from right
        while (i < j && nums[i] <= nums[left])
            i++;                // Find first element greater than pivot from left
        swap(nums[i], nums[j]); // Swap these two elements
    }
    swap(nums[i], nums[left]);  // Move pivot to correct position
    return i;                   // Return pivot index
}

void quickSort(vector<int>& nums, int left, int right) {
    // Terminate when subarray length is 1
    while (left < right) {
        // Partition operation
        int pivot = partition(nums, left, right);
        // Recursively sort the shorter subarray
        if (pivot - left < right - pivot) {
            quickSort(nums, left, pivot - 1); // Recursively sort left subarray
            left = pivot + 1;                 // Remaining unsorted interval: [pivot + 1, right]
        }
        else {
            quickSort(nums, pivot + 1, right); // Recursively sort right subarray
            right = pivot - 1;                 // Remaining unsorted interval: [left, pivot - 1]
        }
    }
}

int main() {
    // Example usage
    vector<int> nums = { 3, 6, 8, 10, 1, 2, 1 };

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Perform quick sort
    quickSort(nums, 0, nums.size() - 1);

    cout << "Sorted array:   ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
