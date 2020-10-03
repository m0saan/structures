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

    void insert_(const T &item);

    void insert(const T &item);

    bool isBalanced();

    bool isPerfect();

private:
    std::size_t mSize;
    AVLNode *root;

private:

    auto insert_(AVLNode *pRoot, const T &item);

    auto insert(AVLNode *pRoot, const T &item);

    bool isLeaf(const AVLNode *pRoot) const;

    int getHeight(const AVLNode *pRoot) const;

    int getBalanceFactor(const AVLNode *pRoot) const;

    bool isLeftHeavy(int balanceFactor) const;

    bool isRightHeavy(int balanceFactor) const;

    auto *balance(AVLNode *pRoot);

    auto *rotateLeft(AVLNode *pRoot) const;

    auto *rotateRight(AVLNode *pRoot) const;

    void resetHeight(AVLNode *pRoot, AVLNode &newRoot) const;
};

#endif //DATA__STRUCTURES_AVLTREE_H
