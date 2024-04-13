#ifndef FILLARRAY_H
#define FILLARRAY_H

#include <cstdlib> // Do wykorzystania funkcji rand()
#include <ctime> // Do inicjalizacji generatora liczb losowych

template<typename T>
class FillArray {
public:
    // Konstruktor
    FillArray();

    // Destruktor
    ~FillArray();

    // Metoda wypełniająca tablicę losowymi danymi

    void fillRandom(T* array, int size);

private:
    // Inicjalizacja generatora liczb losowych
    void initRandomSeed();
};

#endif // FILLARRAY_H
