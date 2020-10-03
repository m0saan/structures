/*******************************************************************************
 * DATA STRUCTURES IMPLEMENTATIONS
 *
 *   __                __
 *  |  \  _  |_  _    (_  |_  _      _ |_      _  _  _
 *  |__/ (_| |_ (_|   __) |_ |  |_| (_ |_ |_| |  (- _)
 *
 *
 * Adelson-Velskii and Landis' (AVL) tree
 *
 * Features, being N the number of elements in the tree:
 * 1. Guaranteed search time is O(log(N)).
 * 2. Dynamically updated/balanced tree structure O(N) storage.
 *
 * http://en.wikipedia.org/wiki/AVL_tree
 *
 * @author (moboustta6@gmail.com)
 * @github MoBoustta
 *
 ******************************************************************************/


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
