#include "Sorting.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

// Sortowanie przez wstawianie
template<typename T>
void Sorting::insertionSort(DynamicArray<T>& tab, int size) {
    for (int i = 1; i < size; i++) {
        T key = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > key) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = key;
    }
}

// Metoda pomocnicza do sortowania przez kopcowanie
template<typename T>
void Sorting::heapHelp(DynamicArray<T>& tab, int size, int root) {
    int tmp = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && tab[left] > tab[tmp])
        tmp = left;

    if (right < size && tab[right] > tab[tmp])
        tmp = right;

    if (tmp != root) {
        swap(tab[root], tab[tmp]);
        heapHelp(tab, size, tmp);
    }
}

// Sortowanie przez kopcowanie
template<typename T>
void Sorting::heapSort(DynamicArray<T>& tab, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapHelp(tab, size, i);

    for (int i = size - 1; i > 0; i--) {
        swap(tab[0], tab[i]);
        heapHelp(tab, i, 0);
    }
}

// Sortowanie Shella (wariant I)
template<typename T>
void Sorting::shellSortOne(DynamicArray<T>& tab, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            T tmp = tab[i];
            int j;
            for (j = i; j >= gap && tab[j - gap] > tmp; j -= gap)
                tab[j] = tab[j - gap];
            tab[j] = tmp;
        }
    }
}

// Sortowanie Shella (wariant II) z użyciem odstępu (2^k) - 1
template<typename T>
void Sorting::shellSortTwo(DynamicArray<T>& tab, int size) {
    int gap = 1;
    while (gap < size / 2)
        gap = 2 * gap + 1;

    while (gap > 0) {
        for (int i = gap; i < size; ++i) {
            T tmp = tab[i];
            int j = i;

            while (j >= gap && tab[j - gap] > tmp) {
                tab[j] = tab[j - gap];
                j -= gap;
            }
            tab[j] = tmp;
        }
        gap /= 2;
    }
}

template<typename T>
int Sorting::pivotPosition(int left, int right, int pivotType) {
    switch (pivotType) {
        case 0:
            cout<<"left\n";
            return left; // Pivot lewy
        case 1:
            cout<<"right\n";
            return right; // Pivot prawy
        case 2:
            cout<<"middle\n";
            return (left + right) / 2;  // Pivot środkowy
        case 3:
            cout<<"random\n";
            return left + rand() % (right - left + 1);  // Pivot losowy
        default:
           return left;
    }
}

template<typename T>
int Sorting::partition(DynamicArray<T>& tab, int left, int right, int pivotType) {
    int pivotIndex = pivotPosition<T>(left, right, pivotType);
    T pivot = tab[pivotIndex]; // Wybór pivota

    // Zamiana miejscami pivota z elementem na pozycji left
    std::swap(tab[left], tab[pivotIndex]);

    int l = left + 1;
    int r = right;

    while (true) {
        // Przesuwanie l w prawo, dopóki nie znajdziemy elementu większego od pivota
        while (l <= r && tab[l] <= pivot)
            l++;

        // Przesuwanie r w lewo, dopóki nie znajdziemy elementu mniejszego od pivota
        while (l <= r && tab[r] > pivot)
            r--;

        // Jeśli l i r się minęły, to przerywamy pętlę
        if (l >= r)
            break;

        // Zamiana miejscami elementów arr[l] i arr[r]
        std::swap(tab[l], tab[r]);
    }

    // Zamiana miejscami pivota z elementem na pozycji r
    std::swap(tab[left], tab[r]);

    // Zwracamy indeks, na którym znajduje się pivot
    return r;
}

template<typename T>
void Sorting::quickSort(DynamicArray<T>& tab, int left, int right, int pivotType) {
    if (left < right) {
        // Podzial tablicy i znalezienie punkt podziału (pivot)
        int pivotIndex = partition(tab, left, right, pivotType);

        // Sortowanie rekurencyjnie elementów przed pivotem i po pivotem
        quickSort(tab, left, pivotIndex - 1, pivotType);
        quickSort(tab, pivotIndex + 1, right, pivotType);
    }
}

