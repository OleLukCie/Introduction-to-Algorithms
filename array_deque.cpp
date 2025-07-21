#include <iostream>
#include <vector>
using namespace std;

class ArrayDeque {
private:
    vector<int> nums;
    int front;
    int queSize;

public:
    ArrayDeque(int capacity) {
        nums.resize(capacity);
        front = queSize = 0;
    }


    int capacity() {
        return nums.size();
    }

    int size() {
        return queSize;
    }

    bool isEmpty() {
        return queSize == 0;
    }

    int index(int i) {
        return (i + capacity()) % capacity();
    }

    void pushFirst(int num) {
        if (queSize == capacity()) {
            cout << "Deque Full" << endl;
            return;
        }
        front = index(front - 1);
        nums[front] = num;
        queSize++;
    }

    void pushLast(int num) {
        if (queSize == capacity()) {
            cout << "Deque Full" << endl;
            return;
        }
        int rear = index(front + queSize);
        nums[rear] = num;
        queSize++;
    }

    int popFirst() {
        int num = peekFirst();
        front = index(front + 1);
        queSize--;
        return num;
    }

    int popLast() {
        int num = peekLast();
        queSize--;
        return num;
    }

    int peekFirst() {
        if (isEmpty())
            throw out_of_range("Deque Empty");
        return nums[front];
    }

    int peekLast() {
        if (isEmpty())
            throw out_of_range("Deque Empty");
        int last = index(front + queSize - 1);
        return nums[last];
    }

    vector<int> toVector() {
        vector<int> res(queSize);
        for (int i = 0, j = front; i < queSize; i++, j++) {
            res[i] = nums[index(j)];
        }
        return res;
    }
};