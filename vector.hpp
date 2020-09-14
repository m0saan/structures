#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>

template <typename T>
class Vector {
    public:
    explicit Vector(std::size_t capacity=2);
    Vector(std::initializer_list<T> initializerList);

    void insert(T item);
    void insertAt(T item, size_t index);
    void removeAt(std::size_t at);
    std::size_t indexOf(std::size_t item);
    T& operator[](std::size_t index);
    T& operator[](std::size_t index) const;
    bool operator==(const Vector<T>& other) const;

    T& getLargest(T item) const;
    std::size_t size() const;
    bool isEmpty() const;
    void print() const;
    Vector set_intersection(const Vector<T>& other);
    void reverse();


private:
    T *array;
    std::size_t counter;
    std::size_t capacity;

    void allocate(std::size_t newCapacity, int flag);
    void checkIndex(size_t at) const;
    void initializer(const std::initializer_list<T> &initializerList);
};


#endif