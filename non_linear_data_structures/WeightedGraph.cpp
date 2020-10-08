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

#include "WeightedGraph.h"


template<typename T>
WeightedGraph<T>::WeightedGraph() {
    vertices = new std::map<T, Node *>{};
}


template<typename T>
WeightedGraph<T>::~WeightedGraph() {
    delete vertices;
}


template<typename T>
void WeightedGraph<T>::addNode(const T &label) {
    vertices->insert(std::make_pair( label, new Node { label } ) );
}


template<typename T>
void WeightedGraph<T>::addEdge(const T &from, const T &to, const int& weight) {
    auto fromPair = getNode(from);
    auto toPair = getNode(to);

    if (fromPair == vertices->end() || toPair == vertices->end())
        throw std::runtime_error{ "Invalid argument" };

    Edge *fromToEdge = new Edge{ fromPair->second, toPair->second, weight};
    Edge *toFromEdge = new Edge{ toPair->second, fromPair->second, weight};

    fromPair->second->addEdge(toPair->second, weight);
    toPair->second->addEdge(fromPair->second, weight);
}


template <typename T>
typename WeightedGraph<T>::iterator WeightedGraph<T>::getNode(const T &label) {
    return vertices->lower_bound(label);
}

template <typename T>
void WeightedGraph<T>::print() const {
    for (auto itr = vertices->begin(); itr != vertices->end(); itr++)
    {
        std::cout << itr->first << " is connected to [ ";
        for (auto &values : itr->second->getEdges()) {
            std::cout << values->from->label << "->";
            std::cout << values->to->label << " ";
        }
        std::cout << "]\n";
    }
}