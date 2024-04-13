#include "DynamicArray.h"

#include <stdexcept> // Dla std::out_of_range

template<typename T>
DynamicArray<T>::DynamicArray() : size(0), array(nullptr) {} // Konstruktor domyślny

template<typename T>
DynamicArray<T>::DynamicArray(int size) : size(size), array(new T[size]) {} // Konstruktor z ustalonym rozmiarem

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;
}

template<typename T>
int DynamicArray<T>::getSize() const {
    return size;
}

template<typename T>
T& DynamicArray<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("DynamicArray<T>::operator[]: index out of range");
    }
    return array[index];
}

template<typename T>
const T& DynamicArray<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("DynamicArray<T>::operator[]: index out of range");
    }
    return array[index];
}

template class DynamicArray<int>;
