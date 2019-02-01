cmake_minimum_required(VERSION 3.1)

project(bcptrs)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#GTEST
enable_testing()
add_subdirectory(googletest)

#UNIT TESTS
add_subdirectory(test)

# Main binary
file(GLOB_RECURSE bcptrs_SOURCES "src/*.hpp" "src/*.cpp")
add_executable(${CMAKE_PROJECT_NAME} ${bcptrs_SOURCES})
