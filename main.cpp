#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
#include "PriorityQueue.cpp"
#include "QueueWithLinkedList.h"
#include "QueueWithLinkedList.cpp"
#include <queue>
#include "Exercises.h"
/*
std::ostream& operator<<(std::ostream& o, std::queue<int> queue){
    std::cout << "[ ";
    while (!queue.empty()) {
        o << queue.front() << ' ';
        queue.pop();
    }
    std::cout << "]\n";
    return o;
}
std::ostream& operator<<(std::ostream& o, Queue<int> queue){
    std::cout << "[ ";
    while (!queue.empty()) {
        o << queue.front() << ' ';
        queue.pop();
    }
    std::cout << "]\n";
    return o;
}
 */

int main(){
    QueueWithLinkedList<int> queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);

    std::cout<< queue.front() << std::endl;
    std::cout<< queue.back() << std::endl;
    queue.pop();
    std::cout<< queue.front() << std::endl;
    queue.pop();
    queue.push(100);
    std::cout<< queue.front() << std::endl;
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    std::cout << queue.front() << std::endl;
    std::cout << queue.back() << std::endl;
    std::cout << "**************************************" << std::endl;

    Queue<int> nqueue(5);
    nqueue.push(10);
    nqueue.push(20);
    nqueue.push(30);
    nqueue.push(40);
    nqueue.push(50);

    std::cout<< nqueue.front() << std::endl;
    std::cout<< nqueue.back() << std::endl;
    nqueue.pop();
    std::cout<< nqueue.front() << std::endl;
    nqueue.pop();
    nqueue.push(100);

    std::cout<< nqueue.front() << std::endl;
    nqueue.pop();
    nqueue.pop();
    nqueue.pop();
    nqueue.pop();
    std::cout<< nqueue.front() << std::endl;
    std::cout<< nqueue.back() << std::endl;

    return 0;
}
