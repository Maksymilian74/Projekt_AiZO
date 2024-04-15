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
    T* dataToSort; // Tablica przechowująca dane do posortowania
    high_resolution_clock::time_point start; // Początek pomiaru czasu
    high_resolution_clock::time_point stop; // Koniec pomiaru czasu
    double time; // Czas sortowania
};


#endif





