cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "testing")

project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(SRCS employee_test.cpp)
set(SRC_LIB employee.cpp fink.cpp high.cpp manager.cpp abstract.cpp)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11")

add_library(_employee STATIC ${SRC_LIB})

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} _employee)
