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


#ifndef DATA__STRUCTURES_TRIE_H
#define DATA__STRUCTURES_TRIE_H

#include <array>
#include <string>

class Node {
private:
public:

    Node() = default;
    explicit Node(char v) : value {v}, isEndOfWord{ false } {
        children = new std::array<Node*, NUMBER_OF_CHARACTERS> { nullptr };

       // std::fill(children->begin(), children->end(), Node{});
    }

public:
    char value;
    bool isEndOfWord;

    static constexpr size_t NUMBER_OF_CHARACTERS = 26;
    std::array<Node*, NUMBER_OF_CHARACTERS>  *children;
};


class Trie {

public:

    Trie();
    ~Trie();

public:

    void insert(std::basic_string<char, std::char_traits<char>, std::allocator<char>> str);
private:
    Node *root;
};



#endif //DATA__STRUCTURES_TRIES_H
