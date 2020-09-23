#include <iostream>
#include "MapWithLinearProbing.h"
#include <gtest/gtest.h>

int main(){
    MapWithLinearProbing map(5);
    map.put(6, "A");
    map.put(8, "B");
    map.put(11, "C");
    map.print();

    map.remove(6);
    map.print();

    std::cout << map.get(8) << std::endl;
    return 0;
}
