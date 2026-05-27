cmake_minimum_required(VERSION 3.20)
project(de_pina)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

set(SRC_GRADIENTE main.cpp)

add_executable(de_pina ${SRC_GRADIENTE})