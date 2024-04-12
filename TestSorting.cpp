#include "TestSorting.h"
#include <iostream>

using namespace std;

TestSorting::TestSorting() {

    dataToSort = nullptr;
    sortedData = nullptr;
    sortingTime = 0;
}

TestSorting::~TestSorting() {

    delete[] dataToSort;
    delete[] sortedData;
}

void TestSorting::loadDataFromFile() {
    cout << "Wczytanie danych z pliku\n";
}

void TestSorting::loadRandomData() {
    cout << "Zaladowanie losowych danych\n";
}

void TestSorting::sort() {
    cout << "Wykonanie sortowania\n";
}

void TestSorting::displayArray() {
    cout << "Wypisanie danych w tablicy\n";
}

void TestSorting::saveDataToFile() {
    cout << "Zapisanie danych do pliku\n";
}
