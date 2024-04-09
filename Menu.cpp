#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::runMainMenu() {
    int number;
    do {
        number = displayMainMenu();

        switch (number) {
            case 1:
                cout << "Tryb pracy testowej\n";
                break;
            case 2:
                cout << "Tryb pracy badawczej\n";
                break;
            case 3:
                cout << "Zakonczenie dzialania programu\n";
                break;
            default:
                cout << "Bledny numer, podaj prawidlowa wartosc\n";
        }
    } while (number != 6);
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
