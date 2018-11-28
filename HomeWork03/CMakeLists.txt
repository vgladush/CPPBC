cmake_minimum_required(VERSION 3.0)

project("HomeWork03" VERSION 1.0.0 LANGUAGES CXX)

set(MOVE move.cpp mv.cpp)
set(GOLF golf.cpp pe9-1.cpp)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11")

add_executable(move ${MOVE})
add_executable(golf ${GOLF})
