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
void TestSorting<T>::loadRandomData(int size, int fillingMethod) {
    setSizeOfTab(size);
    if (dataToSort != nullptr) {
        cout << "Podmiana starych danych na nowe\n";
        delete[] dataToSort;
        delete[] sortedData;
    } else {
        cout << "Generowanie nowych danych do tablicy\n";
    }
    dataToSort = new T[getSizeOfTab()];
    FillArray<T> fillArray;

    switch (fillingMethod) {
        case 1:
            cout << "Wybrano losowe wypelnienie tablicy\n";
            fillArray.fillRandom(dataToSort, size);
            break;
        case 2:
            cout << "Wybrano wypelnienie tablicy danymi posortowanymi rosnaco\n";
            fillArray.fillAscending(dataToSort, size);
            break;
        case 3:
            cout << "Wybrano wypelnienie tablicy danymi posortowanymi malejaco\n";
            fillArray.fillDescending(dataToSort, size);
            break;
        case 4:
            cout << "Wybrano wypelnienie tablicy danymi posortowanymi w 33%\n";
            fillArray.fillOneThird(dataToSort, size);
            break;
        case 5:
            cout << "Wybrano wypelnienie tablicy danymi posortowanymi w 66%\n";
            fillArray.fillTwoThirds(dataToSort, size);
            break;
        default:
            cout << "Nieznany sposób wypelnienia tablicy\n";
            break;
    }
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
                Sorting::isSorted(sortedData, getSizeOfTab());
                break;
            case 6:
                Sorting::quickSort(sortedData, 0, getSizeOfTab() - 1, 1); // Pivot prawy
                Sorting::isSorted(sortedData, getSizeOfTab());
                break;
            case 7:
                Sorting::quickSort(sortedData, 0, getSizeOfTab() - 1, 2); // Pivot środkowy
                Sorting::isSorted(sortedData, getSizeOfTab());
                break;
            case 8:
                Sorting::quickSort(sortedData, 0, getSizeOfTab() - 1, 3); // Pivot losowy
                Sorting::isSorted(sortedData, getSizeOfTab());
                break;
            case 9:
                cout << "Wszystkie sortowania dostepne sa tylko w trybie badawczym!\n";
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
