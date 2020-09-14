#include "vector.hpp"

template<typename T>

void Vector<T>::insert(T item) {
    if (counter >= capacity)
        allocate(capacity * 2);
    array[counter++] = item;
}

template<typename T>
void Vector<T>::removeAt(std::size_t at) {
    checkIndex(at);
    for (int i = at; i < counter && i + 1 < counter; ++i)
        array[i] = array[i + 1];
    counter--;
}

template<typename T>
void Vector<T>::checkIndex(size_t at) const {
    if (at < 0 || at >= counter) throw std::runtime_error {"Invalid index" };
}

template<typename T>
std::size_t Vector<T>::indexOf(std::size_t item) {
    for (int i = 0; i < counter; ++i)
        if (array[i] == item)
            return i;
    return -1;
}

template<typename T>
void Vector<T>::print() const {
    std::cout << "[ ";
    for (int i = 0; i < counter; i++)
        std::cout << array[i] << " ";
    std::cout << "]\n";
}

template<typename T>
T &Vector<T>::operator[](std::size_t index) {
    checkIndex(index);
    return array[index];
}

template<typename T>
T &Vector<T>::operator[](std::size_t index) const {
    checkIndex(index);
    return array[index];
}

template<typename T>
void Vector<T>::allocate(std::size_t newCapacity) {
    T *other = new T[newCapacity];
    for (int i = 0; i < counter; ++i) other[i] = array[i];
    array = other;
    capacity = newCapacity;
}

template<typename T>
T& Vector<T>::getLargest(T item) const {
    T largest = array[0];
    for (size_t i { 1 }; i < counter; ++i)
        if (array[i] > largest) largest = array[i];
    return largest;
}

template<typename T>
std::size_t Vector<T>::size() const {
    return counter;
}

template<typename T>
bool Vector<T>::isEmpty() const {
    return counter == 0;
}
