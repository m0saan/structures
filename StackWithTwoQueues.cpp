#include "StackWithTwoQueues.h"

template<typename T>
void StackWithTwoQueues<T>::push(T item){
    if (isFull()) throw std::bad_alloc{};
    queue1->push(item);
    nPushedItems++;
}

template<typename T>
void StackWithTwoQueues<T>::pop() {
    MoveQueue1ToQueue2(*queue1, *queue1, nPushedItems);
    queue1->pop();
    MoveQueue1ToQueue2(*queue2, *queue1, nPushedItems + 1);
    nPushedItems--;
}

template<typename T>
T& StackWithTwoQueues<T>::top() { return queue1->back(); }

template<typename T>
bool StackWithTwoQueues<T>::isFull() { return nPushedItems == capacity; }

template<typename T>
bool StackWithTwoQueues<T>::empty() {return !nPushedItems; }

template<typename T>
std::size_t StackWithTwoQueues<T>::size() { return nPushedItems; }

template<typename T>
void StackWithTwoQueues<T>::MoveQueue1ToQueue2(Queue<T>& fromQueue, Queue<T>& toQueue, std::size_t i){
    while(i--) {
        toQueue.push(fromQueue.front());
        fromQueue.pop();
    }
}
// Q1 = [ 4]
// Q2 = [ 1 2 3 ]
