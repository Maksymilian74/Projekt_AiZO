#ifndef TESTSORTING_H
#define TESTSORTING_H

#include "Sorting.h"

template<typename T>
class TestSorting {
public:
    TestSorting(); // Konstruktor
    ~TestSorting(); // Destruktor

    void loadDataFromFile(); // Metoda wczytująca dane z pliku
    void loadRandomData(int size); // Metoda generująca losowe dane do sortowania
    void sort(int sortingMethod); // Metoda wykonująca sortowanie i mierząca czas
    void displayArray(); // Metoda wyświetlająca zawartość tablicy
    void saveDataToFile(); // Metoda zapisująca dane do pliku
    void setSizeOfTab(int size); //Metoda ustawiająca wielkosc tablicy
    int getSizeOfTab(); //Metoda do zwrocenia rozmiaru tablicy

private:
    double sortingTime; // Zmienna przechowująca czas sortowania
    int sizeOfTab; //Rozmiar tablicy
    T* dataToSort; // Tablica przechowująca dane do posortowania
    T* sortedData; // Kopia tablicy danych do posortowania
};

#endif

