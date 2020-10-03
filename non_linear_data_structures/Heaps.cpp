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
