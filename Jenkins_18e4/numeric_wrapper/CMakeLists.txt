# Copyright 2018, GlobalLogic Inc.
# All rights reserved.
#

cmake_minimum_required(VERSION 3.1)

set(ENV{GTEST_DIR} "../googletest/googletest")

project(numeric_wrapper)

add_executable(numeric_wrapper_gTest
    project/numeric_wrapper.h
    project/numeric_wrapper.hpp
    test/numeric_wrapper_gTest.cpp
)
target_include_directories(numeric_wrapper_gTest PUBLIC
    project
)
set_target_properties(numeric_wrapper_gTest PROPERTIES
    CXX_STANDARD 11
)

target_sources(numeric_wrapper_gTest PRIVATE
    $ENV{GTEST_DIR}/src/gtest-all.cc
)
target_include_directories(numeric_wrapper_gTest PRIVATE
    $ENV{GTEST_DIR}
    $ENV{GTEST_DIR}/include
)
target_link_libraries(numeric_wrapper_gTest
    pthread
)
