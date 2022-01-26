#include "vector.hpp"

template<typename T>

void Vector<T>::insert(T item) {
    if (counter >= capacity)
        allocate(capacity * 2, 1);
    array[counter++] = item;
}

template<typename T>
void Vector<T>::removeAt(std::size_t at) {
    checkIndex(at);
    for (std::size_t i = at; i < counter && i + 1 < counter; ++i)
        array[i] = array[i + 1];
    counter--;
}

template<typename T>
void Vector<T>::checkIndex(size_t at) const {
    if (at < 0 || at >= counter) throw std::runtime_error{"Invalid index"};
}

template<typename T>
std::size_t Vector<T>::indexOf(std::size_t item) {
    for (std::size_t i = 0; i < counter; ++i)
        if (array[i] == item)
            return i;
    return -1;
}

template<typename T>
void Vector<T>::print() const {
    std::cout << "[ ";
    for (std::size_t i {}; i < counter; i++)
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
void Vector<T>::allocate(std::size_t newCapacity, int flag) {
    T *other = new T[newCapacity];
    if (flag)
        for (std::size_t i {}; i < counter; ++i) other[i] = array[i];
    array = other;
    capacity = newCapacity;
}

template<typename T>
T &Vector<T>::getLargest(T item) const {
    T largest = array[0];
    for (size_t i{ 1 }; i < counter; ++i)
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

template<typename T>
Vector<T> Vector<T>::set_intersection(const Vector<T> &other) {
    Vector<T> result(counter);
    for (std::size_t i{}; i < counter; ++i) {
        for (std::size_t j = 0; j < counter; ++j) {
            if (other.array[i] == this->array[j])
                result.insert(this->array[j]);
        }
    }
    return result;
}

template<typename T>
bool Vector<T>::operator==(const Vector<T> &other) const {
    for (std::size_t i {}; i < counter; ++i)
        if (other.array[i] != this->array[i]) return false;
    return true;
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> initializerList) : capacity{initializerList.size()} {
    allocate(capacity, 0);
    initializer(initializerList);
}

template<typename T>
Vector<T>::Vector(std::size_t capacity) : counter{0}, capacity{capacity} {
    allocate(2, 0);
}

template<typename T>
void Vector<T>::initializer(const std::initializer_list<T> &initializerList) {
    std::size_t index{0};
    auto iter = initializerList.begin();
    for (; iter != initializerList.end(); iter++, index++)
        array[index] = *iter;
    counter = index;
}

template<typename T>
void Vector<T>::reverse() {
    T temp {};
    for (std::size_t first = 0, last = counter - 1; first < last ; first++, last--) {
        temp = array[first];
        array[first] = array[last];
        array[last] = temp;
    }
}

template<typename T>
void Vector<T>::insertAt(T item, size_t index) {
    if (capacity < capacity + 1)
        allocate(capacity * 1.5, 1);
    for (size_t i { counter - 1 } ; i >= index; --i){
        array[i + 1] = array[i];
    }
    array[index] = item;
    counter++;
}
