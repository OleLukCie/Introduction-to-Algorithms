#include <iostream>
#include <deque>

int main() {

    std::deque<int> deque;


    deque.push_back(2);
    deque.push_back(5);
    deque.push_back(4);


    deque.push_front(3);
    deque.push_front(1);


    int front = deque.front();
    int back = deque.back();

    std::cout << "Front element: " << front << std::endl;
    std::cout << "Back element: " << back << std::endl;


    deque.pop_front();
    deque.pop_back();


    int size = deque.size();
    std::cout << "Size after pops: " << size << std::endl;


    bool empty = deque.empty();
    std::cout << "Is deque empty? " << (empty ? "Yes" : "No") << std::endl;


    std::cout << "Elements in deque: ";
    for (int element : deque) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}