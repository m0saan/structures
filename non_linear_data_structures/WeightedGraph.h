/*******************************************************************************
 * DATA STRUCTURES IMPLEMENTATIONS
 *
 *   __                __
 *  |  \  _  |_  _    (_  |_  _      _ |_      _  _  _
 *  |__/ (_| |_ (_|   __) |_ |  |_| (_ |_ |_| |  (- _)
 *
 *
 * Undirected Graph
 *
 * -> Graph Applications:
 *  1. Used in social networks
 *  2. GPS
 *  3. Represent connected objects
 *
 * -> There are two approaches to implement a graph:
 *      Being:
 *      - V the number of Vertices/Nodes in the graph
 *      - E the number of Edges in the graph
 *      - K the number of edges a given node has
 *
 *
 *               Adjacency Matrix   |     Adjacency List
 *      ---------------------------------------------------
 *      Case             Worst      |    Average    Worst
 *      ---------------------------------------------------
 *      Space            O(V^2)     |     O(V+K)     O(V^2)
 *      Add edge         O(1)       |     O(K)       O(V)
 *      Remove edge      O(1)       |     O(K)       O(V)
 *      Query edge       O(1)       |     O(K)       O(V)
 *      Find neighbors   O(V)       |     O(K)       O(V)
 *      Add node         O(V^2)     |     O(K)       O(1)
 *      Remove node      O(V^2)     |     O(K)       O(V^2)
 *
 *
 * https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)#Undirected_graph
 *
 * Created by moboustt on 10/8/20.
 * @author (moboustta6@gmail.com)
 * @github MoBoustta
 ******************************************************************************/


#ifndef DATA__STRUCTURES_WEIGHTEDGRAPH_H
#define DATA__STRUCTURES_WEIGHTEDGRAPH_H


#include <iostream>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <queue>


template<typename GRAPH>
class Node {

public:
    using T = typename GRAPH::VT;
    using Edge = typename GRAPH::Edge;

    /*
     * This section is dedicated to the constructors and destructor of the Node class
     */
public:
    Node() = default;
    explicit Node(const T& label) : label { label } {};
    ~Node() = default;

    /*
     * This section is dedicated to the public fields and methods
     */
public:
    const T& label;

    void addEdge(Node *to, int weight) {
        edges.push_back(new Edge{ this, to, weight});
    }

    std::vector<Edge*>& getEdges() {
        return edges;
    }

    /*
     * This section is dedicated to the private fields
     */
private:
    std::vector<Edge*> edges;
};

template <typename GRAPH>
class Edge{

public:

    using Node = typename GRAPH::Node;
    using T = typename GRAPH::VT;
public:
    Edge() = default;
    Edge(Node* f, Node* t, int w) :
                    from{ f }, to { t }, weight { w } {}
    ~Edge() {
        delete from;
        delete to;
    }

public:
    
    Node *from;
    Node *to;
    int weight;
};

template<typename T>
class WeightedGraph {

public:

    using VT = T;
    using Node = Node<WeightedGraph<T>>;
    using Edge = Edge<WeightedGraph<T>>;
    using iterator = typename std::map<T, Node*>::iterator;

public:

    WeightedGraph();
    ~WeightedGraph();

public:

    void addNode(const T &label);

    void addEdge(const T& from, const T& to, const int& weight);

    void print() const;

private:

    std::map<T, Node*> *vertices;

private:

    iterator getNode(const T& label);
};


#endif //DATA__STRUCTURES_WEIGHTEDGRAPH_H
