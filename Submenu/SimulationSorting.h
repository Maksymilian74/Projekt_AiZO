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

    void sort(int sortingMethod); // Metoda wykonująca sortowanie i mierząca czas


private:
    T* dataToSort; // Tablica przechowująca dane do posortowania
    std::chrono::high_resolution_clock::time_point start; // Początek pomiaru czasu
    std::chrono::high_resolution_clock::time_point stop; // Koniec pomiaru czasu
    double time; // Czas sortowania
    // Typ funkcji sortującej
    using SortingFunction = void (*)(T*, int);
    // Tablica funkcji sortujących
    static SortingFunction sortingMethods[];
};


#endif





