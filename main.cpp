#include "vector.hpp"
#include "vector_iterator.h"
#include "linked_list.h"
#include "vector.cpp"
#include "vector_iterator.cpp"
#include "linked_list.cpp"

int main(){
    LinkedList<std::string> list {};
    LinkedList<size_t> numbers { 1, 2, 3, 4 };

    list.addFirst("1");
    list.addFirst("2");
    list.addFirst("3");
    list.addFirst("4");

    std::cout << list.size() << '\n';
    std::cout << numbers.size() << '\n';
    return 0;
}
