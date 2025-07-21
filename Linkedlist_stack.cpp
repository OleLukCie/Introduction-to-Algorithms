#include <iostream>
#include <vector>
#include <stdexcept>

class ListNode {
public:
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

class LinkedListStack {
private:
    ListNode* stackTop;
    int stkSize;
public:
    LinkedListStack() {
        stackTop = nullptr;
        stkSize = 0;
    }

    ~LinkedListStack() {
        freeMemoryLinkedList(stackTop);
    }

    int size() {
        return stkSize;
    }

    bool isEmpty() {
        return size() == 0;
    }

    void push(int num) {
        ListNode* node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stkSize++;
    }

    int pop() {
        int num = top();
        ListNode* tmp = stackTop;
        stackTop = stackTop->next;
        delete tmp;
        stkSize--;
        return num;
    }

    int top() {
        if (isEmpty())
            throw std::out_of_range("Stack Empty");
        return stackTop->val;
    }

    std::vector<int> toVector() {
        ListNode* node = stackTop;
        std::vector<int> res(size());
        for (int i = res.size() - 1; i >= 0; i--)
        {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};


int main() {
    LinkedListStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Stack size: " << stack.size() << std::endl;

    std::cout << "Top element: " << stack.top() << std::endl;

    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Stack size after pop: " << stack.size() << std::endl;

    std::vector<int> vec = stack.toVector();
    std::cout << "Stack elements: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}