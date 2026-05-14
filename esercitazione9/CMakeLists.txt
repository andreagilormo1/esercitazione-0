cmake_minimum_required(VERSION 3.20)
project(esercizio_grafi)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

set(SRC_GRAFI grafi.cpp)

add_executable(test_grafi ${SRC_GRAFI})