/*******************************************************************************
 * DATA STRUCTURES IMPLEMENTATIONS
 *
 *   __                __
 *  |  \  _  |_  _    (_  |_  _      _ |_      _  _  _
 *  |__/ (_| |_ (_|   __) |_ |  |_| (_ |_ |_| |  (- _)
 *
 *
 * Graph (Directed Graph)
 *
 * -> Graph Applications:
 *  1. Used in social networks
 *  2. GPS
 *
 * -> There are two approaches to implement a graph:
 *      Being:
 *      - V the number of Vertices/Nodes in the graph
 *      - E the number of Edges in the graph
 *      - K the number of edges a given node has
 *
 *
 *                       Matrix   |         List
 *      ---------------------------------------------------
 *      Case             Worst    |   Average    Worst
 *      ---------------------------------------------------
 *      Space            O(V^2)   |  O(V+K)     O(V^2)
 *      Add edge         O(1)     |  O(K)       O(V)
 *      Remove edge      O(1)     |  O(K)       O(V)
 *      Query edge       O(1)     |  O(K)       O(V)
 *      Find neighbors   O(V)     |  O(K)       O(V)
 *      Add node         O(V^2)   |  O(K)       O(1)
 *      Remove node      O(V^2)   |  O(K)       O(V^2)
 *
 *
 * https://en.wikipedia.org/wiki/Graph
 *
 * Created by moboustt on 10/6/20.
 * @author (moboustta6@gmail.com)
 * @github MoBoustta
 ******************************************************************************/

#ifndef DATA__STRUCTURES_GRAPH_H
#define DATA__STRUCTURES_GRAPH_H

#include <iostream>
#include <map>
#include <list>

template<typename GRAPH>
class Node {

public:

    using T = typename GRAPH::VT;

public:

    Node() = default;
    explicit Node(const T& label) : label { label } {};
    ~Node() = default;

public:

    const T& label;
};



template<typename T>
class Graph {

public:

    using VT = T;
    using Node = Node<Graph<T>>;
    using iterator = typename std::map<T, Node*>::iterator;

public:

    Graph();
    ~Graph();

public:

    void addNode(const T &label);

    [[nodiscard]] bool isEmpty() const;

    void addEdge(const T& from, const T& to);

    void removeNode(const T &label);

    void removeEdge(const T &from, const T &to);

    void print() const;

private:

    size_t mCounter;
    std::map<Node*, std::list<Node*>* > *adjacencyList;
    std::map<T, Node*> *vertices;

    iterator getNode(const T &from);
};


#endif //DATA__STRUCTURES_GRAPH_H
