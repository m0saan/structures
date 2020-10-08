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
 * https://en.wikipedia.org/wiki/Graph
 *
 * Created by moboustt on 10/6/20.
 * @author (moboustta6@gmail.com)
 * @github MoBoustta
 ******************************************************************************/

#include "Graph.h"

template <typename T>
Graph<T>::Graph() : mCounter{}
{
    adjacencyList = new std::map<Node*, std::list<Node *> *>{};
    vertices = new std::map<T, Node *>{};
}

template <typename T>
Graph<T>::~Graph()
{
    delete vertices;
    delete adjacencyList;
}

template <typename T>
void Graph<T>::addNode(const T &label)
{

    auto node = new Node{label};
    vertices->insert({label, node});
    adjacencyList->insert({node, new std::list<Node *>{}});
}

template <typename T>
void Graph<T>::addEdge(const T &from, const T &to)
{
    auto fromNode = getNode(from);
    auto toNode = getNode(to);

    if (fromNode == vertices->end() || toNode == vertices->end())
        throw std::runtime_error{"No such elements"};

    adjacencyList->lower_bound(fromNode->second)->second->push_back(toNode->second);
}

template <typename T>
bool Graph<T>::isEmpty() const
{
    return !mCounter;
}

template <typename T>
void Graph<T>::removeNode(const T &label)
{
    auto node = getNode(label);

    if (node == vertices->end())
        throw std::runtime_error{"No such element to be removed"};

    for (auto itr = adjacencyList->begin(); itr != adjacencyList->end(); itr++)
        adjacencyList->lower_bound(itr->first)->second->remove(node->second);

    vertices->erase(label);
    adjacencyList->erase(node->second);
}

template <typename T>
void Graph<T>::removeEdge(const T &from, const T &to)
{

    auto fromNode = getNode(from);
    auto toNode = getNode(to);

    if (fromNode == vertices->end() || toNode == vertices->end())
        throw std::runtime_error{"No such elements"};

    adjacencyList->at(fromNode->second)->remove(toNode->second);
}

template <typename T>
void Graph<T>::print() const
{
    for (auto itr = adjacencyList->begin(); itr != adjacencyList->end(); itr++)
    {
        if (itr->second->empty())
            continue;
        std::cout << itr->first->label << " is connected to [ ";
        for (auto &values : *itr->second)
            std::cout << values->label << " ";
        std::cout << "]\n";
    }
}

template <typename T>
typename Graph<T>::iterator Graph<T>::getNode(const T &value)
{
    return vertices->lower_bound(value);
}

template <typename T>
void Graph<T>::DFSRec(const T &root)
{
    auto pair = getNode(root);

    if (pair == vertices->end())
        throw std::runtime_error{"Invalid argument"};

    std::set<Node *> visited;
    DFSRec(pair->second, visited);
}

template <typename T>
void Graph<T>::DFSRec(Node *root, std::set<Node *> visited)
{

    std::cout << root->label << std::endl;

    visited.insert(root);

    for (auto &item : *adjacencyList->at(root))
    {
        if (!visited.count(item))
            DFSRec(item, visited);
        break;
    }
}

template <typename T>
void Graph<T>::DFSIter(const T &root)
{
    auto pair = getNode(root);

    if (pair == vertices->end())
        throw std::runtime_error{"Invalid argument"};

    std::stack<Node *> stack;
    std::set<Node *> visited;

    stack.push(pair->second);
    while (!stack.empty())
    {

        auto current = stack.top();
        stack.pop();

        if (visited.count(current))
            continue;

        std::cout << current->label << std::endl;
        visited.insert(current);

        for (auto &neighbor : *adjacencyList->at(current))
        {
            if (!visited.count(neighbor))
                stack.push(neighbor);
        }
    }
}

template <typename T>
void Graph<T>::BFS(const T &root)
{
    auto pair = getNode(root);

    if (pair == vertices->end())
        throw std::runtime_error{"Invalid argument"};

    std::queue<Node *> queue;
    std::set<Node *> visited;

    queue.push(pair->second);

    while (!queue.empty())
    {
        auto current = queue.front();
        queue.pop();

        if (visited.count(current))
            continue;

        visited.insert(current);
        std::cout << current->label << std::endl;

        for (auto &neighbors : *adjacencyList->at(current))
        {
            if (!visited.count(neighbors))
                queue.push(neighbors);
        }
    }
}

template<typename T>
std::vector<T> Graph<T>::topologicalSort() {
    std::stack<Node*> stack;
    std::vector<T> vector;
    std::set<Node*> visited;

    for (auto & pair : *vertices) {
        if (!visited.count(pair.second))
            topologicalSort(pair.second, stack, visited);
    }

    while (!stack.empty()){
        vector.push_back(stack.top()->label);
        stack.pop();
    }
    return vector;
}

template<typename T>
void Graph<T>::topologicalSort(Node* node, std::stack<Node *> &stack, std::set<Node*> &visited) {

    visited.insert(node);

    for (auto &neighbors : *adjacencyList->at(node)) {
        if (!visited.count(neighbors))
            topologicalSort(neighbors, stack, visited);
    }
    stack.push(node);
}

template<typename T>
bool Graph<T>::hasCycle() {
    std::set<Node*> all;
    std::set<Node*> visiting;
    std::set<Node*> visited;

    for (auto &pair : *vertices)
        return hasCycle(pair.second, visiting, visited);
}

template<typename T>
bool Graph<T>::hasCycle(Node* node, std::set<Node *> &visiting, std::set<Node *> &visited) {

    if (visiting.count(node))
        return true;

    visiting.insert(node);

    for (auto &neighbor : *adjacencyList->at(node)) {
        if (!visited.count(neighbor))
            return hasCycle(neighbor, visiting, visited);
    }

    visiting.erase(node);
    visited.insert(node);
}
