#include <iostream>
#include <vector>
#include <stdexcept>

class MyList {
private:
    int* arr;
    int arrCapacity = 10;
    int arrSize = 0;
    int extendRatio = 2;

public:
    MyList() {
        arr = new int[arrCapacity];
    }

    ~MyList() {
        delete[] arr;
    }

    int size()
    {
        return arrSize;
    }

    int capacity() {
        return arrCapacity;
    }

    int get(int index) {
        if (index < 0 || index >= size())
            throw std::out_of_range("IndexOutOfBounds");
        return arr[index];
    }

    void set(int index, int num) {
        if (index < 0 || index >= size())
            throw std::out_of_range("IndexOutOfBounds");
        arr[index] = num;
    }

    void add(int num) {
        if (size() == capacity())
            extendCapacity();
        arr[size()] = num;
        arrSize++;
    }

    void insert(int index, int num) {
        if (index < 0 || index > size())
            throw std::out_of_range("IndexOutOfBounds");
        if (size() == capacity())
            extendCapacity();
        for (int j = size() - 1; j >= index; j--) {
            arr[j + 1] = arr[j];
        }
        arr[index] = num;
        arrSize++;
    }

    int remove(int index) {
        if (index < 0 || index >= size())
            throw std::out_of_range("IndexOutOfBounds");
        int num = arr[index];

        for (int j = index; j < size() - 1; j++) {
            arr[j] = arr[j + 1];
        }

        arrSize--;
        return num;
    }

    void extendCapacity() {
        int newCapacity = capacity() * extendRatio;
        int* tmp = arr;
        arr = new int[newCapacity];

        for (int i = 0; i < size(); i++) {
            arr[i] = tmp[i];
        }

        delete[] tmp;
        arrCapacity = newCapacity;
    }

    std::vector<int> toVector() {
        std::vector<int> vec(size());
        for (int i = 0; i < size(); i++) {
            vec[i] = arr[i];
        }
        return vec;
    }
};


int main() {
    MyList list;

    try {

        list.add(1);
        list.add(2);
        list.add(3);


        std::cout << "Size: " << list.size() << ", Capacity: " << list.capacity() << std::endl;


        std::cout << "Element at index 1: " << list.get(1) << std::endl;


        list.set(1, 5);
        std::cout << "Element at index 1 after set: " << list.get(1) << std::endl;


        list.insert(1, 4);
        std::cout << "Size after insert: " << list.size() << std::endl;


        int removed = list.remove(1);
        std::cout << "Removed element: " << removed << ", Size after remove: " << list.size() << std::endl;


        std::vector<int> vec = list.toVector();
        std::cout << "List as vector: ";
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

    }
    catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}