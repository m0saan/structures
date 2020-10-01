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
    else if (item > pRoot->value) {
        if (pRoot->rightChild == nullptr) {
            pRoot->rightChild = new AVLNode{ item };
            return pRoot;
        }
        insert(pRoot->rightChild, item);
    }

}
