//
// Created by one for all on 18/09/2020.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_QUEUEWITHTWOSTACKS_H
#define DATA_STRUCTURES_AND_ALGORITHMS_QUEUEWITHTWOSTACKS_H

#include <iostream>
#include "Stack.h"
#include "Stack.cpp"

template <typename T>
class QueueWithTwoStacks {
public:
    explicit QueueWithTwoStacks(std::size_t capacity) {
        pStack1 = new Stack<T>(capacity);
        pStack2 = new Stack<T>(capacity);
    }
    ~QueueWithTwoStacks() { delete pStack1; delete pStack2; }

    void push(T item){
        pStack1->push(item);
    }

    void pop(){
        if (empty()) throw std::bad_alloc {};
        if (pStack2->empty())
            pushStack1ToStack2();
        pStack2->pop();
    }

    void pushStack1ToStack2() {
        while (!pStack1->empty()){
            pStack2->push(pStack1->top());
            pStack1->pop();
        }
    }

    bool empty() {return pStack2->empty() && pStack1->empty(); }

    T& front() {
        if (pStack2->empty())
            pushStack1ToStack2();
        return pStack2->top();
    }
    //T& back();
    std::size_t size(){ return pStack2->size() + pStack1->size(); }
    void print(){
        if (pStack1->empty()) pStack2->print();
        else pStack1->print();
    }
private:
    Stack<T> *pStack1;
    Stack<T> *pStack2;
};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_QUEUEWITHTWOSTACKS_H
