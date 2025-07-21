#include <iostream>
#include <vector>
using namespace std;

/* Backtracking algorithm: Permutations I */
void backtrack(vector<int>& state, const vector<int>& choices, vector<bool>& selected, vector<vector<int>>& res) {
    // When the state length equals the number of elements, record the solution
    if (state.size() == choices.size()) {
        res.push_back(state);
        return;
    }
    // Traverse all choices
    for (int i = 0; i < choices.size(); i++) {
        int choice = choices[i];
        // Pruning: Do not allow repeated selection of elements
        if (!selected[i]) {
            // Try: Make a choice and update the state
            selected[i] = true;
            state.push_back(choice);
            // Proceed to the next round of selection
            backtrack(state, choices, selected, res);
            // Backtrack: Undo the choice and restore the previous state
            selected[i] = false;
            state.pop_back();
        }
    }
}

/* Permutations I */
vector<vector<int>> permutationsI(vector<int> nums) {
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int>> res;
    backtrack(state, nums, selected, res);
    return res;
}

int main() {
    // Example input
    vector<int> nums = { 1, 2, 3 };

    // Calculate all permutations
    vector<vector<int>> result = permutationsI(nums);

    // Print the result
    cout << "Input: ";
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << nums[i];
    }
    cout << endl;

    cout << "Total permutations: " << result.size() << endl;
    cout << "All permutations:" << endl;
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "Permutation " << (i + 1) << ": ";
        for (size_t j = 0; j < result[i].size(); ++j) {
            if (j > 0) cout << ", ";
            cout << result[i][j];
        }
        cout << endl;
    }

    return 0;
}
