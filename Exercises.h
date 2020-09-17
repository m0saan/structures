//
// Created by one for all on 16/09/2020.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_EXERCISES_H
#define DATA_STRUCTURES_AND_ALGORITHMS_EXERCISES_H

#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
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
};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_EXERCISES_H
