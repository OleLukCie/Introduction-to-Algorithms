#include <iostream>
#include <vector>
#include <algorithm>

// Use the standard namespace to avoid needing std:: prefix everywhere
using namespace std;

/* Bucket Sort */
void bucketSort(vector<float>& nums) {
    // Check if the input vector is empty to avoid division by zero
    if (nums.empty()) {
        return;
    }

    // Initialize k = n/2 buckets, expecting 2 elements per bucket
    int k = nums.size() / 2;
    vector<vector<float>> buckets(k);

    // 1. Distribute array elements into buckets
    for (float num : nums) {
        // Input range is [0, 1), map to index range [0, k-1] using num * k
        int i = num * k;
        // Ensure we don't go out of bounds
        if (i >= k) i = k - 1;
        // Add num to bucket i
        buckets[i].push_back(num);
    }

    // 2. Sort each bucket
    for (vector<float>& bucket : buckets) {
        // Use built-in sort function
        sort(bucket.begin(), bucket.end());
    }

    // 3. Merge results by traversing buckets
    int i = 0;
    for (vector<float>& bucket : buckets) {
        for (float num : bucket) {
            nums[i++] = num;
        }
    }
}

int main() {
    // Example array with numbers in [0, 1) range
    vector<float> numbers = { 0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51 };

    cout << "Original array: ";
    for (float num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Perform bucket sort
    bucketSort(numbers);

    cout << "Sorted array:   ";
    for (float num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
