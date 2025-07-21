#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;


struct Node{
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
};

int func() {

	return 0;
}

int algorithm(int n) {
	const int a = 0;
	int b = 0;
	Node* node = new Node(0);
	int c = func();
	return a + b + c;
}

void Algorithm(int n) {
	int a = 0;
	vector<int> b(10000);
	if (n > 10)
		vector<int> nums(n);
}

void loop(int n)
{
	for (int i = 0; i < n; i++) {
		func();
	}
}

void recur(int n) {
	if (n == 1) return;
	return recur(n - 1);
}


class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int val) : data(val), next(nullptr) {}
};

void constant(int n)
{
	const int a = 0;
	int b = 0;
	vector<int> nums(10000);
	ListNode node(0);

	for (int i = 0; i < n; i++)
	{
		func();
	}
}

void linear(int n) {
	vector<int> nums(n);
	vector<ListNode> nodes;
	for (int i = 0; i < n; i++) {
		nodes.push_back(ListNode(i));
	}

	unordered_map<int, string> map;
	for (int i = 0; i < n; i++)
	{
		map[i] = to_string(i);
	}
}

void linearRecur(int n)
{
	cout << "Recursion n = " << n << endl;
	if (n == 1)
		return;
	linearRecur(n - 1);
}

void quadratic(int n) {
	vector<vector<int>> numMatrix;
	for (int i = 0; i < n; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < n; j++) {
			tmp.push_back(0);
		}
		numMatrix.push_back(tmp);
	}
}

int quardraticRecur(int n)
{
	if (n <= 0)
		return 0;
	vector<int> nums(n);
	cout << "Recursion n = " << n << " Size of nums = " << nums.size() << endl;
	return quardraticRecur(n - 1);
}


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(int n)
{
	if (n == 0)
		return nullptr;
	TreeNode* root = new TreeNode(0);
	root->left = buildTree(n - 1);
	root->right = buildTree(n - 1);
	return root;
}