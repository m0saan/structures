#include "vector.hpp"
#include "vector_iterator.h"
#include "linked_list.h"
#include "vector.cpp"
#include "vector_iterator.cpp"
#include "linked_list.cpp"

int main(){
    LinkedList<size_t> numbers { 1, 2, 3, 4 };

    numbers.print();
    numbers.reverse();
    numbers.print();

    return 0;
}
