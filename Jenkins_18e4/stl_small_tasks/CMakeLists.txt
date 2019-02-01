# Copyright 2018, GlobalLogic Inc.
# All rights reserved.
#

cmake_minimum_required(VERSION 3.1)

set(ENV{GTEST_DIR} /home/cppbcuser/basecamp/googletest/googletest/)

project(stl_task)

add_executable(stl_task_gTest
    project/stl_task.h
    project/stl_task.cpp
    test/stl_task_gTest.cpp
)
target_include_directories(stl_task_gTest PUBLIC
    project
)
set_target_properties(stl_task_gTest PROPERTIES
    CXX_STANDARD 14
)

target_sources(stl_task_gTest PRIVATE
    $ENV{GTEST_DIR}/src/gtest-all.cc
)
target_include_directories(stl_task_gTest PRIVATE
    $ENV{GTEST_DIR}
    $ENV{GTEST_DIR}/include
)
target_link_libraries(stl_task_gTest
    pthread
)
