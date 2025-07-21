#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;

vector<int> topKHeap(vector<int>& nums, int k) {
	if (k <= 0 || nums.empty() || k > nums.size()) {
		throw invalid_argument("Invalid input: k is out of bounds or nums is empty");
	}

	priority_queue<int, vector<int>, greater<int>> heap;

	for (int num : nums) {
		if (heap.size() < k) {
			heap.push(num);
		}
		else if (num > heap.top()) {
			heap.pop();
			heap.push(num);
		}
	}

	vector<int> result;
	while (!heap.empty()) {
		result.push_back(heap.top());
		heap.pop();
	}

	return result;
}