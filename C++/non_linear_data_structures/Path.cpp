//
// Created by moboustt on 10/9/20.
//

#include <vector>
#include <string>
#include <iostream>
#include <istream>
class Path {
public:
    void addNode(const std::string& str){ nodes.push_back(str); }
    void print() {
        std::cout << "[ ";
        for (const auto& node : this->nodes)
            std::cout << node << " ";
        std::cout << "]\n";
    }
private:
    std::vector<std::string> nodes;
};