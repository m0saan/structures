#include "vector.hpp"
#include "vector.cpp"
#include "catch.hpp"

int main(){
    Vector<int> vector;
    vector.insert(10);
    vector.insert(20);
    vector.insert(30);
    vector.insert(40);
    vector.insert(50);
    vector.insert(50);
    vector.insert(50);
    vector.insert(50);
    vector.insert(50);
    vector.insert(50);
    vector.insert(50);
    vector.print();
    vector[0] = 100;
    std::cout << vector[0] << std::endl;
    std::cout << vector[4] << std::endl;

    return 0;
}