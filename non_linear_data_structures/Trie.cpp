/*******************************************************************************
 * DATA STRUCTURES IMPLEMENTATIONS
 *
 *   __                __
 *  |  \  _  |_  _    (_  |_  _      _ |_      _  _  _
 *  |__/ (_| |_ (_|   __) |_ |  |_| (_ |_ |_| |  (- _)
 *
 *
 * Trie
 *
 * -> Tries Applications:
 *  1. Building auto-completion
 *
 * -> Features:
 * being 'L' the length of the word we want to insert or delete
 * 1. Look Up O(L)
 * 2. Delete O(L)
 * 3. Insert O(L)
 *
 * https://en.wikipedia.org/wiki/Trie
 *
 * Created by moboustt on 10/4/20.
 * @author (moboustta6@gmail.com)
 * @github MoBoustta
 ******************************************************************************/

#include "Trie.h"

#include <iostream>


Trie::Trie()  : root { new Node { '\0'} } {}


Trie::~Trie() {
    delete root;
}


Node::Node(char v) : value {v}, isEndOfWord{ false } {
    children = new std::map<char, Node*> {};
}


bool Node::hasChild(char &c) const {
    return children->count(c);
}


void Node::addChild(char &c) const {
    children->insert({c, new Node{c }});
}


Node* Node::getChild(char &c) const {
    return children->at(c);
}

std::vector<Node *> Node::getChildren() const {
    std::vector<Node*> values;

    for (auto & itr : *children)
        values.push_back(itr.second);

    return values;
}


void Trie::insert(const std::string &str) {


    auto current = root;
    for (char c : str){
        auto index = c - 'a';
        if (!current->hasChild(c))
            current->addChild(c);
        current = current->getChild(c);
    }
    current->isEndOfWord = true;
}


bool Trie::contains(const std::string &str) {
    auto current = root;

    for (char c : str) {
        if (current->hasChild(c))
            current = current->getChild(c);
        else return false;
    }

    return current->isEndOfWord;
}



void Trie::preOrderTraversal() const  {
    preOrderTraversal(root);
}


void Trie::preOrderTraversal(Node *node) const {

    std::cout << node->value << std::endl;

    for (auto & child : node->getChildren())
        preOrderTraversal(child);
}

void Trie::postOrderTraversal() const {
    postOrderTraversal(root);
}



void Trie::postOrderTraversal(Node *node) const {

    for (auto & child : node->getChildren())
        postOrderTraversal(child);

    std::cout << node->value << std::endl;
}