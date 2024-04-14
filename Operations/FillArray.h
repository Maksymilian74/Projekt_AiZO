#ifndef FILLARRAY_H
#define FILLARRAY_H

#include <cstdlib> // Do wykorzystania funkcji rand()
#include <ctime> // Do inicjalizacji generatora liczb losowych
#include <algorithm>

template<typename T>
class FillArray {
public:
    // Konstruktor
    FillArray();

    // Destruktor
    ~FillArray();

    // Metoda wypełniająca tablicę losowymi danymi
    void fillRandom(T* array, int size);

    // Metoda wypełniająca tablicę danymi posortowanymi rosnąco
    void fillAscending(T* array, int size);

    // Metoda wypełniająca tablicę danymi posortowanymi malejąco
    void fillDescending(T* array, int size);

    // Metoda wypełniająca tablicę danymi posortowanymi w 33%
    void fillOneThird(T* array, int size);

    // Metoda wypełniająca tablicę danymi posortowanymi w 66%
    void fillTwoThirds(T* array, int size);

private:
    // Inicjalizacja generatora liczb losowych
    void initRandomSeed();
};

#endif // FILLARRAY_H
