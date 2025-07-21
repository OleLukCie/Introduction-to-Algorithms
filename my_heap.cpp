#include <vector>
#include <stdexcept>

using namespace std;

class MaxHeap {
private:
	vector<int> maxHeap;

	int parent(int i) {
		return(i - 1) / 2;
	}

	int left(int i) {
		return 2 * i + 1;
	}

	int right(int i) {
		return 2 * i + 2;
	}

	void siftUp(int i) {
		while (true) {
			int p = parent(i);
			if (p < 0 || maxHeap[i] <= maxHeap[p])
				break;
			swap(maxHeap[i], maxHeap[p]);
			i = p;
		}
	}

	void siftDown(int i) {
		while (true) {
			int l = left(i), r = right(i), ma = i;
			if (l < size() && maxHeap[l] > maxHeap[ma])
				ma = l;
			if (r < size() && maxHeap[r] > maxHeap[ma])
				ma = r;
			if (ma == i)
				break;
			swap(maxHeap[i], maxHeap[ma]);
			i = ma;
		}
	}

public:
	MaxHeap() {}

	MaxHeap(vector<int> nums) {
		maxHeap = nums;
		for (int i = parent(size() - 1); i >= 0; i--) {
			siftDown(i);
		}
	}

	int size() {
		return maxHeap.size();
	}

	bool isEmpty() {
		return size() == 0;
	}

	int peek() {
		return maxHeap[0];
	}

	void push(int val) {
		maxHeap.push_back(val);
		siftUp(size() - 1);
	}

	void pop() {
		if (isEmpty()) {
			throw out_of_range("Empty Heap");
		}
		swap(maxHeap[0], maxHeap[size() - 1]);
		maxHeap.pop_back();
		siftDown(0);
	}
};