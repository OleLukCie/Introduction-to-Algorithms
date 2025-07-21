#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> vec;

void preOrder(TreeNode* root) {
	if (root == nullptr)
		return;
	vec.push_back(root->val);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(TreeNode* root) {
	if (root == nullptr)
		return;
	inOrder(root->left);
	vec.push_back(root->val);
	inOrder(root->right);
}

void postOrder(TreeNode* root) {
	if (root == nullptr)
		return;
	postOrder(root->left);
	postOrder(root->right);
	vec.push_back(root->val);
}

void printVector(const vector<int>& v) {
	for (int num : v) {
		cout << num << " ";
	}
	cout << endl;
}

int main() {
	//       1
	//      / \
    //     2   3
	//    / \
    //   4   5
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	//	PreOrder
	vec.clear();
	preOrder(root);
	cout << "PreOrder Result: ";
	printVector(vec);

	//	InOrder
	vec.clear();
	inOrder(root);
	cout << "InOrder Result: ";
	printVector(vec);

	//	PostOrder
	vec.clear();
	postOrder(root);
	cout << "PostOrder Result: ";
	printVector(vec);

	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}