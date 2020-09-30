//
// Created by moboustt on 9/30/20.
//

#include "tree.h"

/*
 * Inserting a node into into the binary search tree
 */

template<typename T>
void Tree<T>::insert(T item) {
    Node *node = new Node { item };
    if (root == nullptr) root = node;
    else {
        Node *current = root;
        while (true) {
            if (item < current->value) {
                if (current->leftChild == nullptr) {
                    current->leftChild = node;
                    break;
                }
                current = current->leftChild;
            }
            else {
                if (current->rightChild == nullptr) {
                    current->rightChild = node;
                    break;
                }
                current = current->rightChild;
            }
        }
    }
}

/*
 * Finding a value in the binary search tree (if found returns true; otherwise false)
 */
template<typename T>
bool Tree<T>::find(T item) {
    auto current = root;
    while (current != nullptr) {
        if (current->value == item) return true;
        if (item < current->value)
            current = current->leftChild;
        else if (item > current->value)
            current = current->rightChild;
    }
    return false;
}