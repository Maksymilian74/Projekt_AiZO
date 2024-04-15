#include "SimulationSorting.h"
#include "../Operations/FillArray.h"
//#include "../Operations/FillArray.cpp"
#include "../Operations/Sorting.h"
//#include "../Operations/Sorting.cpp"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Inicjalizacja tablicy funkcji sortujących
template<typename T>
typename SimulationSorting<T>::SortingFunction SimulationSorting<T>::sortingMethods[] = {
//        Sorting::insertionSort,
//        Sorting::heapSort,
//        Sorting::shellSortOne,
//        Sorting::shellSortTwo,
        //Sorting::quickSort
};

template<typename T>
SimulationSorting<T>::SimulationSorting() {

    dataToSort = nullptr;
    time = 0;
}

template<typename T>
SimulationSorting<T>::~SimulationSorting() {

    delete[] dataToSort;
}

template<typename T>
void SimulationSorting<T>::sort(int sortingMethod) {
    cout << "Wykonanie sortowania\n";
    int size = 20;
    FillArray<T> fillArray;
    dataToSort = new T[size];
    fillArray.fillRandom(dataToSort, size);

    cout << "Nieposortowane dane\n";
    for (int i = 0; i < size; ++i) {
        cout << dataToSort[i] << " ";
    }
    cout << endl;

    // Pobranie odpowiedniej funkcji sortującej z tablicy i jej wywołanie
    auto sortingFunction = sortingMethods[sortingMethod];
    auto start = high_resolution_clock::now();
    sortingFunction(dataToSort, size);
    auto stop = high_resolution_clock::now();
    time = duration_cast<duration<double, std::milli>>(stop - start).count();

    cout << "Czas sortowania: " << time << " ms\n";

    cout << "Posortowane dane\n";
    for (int i = 0; i < size; ++i) {
        cout << dataToSort[i] << " ";
    }
    cout << endl;

}




