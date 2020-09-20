//
// Created by one for all on 16/09/2020.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_EXERCISES_H
#define DATA_STRUCTURES_AND_ALGORITHMS_EXERCISES_H

#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
#include <stack>
#include <queue>
class Exercises {
public:
    static void reverse(std::string& input){
        std::stack<char> stackOfChars;
        for (char & i : input)
            stackOfChars.push(i);
        std::size_t i {};
        while (!stackOfChars.empty()) {
            input[i++] = stackOfChars.top();
            stackOfChars.pop();
        }
    }

    static void queueReverse(std::queue<int>& queue){
        std::stack<int> stackOfInts;
        while(!queue.empty()) {
            stackOfInts.push(queue.front());
            queue.pop();
        }
        while (!stackOfInts.empty()) {
            queue.push(stackOfInts.top());
            stackOfInts.pop();
        }
    }

    static bool isBalanced(std::string& str){
        std::string closingSymbola(")}>]");
        std::stack<char> stack;
        for(char& c : str){
            if (c == '(' || c == '[' || c == '<' || c == '(') stack.push(c);
            else if (str.find(c) != std::string::npos){
                auto current = stack.top();
                stack.pop();
                if (current - c == 1 || current - c == 2) continue;
                else return false;
            }
        }
        return true;
    }

    static std::queue<int> queueReversKElements(std::queue<int>& queue, std::size_t k){
        if (queue.empty() || k > queue.size() || k < 0) throw std::runtime_error{ "Invalid operation" };
        std::stack<int> stack;
        std::queue<int> outQueue;
        int i = k;
        while (i--) {
            stack.push(queue.front());
            queue.pop();
        }
        while (!stack.empty()){
            outQueue.push(stack.top());
            stack.pop();
        }
        while (!queue.empty()){
            outQueue.push(queue.front());
            queue.pop();
        }
        return outQueue;
    }

};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_EXERCISES_H
