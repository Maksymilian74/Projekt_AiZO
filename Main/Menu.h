/*
 * Klasa Menu odpowiedzialna jest za komunikacje z uzytkownikiem,
 * wybor niezbednych parametrow takich jak typ danych
 * i wywołanie odpowiednich metod w celu dalszej pracy
 */

#include <iostream>
#include "../Submenu/TestSorting.h"

using namespace std;

class Menu {
public:
    // Metoda odpowiedzialna za wybor typu danych
    void selectDataType();

    // Metoda odpowiedzialna za uruchomienie glownego menu
    template<typename T>
    void runMainMenu();

private:
    // Metoda wyswietlajaca menu glowne
    int displayMainMenu();

    // Metoda wyswietlajaca menu dla trybu testowego
    int displayTestingMenu();

    // Metoda wyswietlajaca menu dla trybu badawczego
    int displaySimulationMenu();

    // Metoda wyswietlajaca sposoby sortowania
    int displaySortingMenu();

    // Metoda wyswietlajaca sposoby wypelnienia tablicy
    int displayFillingMenu();

    // Metoda wyswietlajaca mozliwe do wyboru typy danych
    int displayTypeMenu();

};
