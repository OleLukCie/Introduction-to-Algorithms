#include <iostream>
#include <vector>
using namespace std;

/* Insertion Sort */
void insertionSort(vector<int>& nums) {
    // Outer loop: sorted interval is [0, i-1]
    for (int i = 1; i < nums.size(); i++) {
        int base = nums[i], j = i - 1;
        // Inner loop: insert base into the correct position in [0, i-1]
        while (j >= 0 && nums[j] > base) {
            nums[j + 1] = nums[j]; // Move nums[j] one position to the right
            j--;
        }
        nums[j + 1] = base; // Assign base to the correct position
    }
}

int main() {
    // Example array to be sorted
    vector<int> numbers = { 5, 2, 9, 1, 5, 6 };

    // Print original array
    cout << "Original array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Perform insertion sort
    insertionSort(numbers);

    // Print sorted array
    cout << "Sorted array:   ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
