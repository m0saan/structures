//
// Created by moboustt on 10/1/20.
//

#ifndef DATA__STRUCTURES_AVLTREE_H
#define DATA__STRUCTURES_AVLTREE_H

#include "AVLNode.h"

template<typename T>
class AVLTree {
public:
    using AVLNode = AVLNode<AVLTree<T>>;
    using ValueType = T;

public:
    AVLTree();
    ~AVLTree();

public:
    void insert(const T &item);

private:
    AVLNode *root;

private:
    auto insert(AVLNode *pRoot, const T &item);

};


#endif //DATA__STRUCTURES_AVLTREE_H
