#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>

template <typename Vector>
class VectorIterator{
public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;
public:
    explicit VectorIterator(PointerType p): m_Ptr { p } {}

    VectorIterator& operator++(){
        m_Ptr++;
        return *this;
    }

    VectorIterator operator++(int){
        VectorIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    VectorIterator& operator--(){
        m_Ptr--;
        return *this;
    }

    VectorIterator operator--(int){
        VectorIterator iterator = *this;
        --(*this);
        return iterator;
    }

    ReferenceType operator[](std::size_t index){
        return *(m_Ptr + index);
    }

    PointerType operator->(){
        return m_Ptr;
    }

    ReferenceType operator*(){
        return *(m_Ptr);
    }

    bool operator==(const VectorIterator& other) const {
        return m_Ptr == other.m_Ptr;
    }

    bool operator!=(const VectorIterator& other) const {
        return *this != other;
    }
private:
    PointerType m_Ptr;
};

template <typename T>
class Vector {
public:
    using ValueType = T;
    using Iterator = VectorIterator<Vector<T>>;
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

    Iterator begin() { return Iterator(array); }
    Iterator end() { return Iterator(array + counter); }
private:
    T *array;
    std::size_t counter;
    std::size_t capacity;

    void allocate(std::size_t newCapacity, int flag);
    void checkIndex(size_t at) const;
    void initializer(const std::initializer_list<T> &initializerList);
};


#endif