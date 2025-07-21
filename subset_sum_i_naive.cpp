#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Backtracking algorithm: Subset Sum I */
void backtrack(vector<int>& state, int target, int total, vector<int>& choices, vector<vector<int>>& res) {
    // Record solution when subset sum equals target
    if (total == target) {
        res.push_back(state);
        return;
    }
    // Traverse all choices
    for (size_t i = 0; i < choices.size(); i++) {
        // Pruning: Skip if adding current choice exceeds target
        if (total + choices[i] > target) {
            continue;
        }
        // Try: Make a choice and update total
        state.push_back(choices[i]);
        // Proceed to next selection
        backtrack(state, target, total + choices[i], choices, res);
        // Backtrack: Undo the choice
        state.pop_back();
    }
}

/* Solve Subset Sum I (includes duplicate subsets) */
vector<vector<int>> subsetSumINaive(vector<int>& nums, int target) {
    vector<int> state;       // Current state (subset)
    int total = 0;           // Sum of current subset
    vector<vector<int>> res; // Result list (list of subsets)
    backtrack(state, target, total, nums, res);
    return res;
}

// Helper function to print a vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main() {
    // Example 1: Basic test case
    vector<int> nums1 = { 2, 3, 5 };
    int target1 = 8;
    cout << "Example 1:" << endl;
    cout << "Numbers: ";
    printVector(nums1);
    cout << ", Target: " << target1 << endl;

    vector<vector<int>> result1 = subsetSumINaive(nums1, target1);
    cout << "All subsets that sum to " << target1 << ":" << endl;
    for (const auto& subset : result1) {
        printVector(subset);
        cout << endl;
    }

    // Example 2: Another test case with different values
    vector<int> nums2 = { 1, 2, 3, 4 };
    int target2 = 5;
    cout << "\nExample 2:" << endl;
    cout << "Numbers: ";
    printVector(nums2);
    cout << ", Target: " << target2 << endl;

    vector<vector<int>> result2 = subsetSumINaive(nums2, target2);
    cout << "All subsets that sum to " << target2 << ":" << endl;
    for (const auto& subset : result2) {
        printVector(subset);
        cout << endl;
    }

    return 0;
}
