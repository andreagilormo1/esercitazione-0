cmake_minimum_required(VERSION 3.20)
project(esercitazione4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

set(SRC_BT test_bubblesort.cpp)
add_executable(test_bubble ${SRC_BT})

set(SRC_ST test_selectionsort.cpp)
add_executable(test_selection ${SRC_ST})

set(SRC_IT test_insertionsort.cpp)
add_executable(test_insertion ${SRC_IT})

set(SRC_MS measure_sorts.cpp timecounter.cpp)
add_executable(measure_sorts ${SRC_MS})
