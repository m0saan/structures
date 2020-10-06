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


Trie::Trie()  : root { new Node { ' '} } {}


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

void Node::removeChild(char c) const  {
    children->erase(c);
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


bool Trie::contains_iter(const std::string &str) {
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

void Trie::remove(const std::string &str) {
    int i {};
    remove(root ,str, i);
}

void Trie::remove(Node *rootNode, const std::string &str, int i) {

    if (i == str.length()){
        rootNode->isEndOfWord = false;
        return;
    }

    remove(rootNode->getChild(const_cast<char &>(str.at(i))), str, i + 1);

    if (hasNoChildren(rootNode, str, i) && !rootNode->isEndOfWord)
        rootNode->removeChild(const_cast<char &>(str.at(i)));
}


std::vector<std::string> Trie::autoCompletion(const std::string &str) {

    std::vector<std::string> out{};

    autoCompletion(getLastNode(str), str, out);

    return out;
}


void Trie::autoCompletion(Node *rootNode, std::string str, std::vector<std::string> &out) {

    if (rootNode->isEndOfWord)
        out.push_back(str);

    for (auto &child : rootNode->getChildren())
        autoCompletion(child, str + child->value, out);

}


bool Trie::hasNoChildren(const Node *rootNode, const std::string &str,
                         int i) {
    return rootNode->getChild(const_cast<char &>(str.at(i)))->getChildren().empty();
}



Node *Trie::getLastNode(const std::string &str){
    auto current = root;

    for (char c :str ){
        auto child = current->getChild(c);
        if (child == nullptr)
            return nullptr;
        current = child;
    }
    return current;
}

bool Trie::contains_rec(const std::string &str) {
    return contains_rec(root, str);
}

bool Trie::contains_rec(Node *rootNode, const std::string &str) {

    for (char c : str) {
        if (!rootNode->hasChild(c)) return false;
        return contains_rec(rootNode->getChild(c), std::string{str.begin() + 1, str.end()});
    }
    return rootNode->isEndOfWord;
}

std::size_t Trie::countWords() {

    std::size_t counter{};

    countWords(root, counter);

    return counter;
}

void Trie::countWords(Node *rootNode, size_t &counter) {

    if (rootNode->isEndOfWord)
        counter++;

    for (auto &child : rootNode->getChildren())
        countWords(child, counter);
}
