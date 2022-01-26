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


#ifndef DATA__STRUCTURES_AVLNODE_H
#define DATA__STRUCTURES_AVLNODE_H

#include <iostream>

template<typename AVLTREE>
class AVLNode {
public:
    using T = typename AVLTREE::ValueType;
public:
    AVLNode() = default;

    explicit AVLNode(T v);

    T value;
    std::size_t height;
    AVLNode *leftChild;
    AVLNode *rightChild;
};


#endif //DATA__STRUCTURES_AVLNODE_H
