#include "DynamicArray.h"

#include <stdexcept> // Dla std::out_of_range

template<typename T>
DynamicArray<T>::DynamicArray(int size) {
    this->size = size;
    array = new T[size];
}

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


