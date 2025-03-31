cmake_minimum_required(VERSION 3.21)
project(cipsoft)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)
add_subdirectory(test)

add_executable(cipsoft main.cpp)
target_link_libraries(cipsoft PRIVATE core)
