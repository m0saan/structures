//
// Created by one for all on 20/09/2020.
//

#include "QueueWithLinkedList.h"


template<typename T>
void QueueWithLinkedList<T>::push(T item) {
    list.push_back(item);
}

template<typename T>
bool QueueWithLinkedList<T>::empty() {
    return list.empty();
}

template<typename T>
T &QueueWithLinkedList<T>::front() {
    return list.front();
}

template<typename T>
T &QueueWithLinkedList<T>::back() {
    return list.back();
}

template<typename T>
void QueueWithLinkedList<T>::pop() {
    list.pop_front();
}

template<typename T>
std::size_t QueueWithLinkedList<T>::size() {
    return list.size();
}


