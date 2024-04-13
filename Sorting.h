#ifndef SORTING_H
#define SORTING_H



class Sorting {
public:
    // Sortowanie przez wstawianie
    template<typename T>
    static void insertionSort(T* tab, int size);

    // Sortowanie przez kopcowanie
    template<typename T>
    static void heapSort(T* tab, int size);

    // Sortowanie Shella (wariant I)
    template<typename T>
    static void shellSortOne(T* tab, int size);

    // Metoda sortująca Shella dla DynamicArray (2)
    template<typename T>
    static void shellSortTwo(T* tab, int size);

    // Sortowanie quicksort
    template<typename T>
    static void quickSort(T* tab, int low, int high, int pivotType);

    // Metoda sprawdzająca, czy tablica jest posortowana
    template<typename T>
    static void isSorted(T* tab, int size);

 private:
    // Metoda pomocnicza do sortowania przez kopcowanie
    template<typename T>
    static void heapHelp(T* tab, int size, int root);

    // Metoda pomocnicza do ustalenia pivota
    template<typename T>
    static int pivotPosition(int left, int right, int pivotType);

    // Metoda pomocnicza do dzielenia tablicy dla QuickSort
    template<typename T>
    static int partition(T* tab, int low, int high, int pivotType);

};

//#include "Sorting.cpp"

#endif
