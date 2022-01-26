//
// Created by moboustt on 10/8/20.
//

#ifndef DATA__STRUCTURES_NODE_H
#define DATA__STRUCTURES_NODE_H

#include <vector>

template<typename GRAPH>
class Node {

public:
    using T = typename GRAPH::VT;
    using Edge = typename GRAPH::Edge;

    /*
     * This section is dedicated to the constructors and destructor of the Node class
     */
public:
    Node();
    explicit Node(const T& label);
    ~Node();

    /*
     * This section is dedicated to the public fields and methods
     */
public:
    const T& label;

    void addEdge(Node *to, int weight);

    std::vector<Edge*>& getEdges();

    /*
     * This section is dedicated to the private fields
     */
private:
    std::vector<Edge*> edges;
};


#endif //DATA__STRUCTURES_NODE_H
