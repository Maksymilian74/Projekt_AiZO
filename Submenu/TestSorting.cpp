#include "TestSorting.h"
#include "../Operations/FillArray.h"
#include "../Operations/FillArray.cpp"
#include "../Operations/Sorting.h"
#include "../Operations/Sorting.cpp"
#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

template<typename T>
TestSorting<T>::TestSorting() {
    sizeOfTab = 0;
    dataToSort = nullptr;
    sortedData = nullptr;

    // Inicjalizacja czasu
    start = high_resolution_clock::now();
    stop = high_resolution_clock::now();
    time = 0;
}

template<typename T>
TestSorting<T>::~TestSorting() {
    delete [] dataToSort;
    delete [] sortedData;
    dataToSort = nullptr;
    sortedData = nullptr;
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
void TestSorting<T>::loadDataFromFile(string fileToOpen) {
    ifstream file(fileToOpen); // Tworzenie strumienia do odczytu danych z pliku
    if (!file.is_open()) {
        cout << "Blad! Nie udalo sie otworzyc pliku.\n";
        return;
    }

    // Odczytanie rozmiaru tablicy z pierwszej linii pliku
    int size;
    file >> size;
    setSizeOfTab(size);
    if (size <= 0) {
        cout << "Blad! Nieprawidlowy rozmiar tablicy.\n";
        file.close();
        return;
    }

    // Alokacja pamięci na tablicę danych
    if (dataToSort != nullptr) {
        delete[] dataToSort;
        dataToSort = nullptr;
       // delete[] sortedData;
    }
    dataToSort = new T[getSizeOfTab()];

    // Odczytanie danych z pliku i zapisanie ich do tablicy dataToSort
    for (int i = 0; i < sizeOfTab; ++i) {
        if (!(file >> dataToSort[i])) {
            cout<< dataToSort[i] <<" ";
            cout << "Blad! Nie udalo sie odczytac danych z pliku.\n";
            file.close();
            return;
        }
    }

    file.close();
}

template<typename T>
void TestSorting<T>::loadRandomData(int size, int fillingMethod) {
    setSizeOfTab(size);
    if (dataToSort != nullptr) {
        cout << "Podmiana starych danych na nowe\n";
        delete[] dataToSort;
        dataToSort = nullptr;
        //delete[] sortedData;
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
            sortedData = nullptr;
        }
        // Skopiowanie danych do tablicy sortedData
        sortedData = new T[getSizeOfTab()];
        for (int i = 0; i < getSizeOfTab(); ++i) {
            sortedData[i] = dataToSort[i];
        }
        switch (sortingMethod) {
            case 1:
                start = high_resolution_clock::now();
                Sorting::insertionSort(sortedData, getSizeOfTab());
                stop = high_resolution_clock::now();
                break;
            case 2:
                start = high_resolution_clock::now();
                Sorting::heapSort(sortedData, getSizeOfTab());
                stop = high_resolution_clock::now();
                break;
            case 3:
                start = high_resolution_clock::now();
                Sorting::shellSortOne(sortedData, getSizeOfTab());
                stop = high_resolution_clock::now();
                break;
            case 4:
                start = high_resolution_clock::now();
                Sorting::shellSortTwo(sortedData, getSizeOfTab());
                stop = high_resolution_clock::now();
                break;
            case 5:
                start = high_resolution_clock::now();
                Sorting::quickSortLeft(sortedData, 0, getSizeOfTab() - 1); // Pivot lewy
                stop = high_resolution_clock::now();
                break;
            case 6:
                start = high_resolution_clock::now();
                Sorting::quickSortRight(sortedData, 0, getSizeOfTab() - 1); // Pivot prawy
                stop = high_resolution_clock::now();
                break;
            case 7:
                start = high_resolution_clock::now();
                Sorting::quickSortMiddle(sortedData, 0, getSizeOfTab() - 1); // Pivot środkowy
                stop = high_resolution_clock::now();
                break;
            case 8:
                start = high_resolution_clock::now();
                Sorting::quickSortRandom(sortedData, 0, getSizeOfTab() - 1); // Pivot losowy
                stop = high_resolution_clock::now();
                break;
            case 9:
                cout << "Wszystkie sortowania dostepne sa tylko w trybie badawczym!\n";
                break;
            default:
                cout << "Nieznany rodzaj sortowania\n";
                break;
        }

        time = duration_cast<duration<double, std::milli>>(stop - start).count();
        cout << "Czas sortowania: " << time << " ms\n";
        Sorting::isSorted(sortedData, getSizeOfTab());
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
void TestSorting<T>::saveDataToFile(string fileToSave) {
    if (sortedData == nullptr) {
        cout << "Dane nie zostaly jeszcze posortowane\n";
    } else {
        cout << "Zapisanie danych do pliku\n";

        ofstream file(fileToSave); // Tworzenie strumienia do zapisu danych do pliku
        if (!file.is_open()) {
            cout << "Blad! Nie udalo sie otworzyc pliku.\n";
            return;
        }

        // Zapisanie czasu sortowania do pliku
        file << "Czas sortowania: " << time << " ms\n";

        // Zapisanie posortowanej tablicy do pliku
            for (int i = 0; i < getSizeOfTab(); i++) {
                file << sortedData[i] << " ";

            file << "\n";
        }

        file.close();
    }
}
