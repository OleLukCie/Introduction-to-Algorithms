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
    std::cout << "队首元素是: " << front << std::endl;

    queue.pop();

    int size = queue.size();
    std::cout << "移除队首元素后，队列的大小是: " << size << std::endl;

    bool empty = queue.empty();
    std::cout << "队列是否为空? " << (empty ? "是" : "否") << std::endl;

    return 0;
}