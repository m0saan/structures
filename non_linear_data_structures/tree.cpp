//
// Created by moboustt on 9/30/20.
//

#include "tree.h"

void Tree::insert(int item) {
    Node *node = new Node { item };
    if (root == nullptr) root = node;
    else {
        auto current = root;
        while (current != nullptr) {
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
        root = current;
    }
}

bool Tree::find(int item) {
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