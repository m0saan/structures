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

    bool contains(T item) const;

    /*
     * Tree Traversal
     */

    void preOrderTraversal() const;

    void inOrderTraversal() const;

    void postOrderTraversal() const;

    void levelOrderTraversal() const;

    /*
     * Get the height if a binary tree
     */

    size_t height() const;

    /*
     * Min and Max of a binary tree
     */
    T min() const;

    T max() const;

    /*
     * Checking two binary trees for equality or inequality
     */

    bool equals(Tree<T>& other) const;

    bool operator==(Tree<T>& rhs) const;

    bool operator!=(Tree<T>& rhs) const;



    bool isEmpty() const;

    bool isBinarySearchTree();

    void nodeAtKDistance(int K) const;

    size_t countLeaves() const;

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

    size_t height(Node *rootNode) const;

    T min(Node *rootNode) const;

    T max(Node *rootNode) const;

    bool equals(Node *currentNode, Node *other) const;

    bool isBinarySearchTree(Node *rootNode, int min, int max);

    void nodeAtKDistance(Node *rootNode, int K) const;

    bool isLeaf(const Node *rootNode) const;

    bool isLeftLeaf(const Node *current) const;

    bool isRightLeaf(const Node *current) const;

    void countLeaves(Node *rootNode, size_t &counter) const;

    bool contains(Node *rootNode, T item) const;


};


#endif //DATA__STRUCTURES_TREE_H
