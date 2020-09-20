#include <iostream>
#include "Queue.h"
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

    return 0;
}
