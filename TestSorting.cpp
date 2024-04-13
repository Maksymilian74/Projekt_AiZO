#include "TestSorting.h"
#include "FillArray.h"
#include "FillArray.cpp"
#include "Sorting.h"
#include "Sorting.cpp"
#include <iostream>

using namespace std;

template<typename T>
TestSorting<T>::TestSorting() {
    sortingTime = 0;
    sizeOfTab = 0;
    dataToSort = nullptr;
    sortedData = nullptr;
}

template<typename T>
TestSorting<T>::~TestSorting() {
    delete [] dataToSort;
    delete [] sortedData;
}

template<typename T>
void TestSorting<T>::setSizeOfTab(int size) {
    sizeOfTab = size;
}

template<typename T>
int TestSorting<T>::getSizeOfTab() {
    return sizeOfTab;
}

template<typename T>
void TestSorting<T>::loadDataFromFile() {
    cout << "Wczytanie danych z pliku\n";
}

template<typename T>
void TestSorting<T>::loadRandomData(int size) {
    setSizeOfTab(size);
    cout << "Zaladowanie losowych danych\n";
    dataToSort = new T[size];
    // Wypełnienie tablicy losowymi danymi za pomocą FillArray
    FillArray<T> fillArray;
    fillArray.fillRandom(dataToSort, size);

    // Skopiowanie danych do tablicy sortedData
    sortedData = new T[size];
    for (int i = 0; i < size; ++i) {
        sortedData[i] = dataToSort[i];
    }
}

template<typename T>
void TestSorting<T>::sort(int sortingMethod) {
    cout << "Wykonanie sortowania\n";
    switch (sortingMethod) {
        case 1:
            Sorting::insertionSort(dataToSort, getSizeOfTab());
            break;
        case 2:
            Sorting::heapSort(dataToSort, getSizeOfTab());
            break;
        case 3:
            Sorting::shellSortOne(dataToSort, getSizeOfTab());
            break;
        case 4:
            Sorting::shellSortTwo(dataToSort, getSizeOfTab());
            break;
        case 5:
            Sorting::quickSort(dataToSort, 0, getSizeOfTab() - 1, 0); // Pivot lewy
            break;
        case 6:
            Sorting::quickSort(dataToSort, 0, getSizeOfTab() - 1, 1); // Pivot prawy
            break;
        case 7:
            Sorting::quickSort(dataToSort, 0, getSizeOfTab() - 1, 2); // Pivot środkowy
            break;
        case 8:
            Sorting::quickSort(dataToSort, 0, getSizeOfTab() - 1, 3); // Pivot losowy
            break;
        default:
            cout << "Nieznany rodzaj sortowania\n";
            break;
    }
}

template<typename T>
void TestSorting<T>::displayArray() {
    cout << "Wypisanie danych w tablicy\n";
    for (int i = 0; i < getSizeOfTab(); ++i) {
        cout << dataToSort[i] << " ";
    }
    cout << endl;
}

template<typename T>
void TestSorting<T>::saveDataToFile() {
    cout << "Zapisanie danych do pliku\n";
}
