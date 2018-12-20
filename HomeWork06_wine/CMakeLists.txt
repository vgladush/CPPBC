cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME1 "composition")
set(PROJECT_NAME2 "private")

project("HomeWork06" VERSION 1.0.0 LANGUAGES CXX)

set(SRCS wine_example.cpp)
set(SRCS2 wine_example2.cpp)
set(SRC_COMP wine_comp.cpp)
set(SRC_PRIV wine_priv.cpp)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11")

add_library(_comp STATIC ${SRC_COMP})
add_library(_priv STATIC ${SRC_PRIV})

add_executable(${PROJECT_NAME1} ${SRCS})
add_executable(${PROJECT_NAME2} ${SRCS2})

target_link_libraries(${PROJECT_NAME1} _comp)
target_link_libraries(${PROJECT_NAME2} _priv)
