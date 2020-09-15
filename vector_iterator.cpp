//
// Created by one for all on 14/09/2020.
//

#include "vector_iterator.h"

template <typename Vector>
VectorIterator<Vector>& VectorIterator<Vector>::operator++() {
    m_Ptr++;
    return *this;
}

template<typename Vector>
VectorIterator<Vector> VectorIterator<Vector>::operator++(int){
    VectorIterator iterator = *this;
    (*this)++;
    return iterator;
}

template<typename Vector>
VectorIterator<Vector>& VectorIterator<Vector>::operator--() {
    m_Ptr--;
    return *this;
}

template<typename Vector>
VectorIterator<Vector> VectorIterator<Vector>::operator--(int){
    VectorIterator iterator = *this;
    (*this)--;
    return iterator;
}

template<typename Vector>
typename VectorIterator<Vector>::ReferenceType VectorIterator<Vector>::operator[](std::size_t offset){
    return *(m_Ptr + offset);
}

template<typename Vector>
typename VectorIterator<Vector>::PointerType VectorIterator<Vector>::operator->() {
    return m_Ptr;
}

template<typename Vector>
typename VectorIterator<Vector>::ReferenceType VectorIterator<Vector>::operator*() {
    *m_Ptr;
}

template<typename Vector>
bool VectorIterator<Vector>::operator==(const VectorIterator<Vector> &other) const {
    return m_Ptr == other.m_Ptr;
}

template<typename Vector>
bool VectorIterator<Vector>::operator!=(const VectorIterator<Vector> &other) const {
    return m_Ptr != other.m_Ptr;
}