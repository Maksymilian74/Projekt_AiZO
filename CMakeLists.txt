cmake_minimum_required(VERSION 3.27)
project(Projekt_AiZO)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt_AiZO Main.cpp
        Menu.cpp
        Menu.h
        TestSorting.cpp
        TestSorting.h
        SimulationSorting.cpp
        SimulationSorting.h
        Sorting.cpp
        Sorting.h
        DynamicArray.cpp
        DynamicArray.h
        FillArray.cpp
        FillArray.h
)
