#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* dfs(vector<int>& preorder, unordered_map<int, int>& inorderMap, int i, int l, int r) {
    if (r - l < 0)
        return NULL;
    TreeNode* root = new TreeNode(preorder[i]);
    int m = inorderMap[preorder[i]];
    root->left = dfs(preorder, inorderMap, i + 1, l, m - 1);
    root->right = dfs(preorder, inorderMap, i + 1 + m - l, m + 1, r);
    return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }
    TreeNode* root = dfs(preorder, inorderMap, 0, 0, inorder.size() - 1);
    return root;
}

// Helper function to print inorder traversal (for verification)
void printInorder(TreeNode* node) {
    if (node == nullptr)
        return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

// Helper function to print preorder traversal (for verification)
void printPreorder(TreeNode* node) {
    if (node == nullptr)
        return;
    cout << node->val << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    // Example input
    vector<int> preorder = { 3, 9, 20, 15, 7 };
    vector<int> inorder = { 9, 3, 15, 20, 7 };

    cout << "Building binary tree from preorder and inorder traversals..." << endl;
    cout << "Preorder traversal: ";
    for (int num : preorder) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int num : inorder) {
        cout << num << " ";
    }
    cout << endl << endl;

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Verifying the constructed tree:" << endl;
    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    cout << "Preorder traversal of constructed tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
