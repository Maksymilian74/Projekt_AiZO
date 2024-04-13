#include <functional>
#include "FillArray.h"
using namespace std;

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
void FillArray<T>::fillAscending(T* array, int size) {
    fillRandom(array, size); // Wypelnienie tablicy losowymi danymi
    sort(array, array + size); // Posortowanie tablicy rosnaco
}

template<typename T>
void FillArray<T>::fillDescending(T* array, int size) {
    fillRandom(array, size); // Wypełnienie tablicy losowymi danymi
    sort(array, array + size, greater<T>()); // Posortowanie tablicy malejąco
}

template<typename T>
void FillArray<T>::fillOneThird(T* array, int size) {
    fillRandom(array, size); // Wypełnienie tablicy losowymi danymi
    sort(array, array + size / 3); // Posortowanie pierwszego 1/3 tablicy
}

template<typename T>
void FillArray<T>::fillTwoThirds(T* array, int size) {
    fillRandom(array, size); // Wypełnienie tablicy losowymi danymi
    std::sort(array, array + 2 * size / 3); // Posortowanie pierwszych 2/3 tablicy
}

template<typename T>
void FillArray<T>::initRandomSeed() {
    // Inicjalizacja generatora liczb losowych
    srand(time(nullptr));
}

template class FillArray<int>;

