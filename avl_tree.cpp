#include "avl_tree.h"
#include <cstdio>

int AVLTree::height(TreeNode* node) {
    return node == nullptr ? -1 : node->height;
}

void AVLTree::updateHeight(TreeNode* node) {
    node->height = std::max(height(node->left), height(node->right)) + 1;
}

int AVLTree::balanceFactor(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

TreeNode* AVLTree::rightRotate(TreeNode* node) {
    TreeNode* child = node->left;
    TreeNode* grandChild = child->right;
    child->right = node;
    node->left = grandChild;
    updateHeight(node);
    updateHeight(child);
    return child;
}

TreeNode* AVLTree::leftRotate(TreeNode* node) {
    TreeNode* child = node->right;
    TreeNode* grandChild = child->left;
    child->left = node;
    node->right = grandChild;
    updateHeight(node);
    updateHeight(child);
    return child;
}

TreeNode* AVLTree::rotate(TreeNode* node) {
    int _balanceFactor = balanceFactor(node);
    if (_balanceFactor > 1) {
        if (balanceFactor(node->left) >= 0) {
            return rightRotate(node);
        }
        else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (_balanceFactor < -1) {
        if (balanceFactor(node->right) <= 0) {
            return leftRotate(node);
        }
        else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}

TreeNode* AVLTree::insertHelper(TreeNode* node, int val) {
    if (node == nullptr)
        return new TreeNode(val);
    if (val < node->val)
        node->left = insertHelper(node->left, val);
    else if (val > node->val)
        node->right = insertHelper(node->right, val);
    else
        return node;
    updateHeight(node);
    node = rotate(node);
    return node;
}

TreeNode* AVLTree::removeHelper(TreeNode* node, int val) {
    if (node == nullptr)
        return nullptr;
    if (val < node->val)
        node->left = removeHelper(node->left, val);
    else if (val > node->val)
        node->right = removeHelper(node->right, val);
    else {
        if (node->left == nullptr || node->right == nullptr) {
            TreeNode* child = node->left != nullptr ? node->left : node->right;
            if (child == nullptr) {
                delete node;
                return nullptr;
            }
            else {
                delete node;
                node = child;
            }
        }
        else {
            TreeNode* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            int tempVal = temp->val;
            node->right = removeHelper(node->right, temp->val);
            node->val = tempVal;
        }
    }
    if (node == nullptr)
        return nullptr;
    updateHeight(node);
    node = rotate(node);
    return node;
}

bool AVLTree::searchHelper(TreeNode* node, int val) {
    if (node == nullptr)
        return false;
    if (val == node->val)
        return true;
    if (val < node->val)
        return searchHelper(node->left, val);
    else
        return searchHelper(node->right, val);
}

void AVLTree::inorderHelper(TreeNode* node) {
    if (node == nullptr)
        return;
    inorderHelper(node->left);
    printf("%d ", node->val);
    inorderHelper(node->right);
}

void AVLTree::destroyTree(TreeNode* node) {
    if (node == nullptr)
        return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}


AVLTree::~AVLTree() {
    destroyTree(root);
    root = nullptr;
}

void AVLTree::insert(int val) {
    root = insertHelper(root, val);
}

void AVLTree::remove(int val) {
    root = removeHelper(root, val);
}

bool AVLTree::search(int val) {
    return searchHelper(root, val);
}

void AVLTree::inorderTraversal() {
    inorderHelper(root);
    printf("\n");
}
