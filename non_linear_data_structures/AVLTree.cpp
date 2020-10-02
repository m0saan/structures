//
// Created by moboustt on 10/1/20.
//

#include "AVLTree.h"


template<typename T>
AVLTree<T>::AVLTree() : root {nullptr } {

}

template<typename T>
AVLTree<T>::~AVLTree() {
    delete root;
}

template<typename T>
void AVLTree<T>::insert(const T &item) {
    root = insert(root, item);
}

template<typename T>
auto AVLTree<T>::insert(AVLTree::AVLNode *pRoot, const T &item) {
    if (pRoot == nullptr) {
        pRoot = new AVLNode{ item };
        return pRoot;
    }

    if (item < pRoot->value) {
        if (pRoot->leftChild == nullptr) {
            pRoot->leftChild = new AVLNode{ item };
            return pRoot;
        }
        insert(pRoot->leftChild, item);
    }
    else {
        if (pRoot->rightChild == nullptr) {
            pRoot->rightChild = new AVLNode{ item };
            return pRoot;
        }
        insert(pRoot->rightChild, item);
    }
}

template<typename T>
void AVLTree<T>::insert_(const T &item) {
    root = insert_(root, item);
}

template<typename T>
auto AVLTree<T>::insert_(AVLNode *pRoot, const T &item) {

    if (pRoot == nullptr)
        return new AVLNode { item };

    if (item < pRoot->value)
        pRoot->leftChild = insert_(pRoot->leftChild, item);
    else
        pRoot->rightChild = insert_(pRoot->rightChild, item);

    return pRoot;
}


/*
 * This is a cleaner and easy to understand implementation for the insert method
 */

