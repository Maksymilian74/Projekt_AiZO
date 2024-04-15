#ifndef SORTING_H
#define SORTING_H

template<typename T>
class Sorting {
public:
    // Konstruktor
    Sorting();

    // Konstruktor
    ~Sorting();

    // Setter dla pivotType
    void setPivotType(int type);

    // Getter dla pivotType
    int getPivotType();

    // Sortowanie przez wstawianie
    void insertionSort(T* tab, int size);

    // Sortowanie przez kopcowanie
    void heapSort(T* tab, int size);

    // Sortowanie Shella (wariant I)
    void shellSortOne(T* tab, int size);

    // Metoda sortująca Shella dla DynamicArray (2)
    void shellSortTwo(T* tab, int size);

    // Sortowanie quicksort
    void quickSort(T* tab, int size);

    // Metoda do wywołań rekurencyjnych w quicksort
    void quickSortHelp(T* tab, int left, int right);

    // Metoda sprawdzająca, czy tablica jest posortowana
    void isSorted(T* tab, int size);

 private:
    // Metoda pomocnicza do sortowania przez kopcowanie
    void heapHelp(T* tab, int size, int root);

    // Metoda pomocnicza do ustalenia pivota
    int pivotPosition(int left, int right);

    // Metoda pomocnicza do dzielenia tablicy dla QuickSort
    int partition(T* tab, int low, int high);

    int pivotType; //Pole przechowujące typ pivota
};

//#include "Sorting.cpp"

#endif
