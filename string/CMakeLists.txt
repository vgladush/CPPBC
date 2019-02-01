cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "testing")

project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(SRCS main.cpp)
set(SRC_LIB my_string.cpp)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

add_library(_my_string STATIC ${SRC_LIB})

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} _my_string)
