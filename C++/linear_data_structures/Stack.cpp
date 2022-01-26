//
// Created by one for all on 17/09/2020.
//

#include "Stack.h"

template<typename T>
Stack<T>::Stack() : count{ 0 }, capacity { 2 } {
    data = allocate_and_copy(capacity, 0);
}

template<typename T>
Stack<T>::Stack(std::size_t capacity) : capacity{ capacity }, count{ 0 } {
    data = allocate_and_copy(capacity, 0);
}

template<typename T>
void Stack<T>::push(T item) {
    if (count >= capacity) allocate_and_copy(count * 2, 1);
    data[count++] = item;
}

template<typename T>
void Stack<T>::print() {
    std::cout << "[ ";
    for (int i = 0; i < count; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "]\n";
}

template<typename T>
T *Stack<T>::allocate_and_copy(std::size_t newCapacity, char _copy) {
    T *other = new T[capacity];
    if (_copy) {
        for (std::size_t i{}; i < count; ++i) other[i] = data[i];
        data = other;
        capacity = newCapacity;
        return data;
    }
    return other;
}

template<typename T>
void Stack<T>::pop(){
    data[--count] = 0;
}

template<typename T>
T& Stack<T>::top() {
    return data[count - 1];
}

template <typename T>
bool Stack<T>::empty() {
    return count == 0;
}

template<typename T>
std::size_t Stack<T>::size() {
    return count;
}

template<typename T>
bool Stack<T>::operator==(const Stack& other){
    if (this->size() != other.size()) return false;
    std::size_t index {};
    while (index++ < other.size())
        if (data[index] != other.data[index]) return false;
    return true;
}

template<typename T>
T& Stack<T>::min() {

}
