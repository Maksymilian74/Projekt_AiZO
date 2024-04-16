/*
 * Klasa TestSorting odpowiedzialna jest za zarzadzanie trybem testowym,
 * zawierajaca odczyt danych z pliku, zapis danych do pliku, wypelnienie tablicy
 * zgodnie z wyborem uzytkownika, posortowanie tablicy wybranym algorytmem sortowania
 * oraz wyswietlenie nieposortowanej lub posortowanej tablicy
 */

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
    // Konstruktor
    TestSorting();

    // Destruktor
    ~TestSorting();

    // Metoda odpowiedzialna za wczytanie danych z pliku
    void loadDataFromFile(string fileToOpen);

    // Metoda odpowiedzialna za generowanie losowych danych do tablicy
    void loadRandomData(int size, int fillingMethod);

    // Metoda odpowiedzialna za wywolanie odpowiedniego algorytmu sortowania i pomiaru czasu
    void sort(int sortingMethod);

    // Metoda odpowiedzialna za wyswietlenie zawartosci nieposortowanej tablicy
    void displayArrayToSort();

    // Metoda odpowiedzialna za wyswietlenie zawartosci posortowanej tablicy
    void displayArraySorted();

    // Metoda odpowiedzialna za zapis danych do pliku
    void saveDataToFile(string fileToSave);

    // Setter pola przechowujacego rozmiar aktualnej tablicy
    void setSizeOfTab(int size);

    // Getter pola przechowujacego rozmiar aktualnej tablicy
    int getSizeOfTab();

private:
    int sizeOfTab; // Pole przechowujace rozmiar aktualnej tablicy
    T* dataToSort; // Wskaznik na tablice przechowujaca nieposortowane dane
    T* sortedData; // Wskaznik na tablice przechowujaca nieposortowane dane
    std::chrono::high_resolution_clock::time_point start; // Zmienna przechowujaca początek pomiaru czasu
    std::chrono::high_resolution_clock::time_point stop; // Zmienna przechowujaca koniec pomiaru czasu
    double time; // Zmienna przechowujaca czas sortowania
};

#endif

