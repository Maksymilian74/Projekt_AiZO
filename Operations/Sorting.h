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

    // Sortowanie quicksort dla lewego pivota
    template<typename T>
    static void quickSortLeft(T* tab, int low, int high);

    // Sortowanie quicksort dla prawego pivota
    template<typename T>
    static void quickSortRight(T* tab, int low, int high);

    // Sortowanie quicksort dla srodkowego pivota
    template<typename T>
    static void quickSortMiddle(T* tab, int low, int high);

    // Sortowanie quicksort dla losowego pivota
    template<typename T>
    static void quickSortRandom(T* tab, int low, int high);

    // Metoda sprawdzająca, czy tablica jest posortowana
    template<typename T>
    static void isSorted(T* tab, int size);

 private:
    // Metoda pomocnicza do sortowania przez kopcowanie
    template<typename T>
    static void heapCreate(T* tab, int size);

    // Metoda pomocnicza do sortowania przez kopcowanie
    template<typename T>
    static void heapFixDown(T* tab, int index, int size);

    // Metoda pomocnicza do dzielenia tablicy dla QuickSort z lewym pivotem
    template<typename T>
    static int partitionLeft(T* tab, int low, int high);

    // Metoda pomocnicza do dzielenia tablicy dla QuickSort z prawym pivotem
    template<typename T>
    static int partitionRight(T* tab, int low, int high);

    // Metoda pomocnicza do dzielenia tablicy dla QuickSort z srodkowym pivotem
    template<typename T>
    static int partitionMiddle(T* tab, int low, int high);

    // Metoda pomocnicza do dzielenia tablicy dla QuickSort z losowym pivotem
    template<typename T>
    static int partitionRandom(T* tab, int low, int high);

};

#endif
