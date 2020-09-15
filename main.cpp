#include "vector.hpp"
#include "vector_iterator.h"
#include "linked_list.h"
#include "vector.cpp"
#include "vector_iterator.cpp"
#include "linked_list.cpp"

int main(){

    LinkedList<int> list{};

    list.addLast(100);
    list.addLast(200);
    list.addLast(300);
    list.print();

/*
    list.deleteFirst();
    list.print();

    list.deleteLast();
    list.print();

    std::cout << list.contains("100") << '\n';
    std::cout << list.contains("1004") << '\n';
    std::cout << list.indexOf("200") << '\n';
    std::cout << list.indexOf("21") << '\n';
     */
    return 0;
}
