#ifndef TESTSORTING_H
#define TESTSORTING_H

#include "../Operations/Sorting.h"
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

template<typename T>
class TestSorting {
public:
    TestSorting(); // Konstruktor
    ~TestSorting(); // Destruktor

    void loadDataFromFile(string fileToOpen); // Metoda wczytująca dane z pliku
    void loadRandomData(int size, int fillingMethod); // Metoda generująca losowe dane do sortowania
    void sort(int sortingMethod); // Metoda wykonująca sortowanie i mierząca czas
    void displayArrayToSort(); // Metoda wyświetlająca zawartość tablicy przed sortowaniem
    void displayArraySorted(); // Metoda wyświetlająca zawartość tablicy po sortowaniu
    void saveDataToFile(string fileToSave); // Metoda zapisująca dane do pliku
    void setSizeOfTab(int size); //Metoda ustawiająca wielkosc tablicy
    int getSizeOfTab(); //Metoda do zwrocenia rozmiaru tablicy

private:
    int sizeOfTab; //Rozmiar tablicy
    T* dataToSort; // Tablica przechowująca dane do posortowania
    T* sortedData; // Kopia tablicy danych do posortowania
    std::chrono::high_resolution_clock::time_point start; // Początek pomiaru czasu
    std::chrono::high_resolution_clock::time_point stop; // Koniec pomiaru czasu
    double time; // Czas sortowania
};

#endif

