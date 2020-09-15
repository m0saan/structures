//
// Created by one for all on 15/09/2020.
//


#include "linked_list.h"
#include <iostream>

template<typename T>
void LinkedList<T>::addFirst(T item) {
    Node *node = getNode(item);
    if (isEmpty()) {
        first = last = node;
        return;
    }
    node->next = first;
    first = node;
    m_size++;
}


template<typename T>
void LinkedList<T>::addLast(T item) {
    auto *node = getNode(item);
    if (isEmpty())
        first = last = node;
    last->next = node;
    last = node;
    m_size++;
}

template<typename T>
void LinkedList<T>::deleteFirst() {
    if !(size) throw std::runtime_error { "No such element " };

    m_size--;

    if (first == last) {
        delete first, last;
        return;
    }
    auto firstRef = first;
    first = first->next;
    firstRef->next = nullptr;
    delete firstRef;
}

template<typename T>
void LinkedList<T>::deleteLast() {
    if (!size) throw std::runtime_error { "No such element" };

    m_size--;

    if (first == last){
        delete first, last;
        return;
    }
    auto current = first;
    while (current->next->next != nullptr)
        current = current->next;
    delete current->next;
    current->next = nullptr;
    last = current;
}

template<typename T>
bool LinkedList<T>::contains(T item) {
    return indexOf(item) >= 0;
}

template<typename T>
short LinkedList<T>::indexOf(T item) {
    char index {};
    auto current = first;
    while (current) {
        if (current->value == item) return short { index };
        current = current->next;
        index++;
    }
    return -1;
}


template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& other) const {
    if (m_size != other.size()) return false;

    auto current = first;
    auto otherCurrent = other.first;
    while (current && otherCurrent){
        if (current->value != otherCurrent->value) return false;
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    return true;
}

template<typename T>
constexpr std::size_t LinkedList<T>::size() const {
    return m_size;
}

template <typename T>
Node<LinkedList<T>> *LinkedList<T>::getNode(T item) const {
    Node *node = new Node(item);
    return node;
}

template<typename T>
void LinkedList<T>::print() const {
    auto current = first;
    printf("[ ");
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    printf("]\n");
}


template<typename T>
bool LinkedList<T>::isEmpty() {
    return first == nullptr;
}
