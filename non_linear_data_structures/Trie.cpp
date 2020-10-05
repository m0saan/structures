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
 *  2.
 *  3.
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

void Trie::insert(std::basic_string<char, std::char_traits<char>, std::allocator<char>> str) {

    std::transform(str.begin(), str.end(), str.begin(), tolower);

    auto current = root;
    for (char& c : str){
        auto index = c - 'a';
        if (current->hasChild(c)) {
            current->addChild(c);
            current = current->getChild(c);
        }
    }
    current->isEndOfWord = true;
}


Node::Node(char v) : value {v}, isEndOfWord{ false } {
    children = new std::map<char, Node*> {};
}

bool Node::hasChild(char &c) const {
    return !children->count(c);
}

void Node::addChild(char &c) const {
    children->insert({c, new Node{c }});
}

Node* Node::getChild(char &c) const {
    return children->at(c);
}
