cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "compare")

project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(SRCS main.cpp)
set(SRC_LIB cmp_dec.cpp)

add_library(stat_lib STATIC ${SRC_LIB})

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} stat_lib)
