//
// Created by moboustt on 9/30/20.
//

#ifndef DATA__STRUCTURES_TREE_H
#define DATA__STRUCTURES_TREE_H

class Node {
public:
    explicit Node(int v) : value{ v }, leftChild { nullptr }, rightChild { nullptr } {}
    Node() = default;
    int value;
    Node *leftChild;
    Node *rightChild;
};

class Tree {
public:

    Tree(): root { nullptr } {};
public:

    void insert(int item);
    bool find(int item);
private:
    Node *root;
};


#endif //DATA__STRUCTURES_TREE_H
