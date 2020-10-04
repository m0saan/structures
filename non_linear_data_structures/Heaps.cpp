/*******************************************************************************
 * DATA STRUCTURES IMPLEMENTATIONS
 *
 *   __                __
 *  |  \  _  |_  _    (_  |_  _      _ |_      _  _  _
 *  |__/ (_| |_ (_|   __) |_ |  |_| (_ |_ |_| |  (- _)
 *
 *
 * Heaps (Type of Tree)
 *
 * -> Heaps Applications:
 *  1. Sorting (heapSort)
 *  2. Graph algorithms (shortest path)
 *  3. Priority queues
 *
 * -> Features:
 * being N the number of elements in the tree
 * being H the height of the binary heap:
 * Height = log(N)
 * 1. Look Up O(log N) / log(H)
 * 2. Delete O(log N)
 * 3. Insert O(log N)
 * NOTE: if the tree is not well structured performance may degrade to O(n).
 *
 * https://en.wikipedia.org/wiki/Tree
 * https://en.wikipedia.org/wiki/Binary_tree
 *
 * @author (moboustta6@gmail.com)
 * @github MoBoustta
 ******************************************************************************/

#include "Heaps.h"


template<typename T>
Heaps<T>::Heaps() {
    vector = new std::vector<T> {};
}

template<typename T>
Heaps<T>::Heaps(std::size_t capacity) {
    vector = new std::vector<T>(capacity);
}

template<typename T>
Heaps<T>::Heaps(std::initializer_list<T> initializerList) {
    vector = new std::vector<T> (initializerList.begin(), initializerList.end());
}

template<typename T>
Heaps<T>::~Heaps() {
    delete vector;
}

/*
 * Useful formulas:
 *
 *  -> leftIndex = (parentIndex * 2) + 1
 *  -> rightIndex = (parentIndex * 2) + 2
 *  -> parentIndex = (nodeIndex - 1) / 2
 *
 */

template<typename T>
void Heaps<T>::insert(const T &item) {
    vector->push_back(item);

    bubbleUp(item);
}


template<typename T>
void Heaps<T>::remove(const T &item) {
    if (isEmpty()) throw std::runtime_error { "Heap empty can't remove" };


    auto leftMostRightNodeIndex = getLeftMostRightNodeIndex();
    vector->at(0) = vector->at(leftMostRightNodeIndex);
    vector->erase(vector->begin() + leftMostRightNodeIndex);

    bubbleDown();

}

template<typename T>
void Heaps<T>::bubbleDown() {
    auto parentIndex = 0;
    auto index = getLeftIndex(parentIndex);

    while (vector->at(parentIndex) < vector->at(index)){
        swapHeapNodes(parentIndex, index);

        parentIndex = index;
        index = getLeftIndex(parentIndex);
    }
}

template<typename T>
int Heaps<T>::getLeftMostRightNodeIndex() const {

    std::string str = std::bitset<sizeof(decltype(vector->size()))>(vector->size()).to_string();
    int nodeIndex = 0;
    int i = 0;

    size_t n = floor(log2(vector->size())) + 1;
    str = str.substr(str.length() - n);

    while (i++ < str.size() - 1){
        if (str[i] == '0')
            nodeIndex = getLeftIndex(nodeIndex);
        else
            nodeIndex = getRightIndex(nodeIndex);
    }

    return nodeIndex;
}


template <typename T>
void Heaps<T>::bubbleUp(const T &item) {

    int parentIndex = getParentIndex(vector->size() - 1);
    int index = vector->size() - 1;

    while (parentIndex >= 0 && item > vector->at(parentIndex)) {
        swapHeapNodes(parentIndex, index);

        index = parentIndex;
        parentIndex = getParentIndex(index);
    }
}



template <typename T>
void Heaps<T>::swapHeapNodes(int parentIndex, int index) {
    auto tmp = vector->at(parentIndex);
    vector->at(parentIndex) = vector->at(index);
    vector->at(index) = tmp;
}


template<typename T>
constexpr std::size_t Heaps<T>::getRightIndex(std::size_t parentIndex) const {
    return (parentIndex * 2) + 2;
}


template<typename T>
constexpr std::size_t Heaps<T>::getLeftIndex(std::size_t parentIndex) const {
    return (parentIndex * 2) + 1;
}


template<typename T>
constexpr std::size_t Heaps<T>::getParentIndex(std::size_t index) const {
    return (index - 1) / 2;
}


template<typename T>
constexpr bool Heaps<T>::isEmpty() const{
    return vector->empty();
}


template<typename T>
constexpr bool Heaps<T>::size() const {
    return vector->size();
}
