#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Backtracking: Subset Sum I */
void backtrack(vector<int>& state, int target, vector<int>& choices, int start, vector<vector<int>>& res) {
    // Record the solution when subset sum equals target
    if (target == 0) {
        res.push_back(state);
        return;
    }
    // Traverse all choices
    // Pruning 2: Start from 'start' to avoid duplicate subsets
    for (int i = start; i < choices.size(); i++) {
        // Pruning 1: If subset sum exceeds target, end the loop directly
        // This is because the array is sorted, subsequent elements are larger, and sum will definitely exceed target
        if (target - choices[i] < 0) {
            break;
        }
        // Try: Make a choice, update target and start
        state.push_back(choices[i]);
        // Proceed to next round of selection
        backtrack(state, target - choices[i], choices, i, res);
        // Backtrack: Undo the choice, restore to previous state
        state.pop_back();
    }
}

/* Solve Subset Sum I */
vector<vector<int>> subsetSumI(vector<int>& nums, int target) {
    vector<int> state;              // State (current subset)
    sort(nums.begin(), nums.end()); // Sort the nums array
    int start = 0;                  // Starting index for traversal
    vector<vector<int>> res;        // Result list (list of subsets)
    backtrack(state, target, nums, start, res);
    return res;
}

int main() {
    // Example usage
    vector<int> nums = { 2, 3, 6, 7 };
    int target = 7;

    // Get all subsets that sum to target
    vector<vector<int>> result = subsetSumI(nums, target);

    // Print the results
    cout << "All subsets that sum to " << target << ":" << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
