//
// Created by moboustt on 9/30/20.
//

#ifndef DATA__STRUCTURES_TREE_H
#define DATA__STRUCTURES_TREE_H

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
private:
    Node *root;
};


#endif //DATA__STRUCTURES_TREE_H
