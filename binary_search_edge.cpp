#include <vector>
using namespace std;

/* Find insertion position for target in sorted array */
int binarySearchInsertion(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int insertionIndex = nums.size();  // Default insertion at the end

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Prevent potential overflow

        if (nums[mid] >= target) {
            insertionIndex = mid;  // Record potential insertion position
            right = mid - 1;       // Search left half for earlier position
        }
        else {
            left = mid + 1;        // Search right half
        }
    }

    return insertionIndex;
}

/* Find leftmost occurrence of target */
int binarySearchLeftEdge(vector<int>& nums, int target) {
    // Equivalent to finding insertion point for target
    int i = binarySearchInsertion(nums, target);
    // Target not found, return -1
    if (i == nums.size() || nums[i] != target) {
        return -1;
    }
    // Target found, return index i
    return i;
}

/* Find rightmost occurrence of target */
int binarySearchRightEdge(vector<int>& nums, int target) {
    // Convert to finding leftmost occurrence of target + 1
    int i = binarySearchInsertion(nums, target + 1);
    // j points to rightmost target, i points to first element greater than target
    int j = i - 1;
    // Target not found, return -1
    if (j == -1 || nums[j] != target) {
        return -1;
    }
    // Target found, return index j
    return j;
}
