//
// Created by moboustt on 9/30/20.
//

#ifndef DATA__STRUCTURES_TREE_H
#define DATA__STRUCTURES_TREE_H

#include <iostream>
#include <limits>


template<typename TREE>
class Node {

public:
    using T = typename TREE::ValueType;

public:

    explicit Node(T v) : value{v}, leftChild{nullptr}, rightChild{nullptr} {}

    Node() = default;

    T value;
    Node *leftChild;
    Node *rightChild;
};

template<typename T>
class Tree {
public:
    using ValueType = T;
    using Node = Node<Tree<T>>;
public:

    Tree();

    ~Tree();

public:

    /*
     * Inserting and Searching in the Tree
     */
    void insert(T item);

    bool find(T item);

    /*
     * Tree Traversal
     */

    void preOrderTraversal() const;

    void inOrderTraversal() const;

    void postOrderTraversal() const;

    void levelOrderTraversal() const;

    size_t height() const;

    T min() const;

    T max() const;

    bool equals(Tree<T>& other) const;

    bool isEmpty() const;

    bool isBinarySearchTree();

    bool operator==(Tree<T>& rhs) const;

    bool operator!=(Tree<T>& rhs) const;

    void nodeAtKDistance(int K);

    void swap(){
        auto tmp = root->leftChild;
        root->leftChild = root->rightChild;
        root->rightChild = tmp;
    }

private:
    Node *root;
    std::size_t mSize;

private:
    void preOrderTraversal(Node *rootNode) const;

    void inOrderTraversal(Node *rootNode) const;

    void postOrderTraversal(Node *rootNode) const;

    void levelOrderTraversal(Node *rootNode) const;

    size_t height(Node *rootNode) const;

    T min(Node *rootNode) const;

    T max(Node *rootNode) const;

    bool equals(Node *currentNode, Node *other) const;

    bool isBinarySearchTree(Node *rootNode, int min, int max);

    void nodeAtKDistance(Node *rootNode, int K);

    bool isLeaf(const Node *rootNode) const;

    bool isLeftLeaf(const Node *current) const;

    bool isRightLeaf(const Node *current) const;
};


#endif //DATA__STRUCTURES_TREE_H
