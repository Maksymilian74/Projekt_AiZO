/*
 * Klasa SimulationSorting odpowiedzialna jest za przeprowadzenie badania dla roznych
 * sposobow wypelnienia tablicy oraz jej rozmiarow, badanie przeprowadzone jest dla
 * wybranego algorytmu sortowania wyznaczajac sredni czas wykonania algorytmu
 */

#ifndef SIMULATIONSORTING_H
#define SIMULATIONSORTING_H

#include "../Operations/Sorting.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

template<typename T>
class SimulationSorting {
public:
    SimulationSorting(); // Konstruktor
    ~SimulationSorting(); // Destruktor

    void sort(int sortingMethod); // Metoda wywolujaca odpowiednie sortowania
private:
    T* dataToSort; // Tablica przechowujaca dane do posortowania
    high_resolution_clock::time_point start; // Zmienna przechowujaca poczatek pomiaru czasu
    high_resolution_clock::time_point stop; // Zmienna przechowujaca koniec pomiaru czasu
    double time; // Zmienna przechowujaca czas sortowania
};


#endif





