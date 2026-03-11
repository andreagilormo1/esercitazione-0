cmake_minimum_required(VERSION 3.20)

project(Esercitazione1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

add_executable(stampa_parametri main_parte2.cpp)

add_executable(calcola_medie esercitazione1.cpp)
