//
// Created by moboustt on 10/1/20.
//

#include "AVLTrees.h"


template<typename T>
AVLTrees<T>::AVLTrees() : root {nullptr } {

}

template<typename T>
AVLTrees<T>::~AVLTrees() {
    delete root;
}

template<typename T>
void AVLTrees<T>::insert(const T &item) {
    insert(root, item)
}

template<typename T>
void AVLTrees<T>::insert(AVLTrees::Node *rootNode, const T &item) {
    if (rootNode == nullptr) {
        rootNode = new Node{item};
        return;
    }
    
}
