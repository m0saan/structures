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

};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_EXERCISES_H
