#include "Sorting.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

// Sortowanie przez wstawianie
template<typename T>
void Sorting::insertionSort(T* tab, int size) {
    T key;
    for (int i = 1; i < size; i++) {
        key = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > key) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = key;
    }
}

// Sortowanie Shella (wariant I - gap: N / 2^k)
template<typename T>
void Sorting::shellSortOne(T* tab, int size) {
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

// Sortowanie Shella (wariant II - gap: (2^k) - 1)
template<typename T>
void Sorting::shellSortTwo(T* tab, int size) {
    int gap = 1;
    while (gap < size / 2)
        gap = 2 * gap + 1;

    while (gap > 0) {
        for (int i = gap; i < size; i++) {
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

// Metoda pomocnicza do sortowania przez kopcowanie odpowiedzialna za naprawe kopca w dol
template<typename T>
void Sorting::heapFixDown(T* tab, int index, int size) {
    int tmp = index;
    int leftChild = 2 * index + 1; // Indeks lewego dziecka w kopcu
    int rightChild = 2 * index + 2; // Indeks prawego dziecka w kopcu

    if (leftChild < size && tab[leftChild] > tab[tmp])
        tmp = leftChild;

    if (rightChild < size && tab[rightChild] > tab[tmp])
        tmp = rightChild;

    if (tmp != index) {
        swap(tab[index], tab[tmp]);

        heapFixDown(tab, tmp, size);
    }
}

// Metoda pomocnicza do sortowania przez kopcowanie odpowiedzialna za tworzenie kopca
template<typename T>
void Sorting::heapCreate(T* tab, int size) {
    for(int i = (size-2) / 2; i >= 0; i--)
        heapFixDown(tab, i, size);
}

// Sortowanie przez kopcowanie
template<typename T>
void Sorting::heapSort(T* tab, int size) {
    heapCreate(tab, size);

    for(int i = size - 1; i > 0; i--) {
        swap(tab[0], tab[i]);
        heapFixDown(tab, 0, i);
    }
}

// Metoda pomocnicza do quicksort z pivotem lewym
template<typename T>
int Sorting::partitionLeft(T* tab, int left, int right) {
    T pivot = tab[left];
    int l = left;
    int r = right;

    while (true) {
        while (tab[l] < pivot)
            l++;
        while (tab[r] > pivot)
            r--;
        if (l < r) {
            swap(tab[l], tab[r]);
            l++;
            r--;
        }
        else {
            if (r == right)
                r--;
            return r;
        }

    }
}

// Metoda pomocnicza do quicksort z pivotem prawym
template<typename T>
int Sorting::partitionRight(T* tab, int left, int right) {
    T pivot = tab[right]; // Wybór pivota
    int l = left;
    int r = right;

    while (true) {
        while (tab[l] < pivot)
            l++;
        while (tab[r] > pivot)
            r--;
        if (l < r) {
            swap(tab[l], tab[r]);
            l++;
            r--;
        }
        else {
            if (r == right)
                r--;
            return r;
        }

    }
}

// Metoda pomocnicza do quicksort z pivotem srodkowym
template<typename T>
int Sorting::partitionMiddle(T* tab, int left, int right) {
    T pivot = tab[(left + right) / 2]; // Wybór pivota
    int l = left;
    int r = right;

    while (true) {
        while (tab[l] < pivot)
            l++;
        while (tab[r] > pivot)
            r--;
        if (l < r) {
            swap(tab[l], tab[r]);
            l++;
            r--;
        }
        else {
            if (r == right)
                r--;
            return r;
        }

    }
}

// Metoda pomocnicza do quicksort z pivotem losowym
template<typename T>
int Sorting::partitionRandom(T* tab, int left, int right) {
    T pivot = tab[left + rand() % (right - left + 1)]; // Wybór pivota
    int l = left;
    int r = right;

    while (true) {
        while (tab[l] < pivot)
            l++;
        while (tab[r] > pivot)
            r--;
        if (l < r) {
            swap(tab[l], tab[r]);
            l++;
            r--;
        }
        else {
            if (r == right)
                r--;
            return r;
        }

    }
}

// Sortowanie quicksort z pivotem ustawionym po prawej
template<typename T>
void Sorting::quickSortLeft(T* tab, int left, int right) {
    if (left < right) {
        // Podzial tablicy i znalezienie punkt podziału (pivot)
        int pivotIndex = partitionLeft<T>(tab, left, right);

        // Sortowanie rekurencyjnie elementów przed pivotem i po pivotem
        quickSortLeft<T>(tab, left, pivotIndex);
        quickSortLeft<T>(tab, pivotIndex + 1, right);
    }
}

// Sortowanie quicksort z pivotem ustawionym po prawej
template<typename T>
void Sorting::quickSortRight(T* tab, int left, int right) {
    if (left < right) {
        // Podzial tablicy i znalezienie punkt podziału (pivot)
        int pivotIndex = partitionRight<T>(tab, left, right);

        // Sortowanie rekurencyjnie elementów przed pivotem i po pivotem
        quickSortRight<T>(tab, left, pivotIndex);
        quickSortRight<T>(tab, pivotIndex + 1, right);
    }
}

// Sortowanie quicksort z pivotem ustawionym po srodku
template<typename T>
void Sorting::quickSortMiddle(T* tab, int left, int right) {
    if (left < right) {
        // Podzial tablicy i znalezienie punkt podziału (pivot)
        int pivotIndex = partitionMiddle<T>(tab, left, right);

        // Sortowanie rekurencyjnie elementów przed pivotem i po pivotem
        quickSortMiddle<T>(tab, left, pivotIndex);
        quickSortMiddle<T>(tab, pivotIndex + 1, right);
    }
}

// Sortowanie quicksort z pivotem ustawionym losowo
template<typename T>
void Sorting::quickSortRandom(T *tab, int left, int right) {
    if (left < right) {
        // Podzial tablicy i znalezienie punkt podziału (pivot)
        int pivotIndex = partitionRandom<T>(tab, left, right);

        // Sortowanie rekurencyjnie elementów przed pivotem i po pivotem
        quickSortRandom<T>(tab, left, pivotIndex);
        quickSortRandom<T>(tab, pivotIndex + 1, right);
    }
}

// Metoda odpowiedzialna za sprawdzenie poprawnosci dzialania algorytmow sortowania
template<typename T>
void Sorting::isSorted(T* tab, int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (tab[i] > tab[i + 1]) {
            cout << "-------------------------------------------\n";
            cout << "Tablica NIE JEST poprawnie posortowana!!!\n";
        }
    }
    cout << "-------------------------------------------\n";
    cout << "Sortowanie przebieglo pomyslnie\n";
}

