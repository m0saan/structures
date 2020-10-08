//
// Created by moboustt on 10/8/20.
//

#ifndef DATA__STRUCTURES_EDGE_H
#define DATA__STRUCTURES_EDGE_H


template <typename GRAPH>
class Edge{

public:

    using Node = typename GRAPH::Node;
    using T = typename GRAPH::VT;

public:
    Edge();
    Edge(Node* f, Node* t, int w);
    ~Edge();

public:

    Node *from;
    Node *to;
    int weight;
};


#endif //DATA__STRUCTURES_EDGE_H
