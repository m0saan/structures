#define CATCH_CONFIG_MAIN
#include "Exercises.h"
#include "Exercises.cpp"
#include "catch.hpp"


TEST_CASE("TEST"){
    Exercises exercises;

    std::vector<int> arr1{ 3, 1, 4, 1, 5};
    int k1 = 2;
    std::vector<int> arr2{ 1, 2 ,3, 4, 5};
    int k2 = 1;
    std::vector<int> arr3{ 1, 3, 1, 5, 4 };
    int k3 = 0;

    REQUIRE(exercises.countPairsWithDiff(arr1, k1) == 2);
    REQUIRE(exercises.countPairsWithDiff(arr2, k2) == 4);
    REQUIRE(exercises.countPairsWithDiff(arr3, k3) == 1);
}

