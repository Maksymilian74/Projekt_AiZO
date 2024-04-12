#include "SimulationSorting.h"
#include <iostream>

using namespace std;

SimulationSorting::SimulationSorting() {

    dataToSort = nullptr;
    sortingTime = 0;
}

SimulationSorting::~SimulationSorting() {

    delete[] dataToSort;
}

void SimulationSorting::sort() {
    cout << "Wykonanie sortowania\n";
}



