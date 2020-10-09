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


#include "Edge.h"
#include "Edge.cpp"
#include "Node.h"
#include "Node.cpp"
#include "Path.cpp"

template<typename GRAPH>
class NodeEntry{
public:
    using Node = typename GRAPH::Node;
public:
    NodeEntry(int priority, Node *node) : priority(priority), node(node) {}
    bool operator<(const NodeEntry& rhs) const { return this->priority < rhs.priority; }
    bool operator==(const NodeEntry& rhs) const { return this->priority == rhs.priority && this->node == rhs.node; }
    int priority;
    Node *node;
};
template<typename T>
class WeightedGraph {

public:

    using VT = T;
    using Node = Node<WeightedGraph<T>>;
    using Edge = Edge<WeightedGraph<T>>;
    using NodeEntry = NodeEntry<WeightedGraph<T>>;
    using iterator = typename std::map<T, Node*>::iterator;

public:

    WeightedGraph();
    ~WeightedGraph();

public:

    void addNode(const T &label);

    void addEdge(const T& from, const T& to, const int& weight);

    Path getShortestDistance(const T& from, const T& to) {
        auto comparator = [](NodeEntry &nodeEntry, NodeEntry &other) { return nodeEntry.priority > other.priority; };

        std::priority_queue<NodeEntry, std::vector<NodeEntry>, decltype(comparator)> priorityQueue(comparator);
        std::map<Node *, int> distances;
        std::map<Node *, Node *> previousNodes;
        std::set<Node*> visited;


        for (auto &vertexPair : *vertices) {
            distances.insert(std::make_pair(vertexPair.second, std::numeric_limits<int>::max()));
            previousNodes.insert(std::make_pair(vertexPair.second, nullptr));
        }

        auto nodePair = getNode(from);
        priorityQueue.push(NodeEntry{0, nodePair->second});
        distances.at(nodePair->second) = 0;

        while (!priorityQueue.empty()) {
            auto current = priorityQueue.top().node;
            priorityQueue.pop();

            if (visited.count(current))
                continue;

            visited.insert(current);

            for (auto &edge : current->getEdges()) {
                if (!visited.count(edge->to)) {
                    auto distance = edge->weight + distances[current];
                    if (distance < distances.at(edge->to)) distances.at(edge->to) = distance;
                    previousNodes.at(edge->to) = current;
                    priorityQueue.push(NodeEntry{ distances[edge->to], edge->to });
                }
            }
        }

        Path path = buildPath(to, previousNodes);

        return path;
    }

    Path buildPath(const T &to, const std::map<Node *, Node *> &previousNodes) {
        std::__1::stack<const std::string> stack;
        pushPathsToStack(to, previousNodes, stack);

        Path path;
        while (!stack.empty()) {
            path.addNode(stack.top());
            stack.pop();
        }
        return path;
    }

    std::stack<const std::string> pushPathsToStack(const T &to, const std::map<Node *, Node *> &previousNodes, std::stack<const std::string>& stack) {
        stack.push(to);
        auto previous = to;
        auto current = previousNodes.at(vertices->at(previous));
        while (current != nullptr){
            stack.push(current->label);
            previous = current->label;
            current = previousNodes.at(vertices->at(previous));
        }
        return stack;
    }


    //void print() const;

private:

    std::map<T, Node*> *vertices;

private:

    iterator getNode(const T& label);
};


#endif //DATA__STRUCTURES_WEIGHTEDGRAPH_H
