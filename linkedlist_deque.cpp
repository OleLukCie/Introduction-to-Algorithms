#include <iostream>
#include <vector>
#include <stdexcept>

struct DoublyListNode {
    int val;
    DoublyListNode* next;
    DoublyListNode* prev;
    DoublyListNode(int val) : val(val), prev(nullptr), next(nullptr) {
    }
};

class LinkedListDeque {
private:
    DoublyListNode* front, * rear;
    int queSize = 0;
public:
    LinkedListDeque() : front(nullptr), rear(nullptr) {
    }

    ~LinkedListDeque() {
        DoublyListNode* pre, * cur = front;
        while (cur != nullptr) {
            pre = cur;
            cur = cur->next;
            delete pre;
        }
    }

    int size() {
        return queSize;
    }

    bool isEmpty() {
        return size() == 0;
    }

    void push(int num, bool isFront) {
        DoublyListNode* node = new DoublyListNode(num);
        if (isEmpty())
            front = rear = node;
        else if (isFront) {
            front->prev = node;
            node->next = front;
            front = node;
        }
        else {
            rear->next = node;
            node->prev = rear;
            rear = node;
        }
        queSize++;
    }

    void pushFirst(int num) {
        push(num, true);
    }

    void pushLast(int num) {
        push(num, false);
    }

    int pop(bool isFront) {
        if (isEmpty())
            throw std::out_of_range("Queue Empty");
        int val;
        if (isFront) {
            val = front->val;
            DoublyListNode* fNext = front->next;
            if (fNext != nullptr) {
                fNext->prev = nullptr;
            }
            delete front;
            front = fNext;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
        else {
            val = rear->val;
            DoublyListNode* rPrev = rear->prev;
            if (rPrev != nullptr) {
                rPrev->next = nullptr;
            }
            delete rear;
            rear = rPrev;
            if (rear == nullptr) {
                front = nullptr;
            }
        }
        queSize--;
        return val;
    }

    int popFirst() {
        return pop(true);
    }

    int popLast() {
        return pop(false);
    }

    int peekFirst() {
        if (isEmpty())
            throw std::out_of_range("Deque Empty");
        return front->val;
    }

    int peekLast() {
        if (isEmpty())
            throw std::out_of_range("Deque Empty");
        return rear->val;
    }

    std::vector<int> toVector() {
        DoublyListNode* node = front;
        std::vector<int> res(size());
        for (int i = 0; i < res.size(); i++) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};

int main() {
    LinkedListDeque deque;
    deque.pushFirst(1);
    deque.pushLast(2);
    deque.pushFirst(3);

    std::vector<int> vec = deque.toVector();
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Pop first: " << deque.popFirst() << std::endl;
    std::cout << "Pop last: " << deque.popLast() << std::endl;

    return 0;
}