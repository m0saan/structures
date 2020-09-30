//
// Created by moboustt on 9/30/20.
//

#ifndef DATA__STRUCTURES_TREE_H
#define DATA__STRUCTURES_TREE_H
#include <iostream>


template<typename TREE>
class Node {

public:
    using T = typename TREE::ValueType;

public:

    explicit Node(T v) : value{ v }, leftChild { nullptr }, rightChild { nullptr } {}
    Node() = default;
    T value;
    Node *leftChild;
    Node *rightChild;
};

template<typename T>
class Tree {
public:
    using ValueType = T;
    using Node = Node<Tree<T>>;
public:

    Tree(): root { nullptr } {};
public:

    void insert(T item);
    bool find(T item);
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();

private:
    Node *root;

private:
    void preOrderTraversal(Node *rootNode);
    void inOrderTraversal(Node *rootNode);
    void postOrderTraversal(Node *rootNode);

};


#endif //DATA__STRUCTURES_TREE_H
