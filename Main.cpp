#include "Menu.h"
#include "DynamicArray.cpp"
#include "Sorting.cpp"
#include <iostream>

class Main {
public:
    void run() {
//       Menu menu;
//       menu.runMainMenu();
        DynamicArray<int> dynamicArray(10);

        for (int i = 0; i < dynamicArray.getSize(); ++i) {
            dynamicArray[i] = 100 - 2 * i;
        }

        std::cout << "Array content:" << std::endl;
        for (int i = 0; i < dynamicArray.getSize(); ++i) {
            std::cout << dynamicArray[i] << " ";
        }
        std::cout << std::endl;


        Sorting sorting;
        int arraysize = dynamicArray.getSize();
        //sorting.insertionSort(dynamicArray, arraysize);
        //sorting.heapSort(dynamicArray, arraysize);
        //sorting.shellSortOne(dynamicArray, arraysize);
        //sorting.shellSortTwo(dynamicArray, arraysize);
        //sorting.quickSortLeft(dynamicArray, 0, arraysize - 1);
        //sorting.quickSortRight(dynamicArray, 0, arraysize - 1);
        sorting.quickSort(dynamicArray, 0, arraysize - 1,0);


        std::cout << "Sorted array content:" << std::endl;
        for (int i = 0; i < dynamicArray.getSize(); ++i) {
            std::cout << dynamicArray[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Main main;
    main.run();
    return 0;
}


