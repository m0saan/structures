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


#ifndef DATA__STRUCTURES_TRIE_H
#define DATA__STRUCTURES_TRIE_H

#include <map>
#include <string>
#include <vector>

class Node {
public:

    Node() = default;
    explicit Node(char v);

public:
    bool hasChild(char& c) const;

    void addChild(char &c) const;

    Node* getChild(char& c) const;

    [[nodiscard]] std::vector<Node*> getChildren() const;

public:

    char value;
    bool isEndOfWord;
    std::map<char, Node*> *children;
};


class Trie {

public:

    Trie();
    ~Trie();

public:

    void insert(const std::string &str);

    bool contains(const std::string& str);

    void preOrderTraversal() const;
    void postOrderTraversal() const;

private:
    Node *root;

private:

    void preOrderTraversal(Node *node) const;
    void postOrderTraversal(Node *node) const;

};



#endif //DATA__STRUCTURES_TRIES_H
