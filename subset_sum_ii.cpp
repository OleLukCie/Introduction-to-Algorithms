#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Backtracking: Subset Sum II */
void backtrack(vector<int>& state, int target, vector<int>& choices, int start, vector<vector<int>>& res) {
    // Record the solution when subset sum equals target
    if (target == 0) {
        res.push_back(state);
        return;
    }
    // Traverse all choices
    // Pruning 2: Start from 'start' to avoid duplicate subsets
    // Pruning 3: Start from 'start' to avoid selecting the same element repeatedly
    for (int i = start; i < choices.size(); i++) {
        // Pruning 1: If subset sum exceeds target, end the loop directly
        // This is because the array is sorted, subsequent elements are larger, so sum will definitely exceed target
        if (target - choices[i] < 0) {
            break;
        }
        // Pruning 4: If current element is the same as previous one, this search branch is duplicate, skip directly
        if (i > start && choices[i] == choices[i - 1]) {
            continue;
        }
        // Try: Make a choice, update target and start
        state.push_back(choices[i]);
        // Proceed to next round of selection
        backtrack(state, target - choices[i], choices, i + 1, res);
        // Backtrack: Undo the choice, restore to previous state
        state.pop_back();
    }
}

/* Solve Subset Sum II */
vector<vector<int>> subsetSumII(vector<int>& nums, int target) {
    vector<int> state;              // State (current subset)
    sort(nums.begin(), nums.end()); // Sort the nums array
    int start = 0;                  // Starting index for traversal
    vector<vector<int>> res;        // Result list (list of subsets)
    backtrack(state, target, nums, start, res);
    return res;
}

int main() {
    // Example usage
    vector<int> nums = { 1, 2, 2, 3 };
    int target = 3;

    vector<vector<int>> result = subsetSumII(nums, target);

    // Print the result
    cout << "All unique subsets that sum to " << target << ":" << endl;
    cout << "[" << endl;
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "  [";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j != result[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != result.size() - 1) {
            cout << ",";
        }
        cout << endl;
    }
    cout << "]" << endl;

    return 0;
}
