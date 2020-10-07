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

#include "Graph.h"


template<typename T>
Graph<T>::Graph() : mCounter { } {
    adjacencyList = new std::map< Node* ,  std::list<Node*>* > { };
    vertices = new std::map<T, Node*> {};
}


template<typename T>
Graph<T>::~Graph() {
    delete vertices;
    delete adjacencyList;
}


template<typename T>
void Graph<T>::addNode(const T &label) {

    auto node = new Node { label };
    vertices->insert({ label, node });
    adjacencyList->insert( { node, new std::list<Node*>{ } } );
}

template<typename T>
void Graph<T>::addEdge(const T &from, const T &to) {
    auto fromNode = getNode(from);
    auto toNode = getNode(to);

    if (fromNode == vertices->end() || toNode == vertices->end())
        throw std::runtime_error { "No such elements" };

    adjacencyList->lower_bound(fromNode->second)->second->push_back(toNode->second);
}

template<typename T>
typename Graph<T>::iterator Graph<T>::getNode(const T &from) {
    return vertices->lower_bound(from);
}


template<typename T>
bool Graph<T>::isEmpty() const {
    return !mCounter;
}

template<typename T>
void Graph<T>::removeNode(const T &label) {
    auto node = getNode(label);

    if (node == vertices->end()) throw std::runtime_error { "No such element to be removed" };

    for (auto &pair : adjacencyList) {
        for (auto &l : pair->second)
            if (l == node->second)
                l->erase(node->second);
    }
    vertices->erase(label);
    adjacencyList->erase(node->second);
}

template<typename T>
void Graph<T>::removeEdge(const T &from, const T &to) {

    auto fromNode = getNode(from);
    auto toNode = getNode(to);

    if (fromNode == vertices->end() || toNode == vertices->end())
        throw std::runtime_error { "No such elements" };

    auto list = adjacencyList->at(fromNode->second);
    //*list->erase(toNode);
}

template<typename T>
void Graph<T>::print() const {
    for (auto itr = adjacencyList->begin(); itr != adjacencyList->end(); itr++){
        std::cout << itr->first->label << " is connected to [ ";
        for (auto &values : *itr->second)
            std::cout << values->label << " ";
        std::cout << "]\n";
    }
}



