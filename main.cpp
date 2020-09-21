#include <iostream>
#include <string>
#include "Map.h"
#include "Map.cpp"
#include <map>


int main(){
    std::map<int, std::string> map1;
    map1.insert({6, "A"});
    map1.insert({8, "B"});
    map1.insert({11, "C"});
    map1.insert({6, "A+"});
    Map<std::string , std::string> map(10);
    map.put("6", "A");
    map.put("8", "B");
    map.put("11", "C");
    map.put("6", "A+");

    std::cout << map.get("11") << std::endl;
    return 0;
}

