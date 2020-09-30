//
// Created by one for all on 17/09/2020.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_QUEUE_H
#define DATA_STRUCTURES_AND_ALGORITHMS_QUEUE_H
#include <cstdio>

template<typename T>
class Queue {
public:
    explicit Queue(std::size_t length);
    void push(T item);
    bool empty();
    T& front();
    T& back();
    void pop();
    std::size_t size();
    void print();

private:
    std::size_t capacity;
    std::size_t f;
    std::size_t b;
    std::size_t nPushedItems;
    T* data;
private:
    T* allocate(std::size_t capacity);
};




#endif //DATA_STRUCTURES_AND_ALGORITHMS_QUEUE_H
