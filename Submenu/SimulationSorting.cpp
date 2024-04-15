#include "SimulationSorting.h"
#include "../Operations/FillArray.h"
#include "../Operations/Sorting.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

template<typename T>
SimulationSorting<T>::SimulationSorting() {
}

template<typename T>
SimulationSorting<T>::~SimulationSorting() {
}

template<typename T>
void SimulationSorting<T>::sort(int methodIterator) {
    int size;
    int iterator = 100;
    FillArray<T> fillArray;
    for(int fillingIterator = 0; fillingIterator < 5; fillingIterator++) {
        switch(fillingIterator) {
            case 0:
                cout << endl;
                cout << "Wypelnienie losowe\n";
                break;
            case 1:
                cout << endl;
                cout << "Wypelnienie posortowane rosnaco:\n";
                break;
            case 2:
                cout << endl;
                cout << "Wypelnienie posortowane malejaco:\n";
                break;
            case 3:
                cout << endl;
                cout << "Wypelnienie posortowane w 33%:\n";
                break;
            case 4:
                cout << endl;
                cout << "Wypelnienie posortowane w 66%:\n";
                break;
            default:
                cout << "Zly typ wypelnienia!\n";
                break;
        }
        for(int sizeIterator = 0; sizeIterator < 7; sizeIterator++) {
            switch(sizeIterator) {
                case 0:
                    cout << "1000: ";
                    break;
                case 1:
                    cout << "2000: ";
                    break;
                case 2:
                    cout << "5000: ";
                    break;
                case 3:
                    cout << "10000: ";
                    break;
                case 4:
                    cout << "20000: ";
                    break;
                case 5:
                    cout << "50000: ";
                    break;
                case 6:
                    cout << "100000: ";
                    break;
                default:
                    cout << "Zly rozmiar!\n";
                    break;
            }
            time = 0;
            for(int i = 0; i < iterator; i++) {
                switch(sizeIterator) {
                    case 0:
                        size = 1000;
                        break;
                    case 1:
                        size = 2000;
                        break;
                    case 2:
                        size = 5000;
                        break;
                    case 3:
                        size = 10000;
                        break;
                    case 4:
                        size = 20000;
                        break;
                    case 5:
                        size = 50000;
                        break;
                    case 6:
                        size = 100000;
                        break;
                    default:
                        cout << "Zly rozmiar!\n";
                        break;
                }

                T* dataToSort = new T[size];

                switch(fillingIterator) {
                    case 0:
                        fillArray.fillRandom(dataToSort, size);
                        break;
                    case 1:
                        fillArray.fillAscending(dataToSort, size);
                        break;
                    case 2:
                        fillArray.fillDescending(dataToSort, size);
                        break;
                    case 3:
                        fillArray.fillOneThird(dataToSort, size);
                        break;
                    case 4:
                        fillArray.fillTwoThirds(dataToSort, size);
                        break;
                    default:
                        cout << "Zly typ wypelnienia!\n";
                        break;
                }

                switch (methodIterator) {
                    case 1:
                        start = high_resolution_clock::now();
                        Sorting::insertionSort(dataToSort, size);
                        stop = high_resolution_clock::now();
                        break;
                    case 2:
                        start = high_resolution_clock::now();
                        Sorting::heapSort(dataToSort, size);
                        stop = high_resolution_clock::now();
                        break;
                    case 3:
                        start = high_resolution_clock::now();
                        Sorting::shellSortOne(dataToSort, size);
                        stop = high_resolution_clock::now();
                        break;
                    case 4:
                        start = high_resolution_clock::now();
                        Sorting::shellSortTwo(dataToSort, size);
                        stop = high_resolution_clock::now();
                        break;
                    case 5:
                        start = high_resolution_clock::now();
                        Sorting::quickSort(dataToSort, 0, size - 1, 0); // Pivot lewy
                        stop = high_resolution_clock::now();
                        break;
                    case 6:
                        start = high_resolution_clock::now();
                        Sorting::quickSort(dataToSort, 0, size - 1, 1); // Pivot prawy
                        stop = high_resolution_clock::now();
                        break;
                    case 7:
                        start = high_resolution_clock::now();
                        Sorting::quickSort(dataToSort, 0, size - 1, 2); // Pivot środkowy
                        stop = high_resolution_clock::now();
                        break;
                    case 8:
                        start = high_resolution_clock::now();
                        Sorting::quickSort(dataToSort, 0, size - 1, 3); // Pivot losowy
                        stop = high_resolution_clock::now();
                        break;
                    default:
                        cout << "Nieznany rodzaj sortowania\n";
                        break;
                }
                time += duration_cast<duration<double, std::milli>>(stop - start).count();

                delete[] dataToSort;
            }
            cout << "czas sortowania: " << time/iterator << " ms\n";
        }
    }

}








