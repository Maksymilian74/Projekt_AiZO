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
    if (dataToSort != nullptr) {
        cout << "Podmiana starych danych na nowe\n";
        delete[] dataToSort;
        delete[] sortedData;
    } else {
        cout << "Generowanie nowych danych do tablicy\n";
    }
    dataToSort = new T[getSizeOfTab()];
    // Wypełnienie tablicy losowymi danymi za pomocą FillArray
    FillArray<T> fillArray;
    fillArray.fillRandom(dataToSort, size);
}

template<typename T>
void TestSorting<T>::sort(int sortingMethod) {
    cout << "Wykonanie sortowania\n";
    if (dataToSort == nullptr) {
        cout << "Blad! Dane nie zostaly jeszcze wygenerowane!\n";
    } else {
        if(sortedData != nullptr) {
            delete[] sortedData;
        }
        // Skopiowanie danych do tablicy sortedData
        sortedData = new T[getSizeOfTab()];
        for (int i = 0; i < getSizeOfTab(); ++i) {
            sortedData[i] = dataToSort[i];
        }
        switch (sortingMethod) {
            case 1:
                Sorting::insertionSort(sortedData, getSizeOfTab());
                break;
            case 2:
                Sorting::heapSort(sortedData, getSizeOfTab());
                break;
            case 3:
                Sorting::shellSortOne(sortedData, getSizeOfTab());
                break;
            case 4:
                Sorting::shellSortTwo(sortedData, getSizeOfTab());
                break;
            case 5:
                Sorting::quickSort(sortedData, 0, getSizeOfTab() - 1, 0); // Pivot lewy
                break;
            case 6:
                Sorting::quickSort(sortedData, 0, getSizeOfTab() - 1, 1); // Pivot prawy
                break;
            case 7:
                Sorting::quickSort(sortedData, 0, getSizeOfTab() - 1, 2); // Pivot środkowy
                break;
            case 8:
                Sorting::quickSort(sortedData, 0, getSizeOfTab() - 1, 3); // Pivot losowy
                break;
            default:
                cout << "Nieznany rodzaj sortowania\n";
                break;
        }
    }
}

template<typename T>
void TestSorting<T>::displayArrayToSort() {
    if (dataToSort == nullptr) {
        cout << "Dane nie zostaly jeszcze wygenerowane\n";
    } else {
        cout << "Wypisanie nieposortowanych danych w tablicy\n";
        for (int i = 0; i < getSizeOfTab(); ++i) {
            cout << dataToSort[i] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void TestSorting<T>::displayArraySorted() {
    if (sortedData == nullptr) {
        cout << "Dane nie zostaly jeszcze posortowane\n";
    } else {
        cout << "Wypisanie posortowanych danych w tablicy\n";
        for (int i = 0; i < getSizeOfTab(); ++i) {
            cout << sortedData[i] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void TestSorting<T>::saveDataToFile() {
    cout << "Zapisanie danych do pliku\n";
}
