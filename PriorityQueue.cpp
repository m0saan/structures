//
// Created by one for all on 18/09/2020.
//

#include <iostream>

template<typename T>
class PriorityQueue {
public:
    explicit PriorityQueue(std::size_t capacity) : count{0}, capacity{capacity} {
        data = new T[capacity]{};
    }

    void push(T item) {
        if (isFull()) throw std::bad_alloc{};
        int i;
        for (i = count - 1; i >= 0; i--) {
            if (item < data[i]) data[i + 1] = data[i];
            else break;
        }
        data[++i] = item;
        count++;
    }

    void print() {
        std::cout << "[ ";
        for (int i = 0; i < count; ++i) std::cout << data[i] << ' ';
        std::cout << "]" << std::endl;
    }

    /*
    void pop();
    T& top();
     */
    bool empty() { return count == 0; }

    bool isFull() { return count == capacity; }

    std::size_t size() { return count; }

private:
    std::size_t count;
    std::size_t capacity;
    T *data;
};