#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack;

    stack.push(1);
    stack.push(3);
    stack.push(2);
    stack.push(5);
    stack.push(4);

    int top = stack.top();
    stack.pop();

    int size = stack.size();
    bool empty = stack.empty();

    std::cout << "The top element after pop is: " << top << std::endl;
    std::cout << "The size of the stack is: " << size << std::endl;
    std::cout << "Is the stack empty? " << (empty ? "Yes" : "No") << std::endl;

    return 0;
}