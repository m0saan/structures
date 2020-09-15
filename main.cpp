#include "vector.hpp"
#include "vector.cpp"
#include "vector_iterator.h"
#include "vector_iterator.cpp"
#include "catch.hpp"

int main(){
    Vector<int> nums { 1, 2, 3, 4, 5 };

    std::cout << "Not using Iterators!\n";
    for (int i = 0; i < nums.size(); ++i)
        std::cout << nums[i] << " ";
    std::cout << std::endl;

    std::cout << "using for range-based loops\n";
    for (auto num : nums)
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "Using Iterators!\n";
    for(Vector<int>::Iterator it = nums.begin(); it != nums.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}