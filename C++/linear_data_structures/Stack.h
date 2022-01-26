//
// Created by one for all on 17/09/2020.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_STACK_H
#define DATA_STRUCTURES_AND_ALGORITHMS_STACK_H
#include <iostream>

template <typename T>
class Stack {
public:
    Stack();
    explicit Stack(std::size_t capacity);
    ~Stack() { delete data; }

    void push(T item);
    void print();
    void pop();
    T& top();
    bool empty();
    std::size_t size();
    T& min();
    bool operator==(const Stack& other);


private:
    std::size_t count;
    std::size_t capacity;
    T *data;
private:
    T* allocate_and_copy(std::size_t newCapacity, char _copy);
};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_STACK_H
