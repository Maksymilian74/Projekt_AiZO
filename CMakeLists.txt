cmake_minimum_required(VERSION 3.27)
project(Projekt_AiZO)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt_AiZO Main/Main.cpp
        Main/Menu.cpp
        Main/Menu.h
        Submenu/TestSorting.cpp
        Submenu/TestSorting.h
        Submenu/SimulationSorting.cpp
        Submenu/SimulationSorting.h
        Operations/Sorting.cpp
        Operations/Sorting.h
        Operations/FillArray.cpp
        Operations/FillArray.h
)

set(CMAKE_EXE_LINKER_FLAGS "-static")
