#include <iostream>
#include <vector>
using namespace std;

// Define binary tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSolution(vector<TreeNode*>& state) {
    return !state.empty() && state.back()->val == 7;
}

void recordSolution(vector<TreeNode*>& state, vector<vector<TreeNode*>>& res) {
    res.push_back(state);
}

bool isValid(vector<TreeNode*>& state, TreeNode* choice) {
    return choice != nullptr && choice->val != 3;
}

void makeChoice(vector<TreeNode*>& state, TreeNode* choice) {
    state.push_back(choice);
}

void undoChoice(vector<TreeNode*>& state, TreeNode* choice) {
    state.pop_back();
}

void backtrack(vector<TreeNode*>& state, vector<TreeNode*>& choices, vector<vector<TreeNode*>>& res) {
    if (isSolution(state)) {
        recordSolution(state, res);
    }
    for (TreeNode* choice : choices) {
        if (isValid(state, choice)) {
            makeChoice(state, choice);
            vector<TreeNode*> nextChoices{ choice->left, choice->right };
            backtrack(state, nextChoices, res);
            undoChoice(state, choice);
        }
    }
}

// Helper function to delete the tree and free memory
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Construct a sample binary tree
    // Example tree structure:
    //        1
    //       / \
    //      2   3    <-- This node will be pruned
    //     /   / \
    //    7   7   4
    //   /
    //  5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);  // This node will be pruned
    root->left->left = new TreeNode(7);  // First node with value 7
    root->right->left = new TreeNode(7); // This node won't be found due to pruning
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(5);

    // Initialize backtracking
    vector<TreeNode*> state;
    vector<vector<TreeNode*>> results;
    vector<TreeNode*> initialChoices{ root };

    // Execute backtracking algorithm
    backtrack(state, initialChoices, results);

    // Output the results
    cout << "Found " << results.size() << " paths to nodes with value 7:" << endl;
    for (size_t i = 0; i < results.size(); ++i) {
        cout << "Path " << i + 1 << ": ";
        for (size_t j = 0; j < results[i].size(); ++j) {
            cout << results[i][j]->val;
            if (j != results[i].size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    // Clean up memory
    deleteTree(root);

    return 0;
}
