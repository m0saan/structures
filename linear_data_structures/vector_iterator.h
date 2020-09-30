//
// Created by one for all on 14/09/2020.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_VECTOR_ITERATOR_H
#define DATA_STRUCTURES_AND_ALGORITHMS_VECTOR_ITERATOR_H

#include <cstdio>
template <typename Vector>
class VectorIterator {
public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;
public:
    explicit VectorIterator(PointerType ptr) : m_Ptr { ptr } {}
    VectorIterator& operator++();
    VectorIterator operator++(int);
    VectorIterator& operator--();
    VectorIterator operator--(int);
    ReferenceType operator[](std::size_t offset);
    PointerType operator->();
    ReferenceType operator*();
    bool operator==(const VectorIterator& other) const;
    bool operator!=(const VectorIterator& other) const;

private:
    PointerType m_Ptr;
};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_VECTOR_ITERATOR_H
