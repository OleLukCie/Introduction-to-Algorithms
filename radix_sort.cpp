#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Get the k-th digit of element num, where exp = 10^(k-1) */
int digit(int num, int exp) {
    // Passing exp instead of k avoids expensive expensive power calculation here
    return (num / exp) % 10;
}

/* Counting sort (sorts nums based on the k-th digit) */
void countingSortDigit(vector<int>& nums, int exp) {
    // Decimal digits range from 0~9, so we need a bucket array of length 10
    vector<int> counter(10, 0);
    int n = nums.size();

    // Count occurrences of each digit 0~9
    for (int i = 0; i < n; i++) {
        int d = digit(nums[i], exp); // Get the k-th digit of nums[i], denoted as d
        counter[d]++;                // Count occurrences of digit d
    }

    // Calculate prefix sums to convert "counts" to "array indices"
    for (int i = 1; i < 10; i++) {
        counter[i] += counter[i - 1];
    }

    // Traverse in reverse to place elements into the result array
    vector<int> res(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        int d = digit(nums[i], exp);
        int j = counter[d] - 1; // Get the index j for digit d
        res[j] = nums[i];       // Place current element at index j
        counter[d]--;           // Decrement the count for digit d
    }

    // Overwrite the original array with the sorted result
    for (int i = 0; i < n; i++)
        nums[i] = res[i];
}

/* Radix sort */
void radixSort(vector<int>& nums) {
    // Get the maximum element to determine the number of digits
    int m = *max_element(nums.begin(), nums.end());

    // Process from least significant digit to most significant digit
    for (int exp = 1; exp <= m; exp *= 10)
        // Perform counting sort on the k-th digit of array elements
        // k = 1 -> exp = 1
        // k = 2 -> exp = 10
        // i.e., exp = 10^(k-1)
        countingSortDigit(nums, exp);
}

int main() {
    // Example array to be sorted
    vector<int> nums = { 170, 45, 75, 90, 802, 24, 2, 66 };

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Perform radix sort
    radixSort(nums);

    cout << "Sorted array:   ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
