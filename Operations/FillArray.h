/*
 * Klasa FillArray odpowiedzialna jest za wypelnianie tablic
 * zgodnie z wyborem uzytkownika lub potrzeba w trybie badawczym
 */

#ifndef FILLARRAY_H
#define FILLARRAY_H

#include <cstdlib>
#include <ctime>
#include <algorithm>

template<typename T>
class FillArray {
public:
    // Konstruktor
    FillArray();

    // Destruktor
    ~FillArray();

    // Metoda wypelniajaca tablice losowymi danymi
    void fillRandom(T* array, int size);

    // Metoda wypelniajaca tablice danymi posortowanymi rosnaco
    void fillAscending(T* array, int size);

    // Metoda wypelniajaca tablice danymi posortowanymi malejaco
    void fillDescending(T* array, int size);

    // Metoda wypelniajaca tablice danymi posortowanymi w 33%
    void fillOneThird(T* array, int size);

    // Metoda wypelniajaca tablice danymi posortowanymi w 66%
    void fillTwoThirds(T* array, int size);

private:
    // Inicjalizacja generatora liczb losowych
    void initRandomSeed();
};

#endif
