#include "Menu.h"
#include "../Submenu/TestSorting.h"
#include "../Submenu/SimulationSorting.h"
#include "../Submenu/TestSorting.cpp"
#include "../Submenu/SimulationSorting.cpp"
#include <iostream>

using namespace std;

void Menu::selectDataType() { // Implementacja metody wyboru typu danych
    int type;
    do {
        type = displayTypeMenu(); // Wyswietlenie menu wyboru typu danych i pobranie go do zmiennej
        switch (type) {
            case 1:
                cout << "-------------------------------------------\n";
                cout << "Wybrano typ: INT\n";
                runMainMenu<int>(); // Wywolanie menu dla typu INT
                break;
            case 2:
                cout << "-------------------------------------------\n";
                cout << "Wybrano typ: FLOAT\n";
                runMainMenu<float>(); // Wywolanie menu dla typu FLOAT
                break;
            case 3:
                cout << "-------------------------------------------\n";
                cout << "Zakonczenie dzialania programu\n";
                break;
            default:
                cout << "-------------------------------------------\n";
                cout << "Bledny numer, podaj prawidlowa wartosc\n";
                break;
        }
    } while (type !=3);
}

template<typename T>
void Menu::runMainMenu() { // Implementacja glownego menu dla okreslonego typu danych
    int number;
    int test;
    int simulation;
    int sorting;
    int size;
    int filling;
    string fileToOpen;
    string fileToSave;
    TestSorting<T>* testSorting = nullptr; // Deklaracja wskaznika na obiekt TestSorting
    SimulationSorting<T>* simulationSorting = nullptr; // Deklaracja wskaznika na obiekt SimulationSorting

    do {
        number = displayMainMenu(); // Wyswietlenie glownego menu
        switch (number) {
            case 1:
                cout << "-------------------------------------------\n";
                cout << "Tryb pracy testowej\n";
                testSorting = new TestSorting<T>(); // Utworzenie obiektu klasy TestSorting
                do {
                    test = displayTestingMenu(); // Wyswieltenie menu dla trybu testowania
                    switch (test) {
                        case 1:
                            cout << "-------------------------------------------\n";
                            cout << "Wczytanie danych z pliku\n";
                            cout << "Podaj nazwe pliku z rozszerzeniem\n";
                            cin >> fileToOpen;
                            testSorting->loadDataFromFile(fileToOpen);
                            break;
                        case 2:
                            cout << "-------------------------------------------\n";
                            cout << "Zaladowanie losowych danych\n";
                            cout << "Podaj rozmiar tablicy do posortowania\n";
                            cin >> size;
                            filling = displayFillingMenu(); // Wyswietlenie menu do wyboru sposobu wypelnienia tablicy
                            testSorting->loadRandomData(size, filling);
                            break;
                        case 3:
                            cout << "-------------------------------------------\n";
                            cout << "Wykonanie sortowania\n";
                            sorting = displaySortingMenu(); // Wyswietlenie menu do wyboru sposobu sortowania
                            testSorting->sort(sorting);
                            break;
                        case 4:
                            cout << "-------------------------------------------\n";
                            cout << "Wypisanie nieposortowanych danych z tablicy\n";
                            testSorting->displayArrayToSort();
                            break;
                        case 5:
                            cout << "Wypisanie posortowanych danych z tablicy\n";
                            testSorting->displayArraySorted();
                            break;
                        case 6:
                            cout << "-------------------------------------------\n";
                            cout << "Zapisanie danych do pliku\n";
                            cout << "Podaj nazwe pliku z rozszerzeniem\n";
                            cin >> fileToSave;
                            testSorting->saveDataToFile(fileToSave);
                            break;
                        case 7:
                            cout << "-------------------------------------------\n";
                            cout << "Powrot do glownego menu\n";
                            break;
                        default:
                            cout << "-------------------------------------------\n";
                            cout << "Bledny numer, podaj prawidlowa wartosc\n";
                            break;
                    }
                } while(test != 7);
                delete testSorting;  // Zwolnieni pamieci po obiekcie TestSorting
                testSorting = nullptr; // Ustawienie wskaznika na nullptr
                break;
            case 2:
                cout << "-------------------------------------------\n";
                cout << "Tryb pracy badawczej\n";
                simulationSorting = new SimulationSorting<T>(); // Utworzenie obiektu klasy SimulationSorting
                do {
                    simulation = displaySimulationMenu(); // Wyswietlenie menu dla trybu badawczego
                    switch (simulation) {
                        case 1:
                            cout << "-------------------------------------------\n";
                            cout << "Wybor algorytmu sortowania\n";
                            sorting = displaySortingMenu();
                            simulationSorting ->sort(sorting);
                            break;
                        case 2:
                            cout << "-------------------------------------------\n";
                            cout << "Wyjscie do wyboru typu danych\n";
                            break;
                        default:
                            cout << "-------------------------------------------\n";
                            cout << "Bledny numer, podaj prawidlowa wartosc\n";
                            break;
                    }
                } while(simulation != 2);
                delete simulationSorting;  // Zwolnienie pamieci po obiekcie TestSorting
                simulationSorting = nullptr; // Ustawienie wskaźnika na nullptr
                break;
            case 3:
                cout << "-------------------------------------------\n";
                cout << "Wyjscie to wyboru typu danych\n";
                break;
            default:
                cout << "-------------------------------------------\n";
                cout << "Bledny numer, podaj prawidlowa wartosc\n";
                break;
        }
    } while (number != 3);
}

int Menu::displayMainMenu() { // Implementacja wyswietlania glownego menu
    int task;
    cout << "---------------------------\n";
    cout << "     --- Main Menu ---     \n";
    cout << "1. Tryb pracy testowej     \n";
    cout << "2. Tryb pracy badawczej    \n";
    cout << "3. Wybor typu danych       \n";
    cout << "Wpisz numer zadania:";
    cin >> task;
    return task;
}

int Menu::displayTestingMenu() { // Implementacja wyswietlania menu dla trybu testowego
    int task;
    cout << "------------------------------------------------\n";
    cout << "            --- Testing Menu ---                \n";
    cout << "1. Wczytanie danych z pliku                     \n";
    cout << "2. Zaladowanie losowych danych                  \n";
    cout << "3. Wykonanie sortowania                         \n";
    cout << "4. Wypisanie nieposortowanych danych w tablicy  \n";
    cout << "5. Wypisanie posortowanych danych w tablicy     \n";
    cout << "6. Zapisanie danych do pliku                    \n";
    cout << "7. Wyjscie do wyboru typu danych                \n";
    cout << "Wpisz numer zadania:";
    cin >> task;
    return task;
}

int Menu::displaySimulationMenu() { // Implementacja wyswietlania menu dla trybu badawczego
    int task;
    cout << "---------------------------------- \n";
    cout << "      --- Simulation Menu ---      \n";
    cout << "1. Wybor algorytmu sortujacego     \n";
    cout << "2. Wyjscie do wyboru typu danych   \n";
    cout << "Wpisz numer zadania:";
    cin >> task;
    return task;
}

int Menu::displaySortingMenu() { // Implementacja wyswietlania menu do wyboru sposobu sortowania
    int task;
    cout << "------------------------------------------ \n";
    cout << "           --- Sorting Menu ---            \n";
    cout << "1.  Sortowanie przez wstawianie            \n";
    cout << "2.  Sortowanie przez kopcowanie            \n";
    cout << "3.  Sortowanie Shella (I wariant)          \n";
    cout << "4.  Sortowanie Shella (II wariant)         \n";
    cout << "5.  Quicksort (pivot lewy)                 \n";
    cout << "6.  Quicksort (pivot prawy)                \n";
    cout << "7.  Quicksort (pivot srodkowy)             \n";
    cout << "8.  Quicksort (pivot losowy)               \n";
    cout << "9.  Wszystkie sortowania (tylko do badania)\n";
    cout << "Wpisz numer zadania:";
    cin >> task;
    return task;
}

int Menu::displayFillingMenu() { // Implementacja wyswietlania menu do wyboru sposobu wypelnienia
    int task;
    cout << "---------------------------------------------- \n";
    cout << "             --- Filling Menu ---              \n";
    cout << "1.  Wypelnienie losowymi danymi                \n";
    cout << "2.  Wypelnienie danymi posortowanymi rosnaco   \n";
    cout << "3.  Wypelnienie danymi posortowanymi malejaco  \n";
    cout << "4.  Wypelnienie danymi posortowanymi w 33%     \n";
    cout << "5.  Wypelnienie danymi posortowanymi w 66%     \n";
    cout << "Wpisz numer zadania:";
    cin >> task;
    return task;
}

int Menu::displayTypeMenu() { // Implementacja wyswietlania menu do wyboru typu danych
    int task;
    cout << "------------------------\n";
    cout << "   --- Type Menu ---    \n";
    cout << "1.  Typ danych: INT     \n";
    cout << "2.  Typ danych: FLOAT   \n";
    cout << "3.  Wyjscie             \n";
    cout << "Wpisz numer zadania:";
    cin >> task;
    return task;
}
