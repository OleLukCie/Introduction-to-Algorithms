#include <iostream>
#include <vector>
#include <stdexcept>

class ArrayStack {
private:
    std::vector<int> stack;
public:
    int size() {
        return stack.size();
    }

    bool isEmpty() {
        return stack.size() == 0;
    }

    void push(int num) {
        stack.push_back(num);
    }

    int pop() {
        int num = top();
        stack.pop_back();
        return num;
    }

    int top() {
        if (isEmpty())
            throw std::out_of_range("Stack Empty");
        return stack.back();
    }

    std::vector<int> toVector() {
        return stack;
    }
};

int main() {
    ArrayStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Stack size: " << stack.size() << std::endl;

    try {
        std::cout << "Top element: " << stack.top() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "Popped element: " << stack.pop() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Stack size after pop: " << stack.size() << std::endl;

    std::vector<int> vec = stack.toVector();
    std::cout << "Stack elements: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}