#include <iostream>
#include <vector>

// Define binary tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Container to store results
std::vector<TreeNode*> results;

// Pre-order traversal to find nodes with value 7
void preOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    if (root->val == 7) {
        // Record the solution
        results.push_back(root);
    }
    preOrder(root->left);
    preOrder(root->right);
}

// Helper function: Create a sample binary tree
TreeNode* createSampleTree() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(7);

    return root;
}

// Helper function: Free binary tree memory
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Create sample binary tree
    TreeNode* root = createSampleTree();

    // Perform pre-order traversal search
    preOrder(root);

    // Output results
    std::cout << "Number of nodes with value 7 found: " << results.size() << std::endl;
    std::cout << "Values of these nodes: ";
    for (TreeNode* node : results) {
        std::cout << node->val << " ";
    }
    std::cout << std::endl;

    // Free memory
    deleteTree(root);
    results.clear();

    return 0;
}
