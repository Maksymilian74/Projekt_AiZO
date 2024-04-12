#ifndef SORTING_H
#define SORTING_H

#include "DynamicArray.h"

class Sorting {
public:
    // Sortowanie przez wstawianie
    template<typename T>
    static void insertionSort(DynamicArray<T>& tab, int size);

    // Sortowanie przez kopcowanie
    template<typename T>
    static void heapSort(DynamicArray<T>& tab, int size);

    // Sortowanie Shella (wariant I)
    template<typename T>
    static void shellSortOne(DynamicArray<T>& tab, int size);

    // Metoda sortująca Shella dla DynamicArray (2)
    template<typename T>
    static void shellSortTwo(DynamicArray<T>& tab, int size);

    // Sortowanie quicksort
    template<typename T>
    static void quickSort(DynamicArray<T>& tab, int low, int high, int pivotType);

 private:
    // Metoda pomocnicza do sortowania przez kopcowanie
    template<typename T>
    static void heapHelp(DynamicArray<T>& tab, int size, int root);

    // Metoda pomocnicza do ustalenia pivota
    template<typename T>
    static int pivotPosition(int left, int right, int pivotType);

    // Metoda pomocnicza do dzielenia tablicy dla QuickSort
    template<typename T>
    static int partition(DynamicArray<T>& tab, int low, int high, int pivotType);

};

//#include "Sorting.cpp"

#endif
