//
// Created by one for all on 15/09/2020.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_LINKED_LIST_H
#define DATA_STRUCTURES_AND_ALGORITHMS_LINKED_LIST_H
#include <cstdio>


template< typename  T>
class LinkedList {
public:
    LinkedList() : m_size { }, first { nullptr }, last { nullptr } {}
    LinkedList(std::initializer_list<T> list) : m_size {} {
        for(auto iterator = list.begin(); iterator != list.end(); iterator++)
            addLast(*iterator);
    }
    void addFirst(T item);
    void addLast(T item);
    void deleteFirst();
    void deleteLast();
    bool contains(T item);
    short indexOf(T item);
    void print() const;
    constexpr std::size_t size() const;
    bool operator==(const LinkedList<T>& other) const;

private:
    class Node {
    public:
        explicit Node(T v) : value{ v }, next { nullptr } {}
        T value;
        Node *next;
    };
private:
    Node *first;
    Node *last;
    std::size_t m_size;
private:
    Node *getNode(T item) const;
    bool isEmpty();
};




#endif //DATA_STRUCTURES_AND_ALGORITHMS_LINKED_LIST_H
