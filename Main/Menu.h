#include <iostream>
#include "../Submenu/TestSorting.h"

using namespace std;

class Menu {
public:
    void selectDataType();

    template<typename T>
    void runMainMenu();

private:
    int displayMainMenu();
    int displayTestingMenu();
    int displaySimulationMenu();
    int displaySortingMenu();
    int displayFillingMenu();
    int displayTypeMenu();

};
