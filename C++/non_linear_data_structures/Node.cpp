//
// Created by moboustt on 10/8/20.
//

#include "Node.h"

template<typename GRAPH>
Node<GRAPH>::Node(const T& label) : label { label } {};


template<typename GRAPH>
void Node<GRAPH>::addEdge(Node *to, int weight) {
    edges.push_back(new Edge{ this, to, weight});
}


template<typename GRAPH>
std::vector<typename Node<GRAPH>::Edge*> &Node<GRAPH>::getEdges() {
    return edges;
}
