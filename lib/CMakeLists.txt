cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)

add_library(core Solver.cpp)
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
