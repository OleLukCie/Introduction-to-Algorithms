#include <iostream>
#include <vector>
#include <stdexcept>


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


void freeMemoryLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

class LinkedListQueue {
private:
    ListNode* front, * rear;
    int queSize;
public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        queSize = 0;
    }

    ~LinkedListQueue() {
        freeMemoryLinkedList(front);
    }

    int size() {
        return queSize;
    }

    bool isEmpty() {
        return queSize == 0;
    }

    void push(int num) {
        ListNode* node = new ListNode(num);
        if (front == nullptr) {
            front = node;
            rear = node;
        }
        else {
            rear->next = node;
            rear = node;
        }
        queSize++;
    }

    int pop() {
        int num = peek();
        ListNode* tmp = front;
        front = front->next;
        delete tmp;
        queSize--;
        return num;
    }

    int peek() {
        if (size() == 0)
            throw std::out_of_range("Queue Empty");
        return front->val;
    }

    std::vector<int> toVector() {
        ListNode* node = front;
        std::vector<int> res(size());
        for (int i = 0; i < res.size(); i++) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};


int main() {
    LinkedListQueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    std::cout << "Queue size: " << queue.size() << std::endl;
    std::cout << "Queue front: " << queue.peek() << std::endl;

    std::vector<int> vec = queue.toVector();
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Popped: " << queue.pop() << std::endl;
    std::cout << "Queue size after pop: " << queue.size() << std::endl;

    return 0;
}