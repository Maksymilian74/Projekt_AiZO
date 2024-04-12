#ifndef TESTSORTING_H
#define TESTSORTING_H

#include "DynamicArray.h"

class TestSorting {
public:
    TestSorting(); // Konstruktor
    ~TestSorting(); // Destruktor

    void loadDataFromFile(); // Metoda wczytująca dane z pliku
    void loadRandomData(); // Metoda generująca losowe dane do sortowania
    void sort(); // Metoda wykonująca sortowanie i mierząca czas
    void displayArray(); // Metoda wyświetlająca zawartość tablicy
    void saveDataToFile(); // Metoda zapisująca dane do pliku

private:
    int* dataToSort; // Tablica do przechowywania danych do posortowania
    int* sortedData; // Tablica do przechowywania posortowanych danych
    double sortingTime; // Zmienna przechowująca czas sortowania
};

#endif

