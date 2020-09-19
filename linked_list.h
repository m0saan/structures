//
// Created by one for all on 15/09/2020.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_LINKED_LIST_H
#define DATA_STRUCTURES_AND_ALGORITHMS_LINKED_LIST_H
#include <iostream>

template <typename LinkedList>
 class LinkedListIterator {
public:
    using ValueType =  typename LinkedList::ValueType;
    using NodeType = typename LinkedList::NodeType;
    using NodePointerType = NodeType*;
    using ReferenceType = ValueType&;
    using PointerType = ValueType*;
public:
    explicit LinkedListIterator(NodePointerType ptr) : m_Ptr {ptr } {}

    LinkedListIterator operator++() {
        m_Ptr = m_Ptr->next;
        return *this;
    }

    LinkedListIterator operator++(int){
        auto LinkedListIterator = *this;
        m_Ptr = m_Ptr->next;
        return *this;
    }

    PointerType operator->() const {
        m_Ptr->value;
    }

    ReferenceType operator*() const{
        return m_Ptr->value;
    }

    bool operator==(const LinkedListIterator& rhs) const{
        return m_Ptr == rhs.m_Ptr;
    }

    bool operator!=(const LinkedListIterator& rhs) const{
        return m_Ptr != rhs.m_Ptr;
    }

private:
    NodePointerType m_Ptr;

};

template< typename  T>
class LinkedList {
public:
    using ValueType = T;
    using Iterator = LinkedListIterator<LinkedList<T>>;

public:
    LinkedList();
    LinkedList(std::initializer_list<T> list);
    void addFirst(T item);
    void addLast(T item);
    void deleteFirst();
    void deleteLast();
    bool contains(T item);
    short indexOf(T item);
    void print() const;
    constexpr std::size_t size() const;
    bool operator==(const LinkedList<T>& other) const;
    bool isEmpty();
    void reverse();
    T getKthFromTheEnd(short k);
    void printMiddle();
    bool hasLoop();

    Iterator begin();
    Iterator end();

private:
    class Node {
    public:
        Node() = default;
        explicit Node(T v) : value{ v }, next { nullptr } {}
        T value;
        Node *next;
    };
private:
    Node *first;
    Node *last;
    std::size_t m_size;
private:
    Node* getNode(T item) const;
    Node* getKthNextNode(short k);

public:
    using NodeType = Node;
};

#endif //DATA_STRUCTURES_AND_ALGORITHMS_LINKED_LIST_H
