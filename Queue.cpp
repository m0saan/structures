//
// Created by one for all on 17/09/2020.
//

#include "Queue.h"
#include <exception>
#include <iostream>
template<typename T>
T *Queue<T>::allocate(std::size_t length) {
    return new T[capacity]{};
}

template<typename T>
Queue<T>::Queue(std::size_t capacity) : capacity { capacity }, f {}, b{}, nPushedItems{} {
    data = allocate(capacity);
}

template<typename T>
void Queue<T>::push(T item) {
    if (nPushedItems >= capacity) throw std::bad_alloc{};
    data[b] = item;
    b = (b + 1) % capacity;
    nPushedItems++;
}

template<typename T>
bool Queue<T>::empty() {
    return nPushedItems == 0;
}

template<typename T>
T &Queue<T>::front() {
    return data[f];
}

template<typename T>
T &Queue<T>::back() {
    return data[nPushedItems];
}

template<typename T>
void Queue<T>::pop() {
    if(empty()) throw std::bad_alloc{};
    data[f] = 0;
    f = (f + 1) % capacity;
    nPushedItems--;
}

template<typename T>
std::size_t Queue<T>::size() {
    return nPushedItems;
}

template<typename T>
void Queue<T>::print() {
    std::cout << "[ ";
    for (int i = 0; i < capacity; ++i)
        std::cout << data[i] << " ";
    std::cout << "]" << std::endl;
}
