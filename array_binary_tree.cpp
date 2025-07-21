#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

class ArrayBinaryTree {
public:
	ArrayBinaryTree(vector<int> arr) {
		tree = arr;
	}

	int size() {
		return tree.size();
	}
	
	int val(int i) {
		if (i < 0 || i >= size())
			return INT_MAX;
		return tree[i];
	}

	int left(int i) {
		return 2 * i + 1;
	}

	int right(int i) {
		return 2 * i + 2;
	}

	int parent(int i) {
		return (i - 1) / 2;
	}

	vector<int> levelOrder() {
		vector<int> res;
		for (int i = 0; i < size(); i++) {
			if (val(i) != INT_MAX)
				res.push_back(val(i));
		}
		return res;
	}

	vector<int> preOrder() {
		vector<int> res;
		dfs(0, "pre", res);
		return res;
	}

	vector<int> inOrder() {
		vector<int> res;
		dfs(0, "in", res);
		return res;
	}

	vector<int> postOrder() {
		vector<int> res;
		dfs(0, "post", res);
		return res;
	}

private:
	vector<int> tree;

	void dfs(int i, string order, vector<int>& res) {
		if (val(i) == INT_MAX)
			return;

		if (order == "pre")
			res.push_back(val(i));
		dfs(left(i), order, res);

		if (order == "in")
			res.push_back(val(i));
		dfs(right(i), order, res);

		if (order == "post")
			res.push_back(val(i));
	}
};

int main() {
	vector<int> arr = { 1, 2, 3, 4, INT_MAX, 6, 7, 8, 9, INT_MAX, INT_MAX, 12, INT_MAX, INT_MAX, 15 };
	ArrayBinaryTree tree(arr);

	cout << "LevelOrder: ";
	for (int val : tree.levelOrder()) {
		cout << val << " ";
	}
	cout << endl;


	cout << "PreOrder: ";
	for (int val : tree.preOrder()) {
		cout << val << " ";
	}
	cout << endl;


	cout << "InOrder: ";
	for (int val : tree.inOrder()) {
		cout << val << " ";
	}
	cout << endl;


	cout << "PostOrder: ";
	for (int val : tree.postOrder()) {
		cout << val << " ";
	}
	cout << endl;

	return 0;
}