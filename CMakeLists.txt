cmake_minimum_required(VERSION 3.13)

project(virtual_machine)

set(CMAKE_CXX_STANDARD 14)

include(cmake/clang-format.cmake)
include(cmake/googletest.cmake)

add_subdirectory(src)
add_subdirectory(test)