//
// Created by moboustt on 10/1/20.
//

#ifndef DATA__STRUCTURES_AVLTREES_H
#define DATA__STRUCTURES_AVLTREES_H

#include "AVLNode.h"

template<typename T>
class AVLTrees {
public:
    using Node = AVLNode<AVLTrees<T>>;
    using ValueType = T;

public:
    AVLTrees();
    ~AVLTrees();

public:
    void insert(const T &item);

private:
    Node *root;

private:
    void insert(Node *rootNode, const T &item);

};


#endif //DATA__STRUCTURES_AVLTREES_H
