#include <iostream>
#include "Queue.h"
#include "PriorityQueue.cpp"
#include <queue>

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
    PriorityQueue<int> priorityQueue(5);
    priorityQueue.push(5);
    priorityQueue.push(3);
    priorityQueue.push(6);
    priorityQueue.push(1);
    priorityQueue.push(4);

    priorityQueue.print();
    return 0;
}
