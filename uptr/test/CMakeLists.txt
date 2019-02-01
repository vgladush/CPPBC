file(GLOB_RECURSE bcptrs_UTEST_SOURCES "*.cpp")

#include_directories(${gtest_SOURCE_DIR} ${gtest_SOURCE_DIR}/include)
set(GTEST_DIR ${CMAKE_SOURCE_DIR}/googletest)
set(GTEST_INCLUDES ${GTEST_DIR}/googletest/include)
set(GMOCK_INCLUDES ${GTEST_DIR}/googlemock/include)

set(CMAKE_CXX_STANDARD 11)

include_directories(${GTEST_INCLUDES} ${GMOCK_INCLUDES})
include_directories("${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/test")
add_executable(runUnitTests ${bcptrs_UTEST_SOURCES})
target_link_libraries(runUnitTests gmock gtest gtest_main pthread)
add_test(runUnitTests runUnitTests)
