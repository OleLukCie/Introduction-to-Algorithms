#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>

struct TreeNode {
    int val{};
    int height = 0;
    TreeNode* left{};
    TreeNode* right{};
    TreeNode() = default;
    explicit TreeNode(int x) : val(x) {}
};

class AVLTree {
private:
    TreeNode* root = nullptr;

    int height(TreeNode* node);
    void updateHeight(TreeNode* node);
    int balanceFactor(TreeNode* node);
    TreeNode* rightRotate(TreeNode* node);
    TreeNode* leftRotate(TreeNode* node);
    TreeNode* rotate(TreeNode* node);
    TreeNode* insertHelper(TreeNode* node, int val);
    TreeNode* removeHelper(TreeNode* node, int val);
    bool searchHelper(TreeNode* node, int val);
    void inorderHelper(TreeNode* node);
    void destroyTree(TreeNode* node);

public:
    AVLTree() = default;
    ~AVLTree();
    void insert(int val);
    void remove(int val);
    bool search(int val);
    void inorderTraversal();
};

#endif // AVL_TREE_H
