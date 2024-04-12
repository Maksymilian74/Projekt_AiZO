#ifndef SIMULATIONSORTING_H
#define SIMULATIONSORTING_H

#include "DynamicArray.h"

class SimulationSorting {
public:
    SimulationSorting(); // Konstruktor
    ~SimulationSorting(); // Destruktor

    void sort(); // Metoda wykonująca sortowanie i mierzaca czas

private:
    int* dataToSort; // Tablica do przechowywania danych do posortowania
    double sortingTime; // Zmienna przechowująca czas sortowania
};

#endif





