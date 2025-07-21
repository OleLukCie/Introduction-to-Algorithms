#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/* Backtracking algorithm: Permutations II */
void backtrack(vector<int>& state, const vector<int>& choices, vector<bool>& selected, vector<vector<int>>& res) {
    // When the state length equals the number of elements, record the solution
    if (state.size() == choices.size()) {
        res.push_back(state);
        return;
    }
    // Traverse all choices
    unordered_set<int> duplicated;
    for (int i = 0; i < choices.size(); i++) {
        int choice = choices[i];
        // Pruning: do not allow repeated selection of elements and equal elements
        if (!selected[i] && duplicated.find(choice) == duplicated.end()) {
            // Try: make a choice and update the state
            duplicated.emplace(choice); // Record the selected element value
            selected[i] = true;
            state.push_back(choice);
            // Proceed to the next round of selection
            backtrack(state, choices, selected, res);
            // Backtrack: undo the choice and restore to the previous state
            selected[i] = false;
            state.pop_back();
        }
    }
}

/* Permutations II */
vector<vector<int>> permutationsII(vector<int> nums) {
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int>> res;
    backtrack(state, nums, selected, res);
    return res;
}

int main() {
    // Example input with duplicate elements
    vector<int> nums = { 1, 1, 2 };

    // Get all unique permutations
    vector<vector<int>> result = permutationsII(nums);

    // Print the result
    cout << "All unique permutations:" << endl;
    for (const auto& perm : result) {
        cout << "[";
        for (size_t i = 0; i < perm.size(); ++i) {
            cout << perm[i];
            if (i < perm.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
