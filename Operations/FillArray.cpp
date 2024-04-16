#include <functional>
#include <ctime>
#include "FillArray.h"

using namespace std;

// Konstruktor
template<typename T>
FillArray<T>::FillArray() {
    initRandomSeed(); // Inicjalizacja generatora liczb losowych
}

// Destruktor
template<typename T>
FillArray<T>::~FillArray() {}

// Metoda odpowiedzialna za wypelnienie tablicy losowymi wartosciami
template<typename T>
void FillArray<T>::fillRandom(T* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = static_cast<T>(rand() % 10000) + static_cast<T>(rand()) / RAND_MAX; // Losowa liczba z zakresu 0-10000
    }
}

// Metoda odpowiedzialna za wypelnienie tablicy posortowanej rosnaco
template<typename T>
void FillArray<T>::fillAscending(T* array, int size) {
    fillRandom(array, size); // Wypelnienie tablicy losowymi danymi
    sort(array, array + size); // Posortowanie tablicy rosnaco
}

// Metoda odpowiedzialna za wypelnienie tablicy posortowanej malejaco
template<typename T>
void FillArray<T>::fillDescending(T* array, int size) {
    fillRandom(array, size); // Wypełnienie tablicy losowymi danymi
    sort(array, array + size, greater<T>()); // Posortowanie tablicy malejaco
}

// Metoda odpowiedzialna za wypelnienie tablicy posortowanej w 33%
template<typename T>
void FillArray<T>::fillOneThird(T* array, int size) {
    int tmp = size / 3;
    for(int i = 0; i < tmp; i++) {
        array[i] = i;
    }
    for(int i = tmp; i < size; i++) {
        array[i] = static_cast<T>(rand() % (10000 - tmp + 1) + tmp + static_cast<T>(rand()) / RAND_MAX); // Losowa liczba z zakresu size/3 -10000
    }
}

// Metoda odpowiedzialna za wypelnienie tablicy posortowanej w 66%
template<typename T>
void FillArray<T>::fillTwoThirds(T* array, int size) {
    int tmp = 2 * size / 3;
    for(int i = 0; i < tmp; i++) {
        array[i] = i;
    }
    for(int i = tmp; i < size; i++) {
        array[i] = static_cast<T>(rand() % (10000 - tmp + 1) + tmp + static_cast<T>(rand()) / RAND_MAX); // Losowa liczba z zakresu 2*size/3 -10000
    }
}

// Metoda odpowiedzialna za inicjalizacje generatora liczb losowych
template<typename T>
void FillArray<T>::initRandomSeed() {
    srand(time(nullptr));
}


