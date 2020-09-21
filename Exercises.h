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
#include <set>
#include <map>

class Exercises {
public:
    static void reverse(std::string &input);

    static void queueReverse(std::queue<int> &queue);

    static bool isBalanced(std::string &str);

    static std::queue<int> queueReversKElements(std::queue<int> &queue, std::size_t k);

    static char findFirstNonRepeatedCharacter(const std::string &string);

    static char findFirstRepeatedCharacter(const std::string &string);

    template<size_t N>
    int mostFrequent(int (&input)[N]);

    template<size_t N>
    int countPairsWithDiff(int (&input)[N], int k);

    template<size_t N>
    int* twoSum(int (&input)[N], int target);
};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_EXERCISES_H
