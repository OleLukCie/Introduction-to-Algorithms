#include <iostream>
#include <vector>
using namespace std;

/* Merge left and right subarrays */
void merge(vector<int>& nums, int left, int mid, int right) {
    // Left subarray range: [left, mid], right subarray range: [mid+1, right]
    // Create a temporary array to store the merged result
    vector<int> temp(right - left + 1);
    // Initialize starting indices for left and right subarrays
    int i = left, j = mid + 1, k = 0;

    // Compare elements from both subarrays and copy the smaller one to temp
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    // Copy remaining elements of left subarray
    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    // Copy remaining elements of right subarray
    while (j <= right) {
        temp[k++] = nums[j++];
    }

    // Copy elements from temp back to the original array
    for (k = 0; k < temp.size(); k++) {
        nums[left + k] = temp[k];
    }
}

/* Merge Sort */
void mergeSort(vector<int>& nums, int left, int right) {
    // Termination condition
    if (left >= right)
        return; // Terminate recursion when subarray length is 1

    // Divide phase
    int mid = left + (right - left) / 2;    // Calculate midpoint
    mergeSort(nums, left, mid);             // Recursively sort left subarray
    mergeSort(nums, mid + 1, right);        // Recursively sort right subarray

    // Merge phase
    merge(nums, left, mid, right);
}

int main() {
    // Example array to be sorted
    vector<int> numbers = { 8, 3, 1, 7, 0, 10, 2 };

    cout << "Original array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Perform merge sort
    mergeSort(numbers, 0, numbers.size() - 1);

    cout << "Sorted array:   ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
