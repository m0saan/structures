//
// Created by moboustt on 10/8/20.
//

#include "Edge.h"


template<typename GRAPH>
Edge<GRAPH>::Edge(Node *f, Node *t, int w) : from{ f }, to { t }, weight { w } {}


template<typename GRAPH>
Edge<GRAPH>::Edge() = default;


template<typename GRAPH>
Edge<GRAPH>::~Edge()  {
    delete from;
    delete to;
}

