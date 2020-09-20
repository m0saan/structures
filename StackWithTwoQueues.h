
#ifndef DATA_STRUCTURES_AND_ALGORITHMS_STACKWITHTWOQUEUES_H
#define DATA_STRUCTURES_AND_ALGORITHMS_STACKWITHTWOQUEUES_H

#include "Queue.h"
#include "Queue.cpp"

template<typename T>
class StackWithTwoQueues{
    public:

        StackWithTwoQueues(std::size_t capacity) : nPushedItems {}, capacity { capacity } {
            queue1 = new Queue<T> { capacity };
            queue2 = new Queue<T> { capacity };
        }

        ~StackWithTwoQueues() { delete queue1; delete queue2; }
        void push(T item);
        void pop();
        void print();
        T& top();
        bool empty();
        std::size_t size();

    private:
        std::size_t nPushedItems;
        std::size_t capacity;
        Queue<T>* queue1;
        Queue<T>* queue2;
    private:
        bool isFull();
        void MoveQueue1ToQueue2(Queue<T>& fromQueue, Queue<T>& toQueue, std::size_t i);

};

#endif
