#include <iostream>
#include <queue>

int main() {

    std::queue<int> queue;

    queue.push(1);
    queue.push(3);
    queue.push(2);
    queue.push(5);
    queue.push(4);

    int front = queue.front();
    std::cout << "����Ԫ����: " << front << std::endl;

    queue.pop();

    int size = queue.size();
    std::cout << "�Ƴ�����Ԫ�غ󣬶��еĴ�С��: " << size << std::endl;

    bool empty = queue.empty();
    std::cout << "�����Ƿ�Ϊ��? " << (empty ? "��" : "��") << std::endl;

    return 0;
}