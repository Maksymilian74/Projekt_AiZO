#include "Menu.h"
#include "TestSorting.h"
#include "TestSorting.cpp"
#include <iostream>

using namespace std;

void Menu::runMainMenu() {
    int number;
    int test;
    int simulation;
    int sorting;
    int size;
    TestSorting<int>* testSorting = nullptr; //Deklaracja wskaźnika na obiekt TestSorting

    do {
        number = displayMainMenu();

        switch (number) {
            case 1:
                cout << "Tryb pracy testowej\n";
                // Utworzenie obiektu klasy TestSorting
                testSorting = new TestSorting<int>();
                do {
                    test = displayTestingMenu();
                    switch (test) {
                        case 1:
                            cout << "Wczytanie danych z pliku\n";
                            testSorting->loadDataFromFile();
                            break;
                        case 2:
                            cout << "Zaladowanie losowych danych\n";
                            cout << "Podaj rozmiar tablicy do posortowania\n";
                            cin >> size;
                            testSorting->loadRandomData(size);
                            break;
                        case 3:
                            cout << "Wykonanie sortowania\n";
                            sorting = displaySortingMenu();
                            testSorting->sort(sorting);
                            break;
                        case 4:
                            cout << "Wypisanie danych w tablicy\n";
                            testSorting->displayArray();
                            break;
                        case 5:
                            cout << "Zapisanie danych do pliku\n";
                            testSorting->saveDataToFile();
                            break;
                        case 6:
                            cout << "Powrot do glownego menu\n";
                            break;
                        default:
                            cout << "Bledny numer, podaj prawidlowa wartosc\n";
                            break;
                    }
                } while(test != 6);
                delete testSorting;  //Usuniecie obiektu TestSorting
                testSorting = nullptr; //Ustawienie wskaźnika na nullptr
                break;
            case 2:
                cout << "Tryb pracy badawczej\n";
                do {
                    simulation = displaySimulationMenu();
                    switch (simulation) {
                        case 1:
                            cout << "Wczytanie danych z pliku\n";
                            break;
                        case 2:
                            cout << "Zaladowanie losowych danych\n";
                            break;
                        case 3:
                            cout << "Wykonanie sortowania\n";
                            break;
                        case 4:
                            cout << "Wypisanie danych w tablicy\n";
                            break;
                        case 5:
                            cout << "Zapisanie danych do pliku\n";
                            break;
                        case 6:
                            cout << "Powrot do glownego menu\n";
                            break;
                        default:
                            cout << "Bledny numer, podaj prawidlowa wartosc\n";
                            break;
                    }
                } while(simulation != 6);
                break;
            case 3:
                cout << "Zakonczenie dzialania programu\n";
                break;
            default:
                cout << "Bledny numer, podaj prawidlowa wartosc\n";
                break;
        }
    } while (number != 3);
}

int Menu::displayMainMenu() {
    int task;
    cout << "---------------------------\n";
    cout << "     --- Main Menu ---     \n";
    cout << "1. Tryb pracy testowej     \n";
    cout << "2. Tryb pracy badawczej    \n";
    cout << "3. Wyjscie                 \n";
    cout << "Wpisz numer zadania: ";
    cin >> task;
    return task;
}

int Menu::displayTestingMenu() {
    int task;
    cout << "---------------------------------- \n";
    cout << "       --- Testing Menu ---        \n";
    cout << "1. Wczytanie danych z pliku        \n";
    cout << "2. Zaladowanie losowych danych     \n";
    cout << "3. Wykonanie sortowania            \n";
    cout << "4. Wypisanie danych w tablicy      \n";
    cout << "5. Zapisanie danych do pliku       \n";
    cout << "6. Wyjscie do menu glownego        \n";
    cout << "Wpisz numer zadania: ";
    cin >> task;
    return task;
}

int Menu::displaySimulationMenu() {
    int task;
    cout << "---------------------------------- \n";
    cout << "      --- Simulation Menu ---      \n";
    cout << "1. Wczytanie danych z pliku        \n";
    cout << "2. Zaladowanie losowych danych     \n";
    cout << "3. Wykonanie sortowania            \n";
    cout << "4. Wypisanie danych w tablicy      \n";
    cout << "5. Zapisanie danych do pliku       \n";
    cout << "6. Wyjscie do menu glownego        \n";
    cout << "Wpisz numer zadania: ";
    cin >> task;
    return task;
}

int Menu::displaySortingMenu() {
    int task;
    cout << "---------------------------------- \n";
    cout << "       --- Sorting Menu ---        \n";
    cout << "1.  Sortowanie przez wstawianie    \n";
    cout << "2.  Sortowanie przez kopcowanie    \n";
    cout << "3.  Sortowanie Shella (I wariant)  \n";
    cout << "4.  Sortowanie Shella (II wariant) \n";
    cout << "5.  Quicksort (pivot lewy)         \n";
    cout << "6.  Quicksort (pivot prawy)        \n";
    cout << "7.  Quicksort (pivot środkowy)     \n";
    cout << "8.  Quicksort (pivot losowy)       \n";
    cout << "9.  Wszystkie sortowania           \n";
    cout << "10. Wyjscie do menu                \n";
    cout << "Wpisz numer zadania: ";
    cin >> task;
    return task;
}
