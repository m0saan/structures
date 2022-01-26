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

#ifndef DATA__STRUCTURES_HEAPS_H
#define DATA__STRUCTURES_HEAPS_H

#include <vector>
#include <bitset>
#include <iostream>
#include <cmath>

template<typename T>
class Heaps {
public:
    Heaps();

    explicit Heaps(std::size_t capacity);

    Heaps(std::initializer_list<T> initializerList);

    ~Heaps();

public:

    void insert(const T& item);

    T remove();

    T& getMax() const;

    [[nodiscard]] constexpr bool isEmpty() const;

    [[nodiscard]] constexpr bool size() const;


public:

    static void heapify(T& input);

    static bool isMaxHeap(T& input);

private:

    std::vector<T> *vector;

private:

    void bubbleDown();

    void bubbleUp(const T &item);

    void swapHeapNodes(int parentIndex, int index);

    [[nodiscard]] int getLeftMostRightNodeIndex() const;

    [[nodiscard]] int getLargerChildIndex(const int &leftNodeIndex, const int& rightNodeIndex) const;

    [[nodiscard]] bool isValidParent(int parentIndex, int &leftNodeIndex, int &rightNodeIndex);

    [[nodiscard]] constexpr std::size_t getLeftIndex(std::size_t parentIndex) const;

    [[nodiscard]] constexpr std::size_t getRightIndex(std::size_t parentIndex) const;

    [[nodiscard]] constexpr std::size_t getParentIndex(std::size_t index) const;

    static int swapItems(T &input, int largerItemIndex, int parentIndex, int rightIndex, int leftIndex);
};



#endif //DATA__STRUCTURES_HEAPS_H
