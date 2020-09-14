#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>

template <typename T>
class Vector {
    public:
    explicit Vector(std::size_t capacity=2) : counter { 0 }, capacity { capacity } {
        allocate(2);
    }

    void insert(T item);
    void removeAt(std::size_t at);
    std::size_t indexOf(std::size_t item);
    T& operator[](std::size_t index);
    T& operator[](std::size_t index) const;
    T& getLargest(T item) const;
    std::size_t size() const;
    bool isEmpty() const;
    void print() const;


private:
    T *array;
    std::size_t counter;
    std::size_t capacity;

    void allocate(std::size_t newCapacity);
    void checkIndex(size_t at) const;
};


#endif