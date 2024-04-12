#include <iostream>

using namespace std;

class Menu {
public:
    void runMainMenu();

private:
    int displayMainMenu();
    int displayTestingMenu();
    int displaySimulationMenu();
    int displaySortingMenu();
};
