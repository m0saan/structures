//
// Created by one for all on 20/09/2020.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_QUEUEWITHLINKEDLIST_H
#define DATA_STRUCTURES_AND_ALGORITHMS_QUEUEWITHLINKEDLIST_H

#include <list>

template <typename T>
class QueueWithLinkedList {
public:
    QueueWithLinkedList(){ }

    void push(T item);
    bool empty();
    T& front();
    T& back();
    void pop();
    std::size_t size();
private:
    std::list<T> list;
};



#endif //DATA_STRUCTURES_AND_ALGORITHMS_QUEUEWITHLINKEDLIST_H
