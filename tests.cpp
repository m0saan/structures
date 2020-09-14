#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vector.hpp"
#include "vector.cpp"
#include <string>

TEST_CASE("Testing Vector Class") {

    Vector<int> numbers(3);
    SECTION("Testing Insertions using insert method and operator[]"){
        numbers.insert(1);
        numbers.insert(2);
        numbers.insert(3);

        REQUIRE(numbers[0] == 1);
        REQUIRE(numbers[2] == 3);

        numbers.insert(20);
        numbers.insert(30);
        REQUIRE(numbers[3] == 20);
        REQUIRE(numbers[4] == 30);

        numbers[0] = 100;
        REQUIRE(numbers[0] == 100);
        REQUIRE_THROWS(numbers[10]);
    }

    SECTION("Testing removeAt() / size() / isEmpty() methods "){
        numbers.insert(10);
        numbers.insert(20);
        numbers.insert(30);

        numbers.removeAt(0);
        REQUIRE(numbers[0] == 20);
        numbers.removeAt(1);
        REQUIRE(numbers.size() == 1);

        numbers.removeAt(0);
        REQUIRE(numbers.isEmpty());
    }

    SECTION("Testing some edge cases"){
        Vector<std::string> words;
        words.insert("no");
        words.insert("dreamer");
        words.insert("is");
        words.insert("too");
        words.insert("small");

        REQUIRE_THROWS(words.removeAt(100));
        REQUIRE_THROWS_AS(words[-1], std::runtime_error);
        REQUIRE(numbers.indexOf(-10) == -1);
        REQUIRE(numbers.indexOf(10) == -1);

    }
}

