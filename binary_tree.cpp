#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    cout << "Result: ";
    cout << n1->val << " ";
    cout << n1->left->val << " ";
    cout << n1->left->left->val << " ";
    cout << n1->left->right->val << " ";
    cout << n1->right->val << endl;

    TreeNode* P = new TreeNode(0);
    n1->left = P;
    P->left = n2;
    n1->left = n2;

    delete P;

    return 0;
}