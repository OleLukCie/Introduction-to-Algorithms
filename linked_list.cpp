#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


void insert(ListNode* n0, ListNode* P) {
    ListNode* n1 = n0->next;
    P->next = n1;
    n0->next = P;
}


void remove(ListNode* n0) {
    if (n0->next == nullptr)
        return;
    ListNode* P = n0->next;
    ListNode* n1 = P->next;
    n0->next = n1;
    delete P;
}


ListNode* access(ListNode* head, int index) {
    for (int i = 0; i < index; i++) {
        if (head == nullptr)
            return nullptr;
        head = head->next;
    }
    return head;
}


int find(ListNode* head, int target) {
    int index = 0;
    while (head != nullptr) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

int main() {

    ListNode* n0 = new ListNode(1);
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(5);
    ListNode* n4 = new ListNode(4);


    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;


    ListNode* current = n0;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;


    current = n0;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}