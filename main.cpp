#include <iostream>
#include "StackWithTwoQueues.h"
#include "StackWithTwoQueues.cpp"

std::ostream& operator<<(std::ostream& o, StackWithTwoQueues<int> queue){
    std::cout << "[ ";
    while (!queue.empty()) {
        o << queue.top() << ' ';
        queue.pop();
    }
    std::cout << "]\n";
    return o;
}


int main(){
    Queue<int> queue(5);
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);

    queue.print();
    std::cout << "front: " << queue.front() << std::endl;
    std::cout << "back: " << queue.back() << std::endl;

    queue.pop();
    std::cout << "front: " << queue.front() << std::endl;
    std::cout << "back: " << queue.back() << std::endl;
/*
    StackWithTwoQueues<int> stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    //std::cout<< stack.top() << std::endl;
    stack.pop();
    std::cout<< stack.top() << std::endl;
    stack.pop();
    stack.pop();
    stack.push(100);
    std::cout<< stack.top() << std::endl;
    stack.pop();
    std::cout<< stack.top() << std::endl;
*/
    return 0;
}

// [ 10, 20]