

#include "AVLTree.h"
#include "AVLTree.cpp"
#include "AVLNode.cpp"
#include <string>


/*
template <typename T>
std::ostream &operator<<(std::ostream& o, std::vector<T>& v){
    std::cout << "[ ";
    for (auto& item : v)
        o << item << ' ';
    std::cout << ']' << std::endl;
    return o;
}
*/


int main() {
    AVLTree<int> bst;
    bst.insert(7);
    bst.insert(4);
    bst.insert(6);
    bst.insert(1);
    bst.insert(8);
    bst.insert(10);
    bst.insert(9);

    std::cout << std::boolalpha << bst.isPerfect() << std::endl;
}