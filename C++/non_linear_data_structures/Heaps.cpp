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
 * https://en.wikipedia.org/wiki/Heap_(data_structure)
 *
 * @author (moboustta6@gmail.com)
 * @github MoBoustta
 ******************************************************************************/

#include "Heaps.h"


template<typename T>
Heaps<T>::Heaps() {
    vector = new std::vector<T>{};
}

template<typename T>
Heaps<T>::Heaps(std::size_t capacity) {
    vector = new std::vector<T>(capacity);
}

template<typename T>
Heaps<T>::Heaps(std::initializer_list<T> initializerList) {
    vector = new std::vector<T>(initializerList.begin(), initializerList.end());
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
T Heaps<T>::remove() {
    if (isEmpty()) throw std::runtime_error{"Heap empty can't remove"};


    auto leftMostRightNodeIndex = getLeftMostRightNodeIndex();
    auto toRemove = vector->at(0);
    vector->at(0) = vector->at(leftMostRightNodeIndex);
    vector->erase(vector->begin() + leftMostRightNodeIndex);

    bubbleDown();

    return toRemove;
}


template<typename T>
T& Heaps<T>::getMax() const {

    return vector->at(0);
}


template<typename T>
constexpr bool Heaps<T>::isEmpty() const {
    return vector->empty();
}


template<typename T>
constexpr bool Heaps<T>::size() const {
    return vector->size();
}


template<typename T>
void Heaps<T>::bubbleUp(const T &item) {

    int parentIndex = getParentIndex(vector->size() - 1);
    int index = vector->size() - 1;

    while (parentIndex >= 0 && item > vector->at(parentIndex)) {
        swapHeapNodes(parentIndex, index);

        index = parentIndex;
        parentIndex = getParentIndex(index);
    }
}


template<typename T>
void Heaps<T>::bubbleDown() {
    int parentIndex{};
    int whichToSwapWithParent{};
    int leftNodeIndex{};
    int rightNodeIndex{};

    while (!(isValidParent(parentIndex, leftNodeIndex, rightNodeIndex))) {

        whichToSwapWithParent = getLargerChildIndex(leftNodeIndex, rightNodeIndex);
        swapHeapNodes(parentIndex, whichToSwapWithParent);

        parentIndex = whichToSwapWithParent;
    }
}

template<typename T>
bool Heaps<T>::isValidParent(int parentIndex, int &leftNodeIndex, int &rightNodeIndex) {

    leftNodeIndex = getLeftIndex(parentIndex);
    rightNodeIndex = getRightIndex(parentIndex);

    if ((leftNodeIndex >= vector->size()) || (rightNodeIndex >= vector->size()))
        return true;

    return vector->at(parentIndex) >= vector->at(leftNodeIndex)
           && vector->at(parentIndex) >= vector->at(rightNodeIndex);
}

template<typename T>
int Heaps<T>::getLargerChildIndex(const int &leftNodeIndex, const int &rightNodeIndex) const {
    return vector->at(leftNodeIndex) > vector->at(rightNodeIndex) ? leftNodeIndex : rightNodeIndex;

}

template<typename T>
int Heaps<T>::getLeftMostRightNodeIndex() const {

    std::string str = std::bitset<sizeof(decltype(vector->size()))>(vector->size()).to_string();
    int nodeIndex = 0;
    int i = 0;

    size_t n = std::floor(std::log2(vector->size())) + 1;
    str = str.substr(str.length() - n);

    while (i++ < str.size() - 1) {
        if (str[i] == '0')
            nodeIndex = getLeftIndex(nodeIndex);
        else
            nodeIndex = getRightIndex(nodeIndex);
    }

    return nodeIndex;
}


template<typename T>
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
void Heaps<T>::heapify(T &input) {
    int largerItemIndex{};
    for (size_t i{}; i < input.size() / 2  -1 ; i++) {
        int parentIndex = i;
        int rightIndex = (parentIndex * 2) + 2;
        int leftIndex = (parentIndex * 2) + 1;
        if (input[parentIndex] < input[leftIndex] || input[parentIndex] < input[rightIndex])
            largerItemIndex = swapItems(input, largerItemIndex, parentIndex, rightIndex, leftIndex);
        parentIndex = largerItemIndex;
    }
}


template<typename T>
bool Heaps<T>::isMaxHeap(T &input) {
    for (size_t i{}; i < input.size() ; i++) {

        int rightIndex = (static_cast<int>(i) * 2) + 2;
        int leftIndex = (static_cast<int>(i) * 2) + 1;

        if (input[i] < input[leftIndex] || input[i] < input[rightIndex])
            return false;
    }

    return true;
}



template <typename T>
int Heaps<T>::swapItems(T &input, int largerItemIndex, int parentIndex, int rightIndex, int leftIndex) {
    largerItemIndex = input[leftIndex] > input[rightIndex] ? leftIndex : rightIndex;
    auto tmp = input[parentIndex];
    input[parentIndex] = input[largerItemIndex];
    input[largerItemIndex] = tmp;
    return largerItemIndex;
}


