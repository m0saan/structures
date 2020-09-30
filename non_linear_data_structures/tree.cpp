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

/*
 *  Traversing the tree using Depth-First Approaches
 */

template<typename T>
void Tree<T>::preOrderTraversal() {
    /*
     * pre-order-traversal [root, left, right]
     */
    preOrderTraversal(root);
}

template<typename T>
void Tree<T>::preOrderTraversal(Node *rootNode) {
    if (rootNode == nullptr) return;

    std::cout << rootNode->value << '\n';

    preOrderTraversal(rootNode->leftChild);
    preOrderTraversal(rootNode->rightChild);
}

template<typename T>
void Tree<T>::inOrderTraversal() {
    /*
     * in-order-traversal [left, root, right]
     */
    inOrderTraversal(root);
}

template<typename T>
void Tree<T>::inOrderTraversal(Node *rootNode) {
    if (rootNode == nullptr) return;

    inOrderTraversal(rootNode->leftChild);

    std::cout << rootNode->value << '\n';

    inOrderTraversal(rootNode->rightChild);
}

template<typename T>
void Tree<T>::postOrderTraversal() {
    /*
     * post-order-traversal [left, right, root]
     */
    postOrderTraversal(root);
}

template<typename T>
void Tree<T>::postOrderTraversal(Node *rootNode) {
    if (rootNode == nullptr) return;

    postOrderTraversal(rootNode->leftChild);
    postOrderTraversal(rootNode->rightChild);

    std::cout << rootNode->value << '\n';
}

template<typename T>
void Tree<T>::levelOrderTraversal() {
    auto current = root;
}

template<typename T>
void Tree<T>::levelOrderTraversal(Node *rootNode) {

    std::cout << rootNode->value << '\n';

    levelOrderTraversal(rootNode->leftChild);
    std::cout << rootNode->value << '\n';

    levelOrderTraversal(rootNode->rightChild);
    std::cout << rootNode->value << '\n';


}

/*
 * Using post-order-traversal to get the height the tree.
 * Using the formula H = 1 + max(Height(Left), Height(Right)).
 */

template<typename T>
size_t Tree<T>::hieght() {
    if (root == nullptr) throw std::runtime_error{ "Empty tree" };
    return height(root);
}

template<typename T>
size_t Tree<T>::height(Node *rootNode) {
    if (rootNode->leftChild == nullptr && rootNode->rightChild == nullptr) return 0;

    return 1 + std::max( height(rootNode->leftChild), height(rootNode->rightChild));
}


