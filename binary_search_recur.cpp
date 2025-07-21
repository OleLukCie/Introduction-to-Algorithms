#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<int>& nums, int target, int i, int j) {
    if (i > j) {
        return -1;
    }
    int m = (i + j) / 2;
    if (nums[m] < target) {
        return dfs(nums, target, m + 1, j);
    }
    else if (nums[m] > target) {
        return dfs(nums, target, i, m - 1);
    }
    else {
        return m;
    }
}

int binarySearch(vector<int>& nums, int target) {
    int n = nums.size();
    return dfs(nums, target, 0, n - 1);
}

int main() {
    // Example sorted array
    vector<int> numbers = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int searchTarget = 23;

    // Perform binary search
    int result = binarySearch(numbers, searchTarget);

    // Output results in English
    cout << "Searching for " << searchTarget << " in the array:" << endl;
    cout << "[ ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << "]" << endl;

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    }
    else {
        cout << "Element not found in the array" << endl;
    }

    // Additional test case
    int anotherTarget = 10;
    result = binarySearch(numbers, anotherTarget);
    cout << "\nSearching for " << anotherTarget << ":" << endl;
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    }
    else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
