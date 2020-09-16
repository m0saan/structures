//
// Created by one for all on 15/09/2020.
//


#include "linked_list.h"
#include <iostream>

template<typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> list) : m_size{}, first{nullptr}, last{nullptr} {
    for (auto iterator = list.begin(); iterator != list.end(); iterator++)
        addLast(*iterator);
}

template<typename T>
LinkedList<T>::LinkedList() : m_size{}, first{nullptr}, last{nullptr} {}


template<typename T>
void LinkedList<T>::addFirst(T item) {
    Node *node = getNode(item);
    if (isEmpty()) first = last = node;
    else {
        node->next = first;
        first = node;
    }
    m_size++;
}

template<typename T>
void LinkedList<T>::addLast(T item) {
    auto *node = getNode(item);
    if (isEmpty())
        first = last = node;
    else {
        last->next = node;
        last = node;
    }
    m_size++;
}

template<typename T>
void LinkedList<T>::deleteFirst() {
    if (!(m_size)) throw std::runtime_error{"No such element "};

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
    if (!m_size) throw std::runtime_error{"No such element"};

    m_size--;

    if (first == last) {
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
    char index{};
    auto current = first;
    while (current) {
        if (current->value == item) return short{index};
        current = current->next;
        index++;
    }
    return -1;
}


template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &other) const {
    if (m_size != other.size()) return false;

    auto current = first;
    auto otherCurrent = other.first;
    while (current && otherCurrent) {
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

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::getNode(T item) const {
    Node *node = new Node(item);
    return node;
}

template<typename T>
void LinkedList<T>::reverse() {
    if (isEmpty() || m_size == 1) return;

    auto second = first->next;
    auto current = first;
    while (second != nullptr) {
        auto tmp = *second;
        second->next = current;
        current = second;
        second = tmp.next;
    }

    last = first;
    last->next = nullptr;
    first = current;
}

template<typename T>
T LinkedList<T>::getKthFromTheEnd(short k) {
    auto previous = first;
    while (k-- > 1)
        previous = previous->next;
    auto next = previous;
    previous = first;
    while (next){
        next = next->next;
        previous = previous->next;
    }
    return previous->value;
}
