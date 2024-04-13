#include "FillArray.h"

template<typename T>
FillArray<T>::FillArray() {
    // Inicjalizacja generatora liczb losowych
    initRandomSeed();
}

template<typename T>
FillArray<T>::~FillArray() {}

template<typename T>
void FillArray<T>::fillRandom(T* array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 1000; // Losowa liczba z zakresu 0-999
    }
}

template<typename T>
void FillArray<T>::initRandomSeed() {
    // Inicjalizacja generatora liczb losowych
    srand(time(nullptr));
}


