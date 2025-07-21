#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
private:
	TreeNode* root;

public:
	BST() : root(nullptr) {}

	TreeNode* search(int num) {
		TreeNode* cur = root;
		while (cur != nullptr) {
			if (cur->val < num)
				cur = cur->right;
			else if (cur->val > num)
				cur = cur->left;
			else
				break;
		}
		return cur;
	}

	void insert(int num) {
		if (root == nullptr) {
			root = new TreeNode(num);
			return;
		}
		TreeNode* cur = root, * pre = nullptr;
		while (cur != nullptr) {
			if (cur->val == num)
				return;
			pre = cur;
			if (cur->val < num)
				cur = cur->right;
			else
				cur = cur->left;
		}
		TreeNode* node = new TreeNode(num);
		if (pre->val < num)
			pre->right = node;
		else
			pre->left = node;
	}

	void remove(int num) {
		if (root == nullptr)
			return;
		TreeNode* cur = root, * pre = nullptr;
		while (cur != nullptr) {
			if (cur->val == num)
				break;
			pre = cur;
			if (cur->val < num)
				cur = cur->right;
			else
				cur = cur->left;
		}
		if (cur == nullptr)
			return;

		if (cur->left == nullptr || cur->right == nullptr) {
			TreeNode* child = cur->left != nullptr ? cur->left : cur->right;
			if (cur != root) {
				if (pre->left == cur)
					pre->left = child;
				else
					pre->right = child;
			}
			else {
				root = child;
			}
			delete cur;
		}
		else {
			TreeNode* tmp = cur->right;
			while (tmp->left != nullptr) {
				tmp = tmp->left;
			}
			int tmpVal = tmp->val;
			remove(tmp->val);
			cur->val = tmpVal;
		}
	}

	~BST() {
		destroyTree(root);
	}

private:
	void destroyTree(TreeNode* node) {
		if (node == nullptr)	return;
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}
};

int main()
{
	BST bst;

	bst.insert(5);
	bst.insert(3);
	bst.insert(7);
	bst.insert(2);
	bst.insert(4);
	bst.insert(6);
	bst.insert(8);

	TreeNode* found = bst.search(4);
	if (found) {
		std::cout << "Node Found: " << found->val << std::endl;
	}
	else {
		std::cout << "Node Not Found: " << std::endl;
	}

	bst.remove(3);

	return 0;
}