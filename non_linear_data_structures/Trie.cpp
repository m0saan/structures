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
        if (current->children->at(index) == nullptr) {
            current->children->at(index) = new Node{c};
            current = current->children->at(index);
        }
    }
    current->isEndOfWord = true;
}


