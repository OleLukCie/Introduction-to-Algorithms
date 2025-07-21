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

// Global variables to store path and results
vector<TreeNode*> path;
vector<vector<TreeNode*>> results;

// Pre-order traversal function: find nodes with value 7 and record paths
void preOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // Try: add current node to path
    path.push_back(root);
    // If target node (value 7) is found, record current path
    if (root->val == 7) {
        results.push_back(path);
    }
    // Recursively traverse left subtree
    preOrder(root->left);
    // Recursively traverse right subtree
    preOrder(root->right);
    // Backtrack: remove current node from path
    path.pop_back();
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
    //      2   3
    //     /   / \
    //    7   7   4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(7);  // First node with value 7
    root->right->left = new TreeNode(7); // Second node with value 7
    root->right->right = new TreeNode(4);

    // Perform pre-order traversal to find paths to nodes with value 7
    preOrder(root);

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
