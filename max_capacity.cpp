#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Maximum capacity: Greedy algorithm */
int maxCapacity(vector<int>& ht) {
    // Initialize i, j at both ends of the array
    int i = 0, j = ht.size() - 1;
    // Initial maximum capacity is 0
    int res = 0;
    // Greedily select until the two pointers meet
    while (i < j) {
        // Update maximum capacity
        int cap = min(ht[i], ht[j]) * (j - i);
        res = max(res, cap);
        // Move the shorter board inward
        if (ht[i] < ht[j]) {
            i++;
        }
        else {
            j--;
        }
    }
    return res;
}

int main() {
    // Example test cases
    vector<int> test1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    vector<int> test2 = { 1, 1 };
    vector<int> test3 = { 4, 3, 2, 1, 4 };

    // Calculate and display results
    cout << "Test case 1: [1, 8, 6, 2, 5, 4, 8, 3, 7]" << endl;
    cout << "Maximum capacity: " << maxCapacity(test1) << endl << endl;

    cout << "Test case 2: [1, 1]" << endl;
    cout << "Maximum capacity: " << maxCapacity(test2) << endl << endl;

    cout << "Test case 3: [4, 3, 2, 1, 4]" << endl;
    cout << "Maximum capacity: " << maxCapacity(test3) << endl;

    return 0;
}
