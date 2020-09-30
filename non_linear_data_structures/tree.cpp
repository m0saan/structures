//
// Created by moboustt on 9/30/20.
//

#include "tree.h"

/*
 * Constructor and Destructor
 */
template<typename T>
Tree<T>::Tree() : root{nullptr}, mSize{} {}

template<typename T>
Tree<T>::~Tree() { delete root; }


/*
 * Inserting a node into into the binary search tree
 */

template<typename T>
void Tree<T>::insert(T item) {
    Node *node = new Node{item};
    if (root == nullptr) root = node;
    else {
        Node *current = root;
        while (true) {
            if (item < current->value) {
                if (isLeftLeaf(current)) {
                    current->leftChild = node;
                    break;
                }
                current = current->leftChild;
            } else {
                if (isRightLeaf(current)) {
                    current->rightChild = node;
                    break;
                }
                current = current->rightChild;
            }
        }
    }
    mSize++;
}

template<typename T>
bool Tree<T>::isRightLeaf(const Node *current) const { return current->rightChild == nullptr; }

template<typename T>
bool Tree<T>::isLeftLeaf(const Node *current) const { return current->leftChild == nullptr; }

/*
 * Finding a value in the binary search tree (if found returns true; otherwise false)
 */
template<typename T>
bool Tree<T>::find(T item) {
    auto current = root;
    while (current != nullptr) {
        if (current->value == item) return true;
        else if (item < current->value) current = current->leftChild;
        else current = current->rightChild;
    }
    return false;
}

/*
 *  Traversing the tree using Depth-First Approaches
 */

template<typename T>
void Tree<T>::preOrderTraversal() const{
    /*
     * pre-order-traversal [root, left, right]
     */
    preOrderTraversal(root);
}

template<typename T>
void Tree<T>::preOrderTraversal(Node *rootNode) const{
    if (rootNode == nullptr) return;

    std::cout << rootNode->value << '\n';

    preOrderTraversal(rootNode->leftChild);
    preOrderTraversal(rootNode->rightChild);
}

template<typename T>
void Tree<T>::inOrderTraversal() const{
    /*
     * in-order-traversal [left, root, right]
     */
    inOrderTraversal(root);
}

template<typename T>
void Tree<T>::inOrderTraversal(Node *rootNode) const{
    if (rootNode == nullptr) return;

    inOrderTraversal(rootNode->leftChild);

    std::cout << rootNode->value << '\n';

    inOrderTraversal(rootNode->rightChild);
}

template<typename T>
void Tree<T>::postOrderTraversal() const{
    /*
     * post-order-traversal [left, right, root]
     */
    postOrderTraversal(root);
}

template<typename T>
void Tree<T>::postOrderTraversal(Node *rootNode) const{
    if (rootNode == nullptr) return;

    postOrderTraversal(rootNode->leftChild);
    postOrderTraversal(rootNode->rightChild);

    std::cout << rootNode->value << '\n';
}

template<typename T>
void Tree<T>::levelOrderTraversal() const{
    auto current = root;
}

template<typename T>
void Tree<T>::levelOrderTraversal(Node *rootNode) const{

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
size_t Tree<T>::height() const{
    if (isEmpty()) throw std::runtime_error{"Empty tree"};
    return height(root);
}

template<typename T>
size_t Tree<T>::height(Node *rootNode) const{
    if (isLeaf(rootNode)) return 0;

    return 1 + std::max(height(rootNode->leftChild), height(rootNode->rightChild));
}

/*
 * Getting the min and max values in a binary tree.
 */

template<typename T>
T Tree<T>::min() const{
    if (isEmpty()) throw std::runtime_error { "Empty Tree" };
    return min(root);
}

template<typename T>
T Tree<T>::min(Node *rootNode) const{
    if (isLeaf(rootNode)) return rootNode->value;
    return std::min(std::min(min(rootNode->leftChild), min(rootNode->rightChild)), rootNode->value);
}

template<typename T>
T Tree<T>::max() const{
    if (isEmpty()) throw std::runtime_error { "Empty Tree" };
    return max(root);
}

template<typename T>
T Tree<T>::max(Node *rootNode) const{
    if (isLeaf(rootNode)) return rootNode->value;
    return std::max(std::max(max(rootNode->leftChild), max(rootNode->rightChild)), rootNode->value);
}

/*
 * Checking two binary trees for equality
 */

template<typename T>
bool Tree<T>::equals(Tree<T> &other) const {
    return this->mSize == other.mSize && equals(root, other.root);
}

template<typename T>
bool Tree<T>::equals(Node *currentNode, Node *other) const {

    if(currentNode == nullptr && other == nullptr) return true;

    if (currentNode->value != other->value) return false;

    return equals(currentNode->leftChild, other->leftChild) && equals(currentNode->rightChild, other->rightChild);
}

template<typename T>
bool Tree<T>::isEmpty() const {
    return mSize == 0;
}


template<typename T>
bool Tree<T>::isLeaf(const Node *rootNode) const {
    return rootNode->leftChild == nullptr && rootNode->rightChild == nullptr;
}

template<typename T>
bool Tree<T>::operator==(Tree<T> &rhs) const {
    return this->equals(rhs);
}

template<typename T>
bool Tree<T>::operator!=(Tree<T> &rhs) const {
    return !(this->equals(rhs));
}


