cmake_minimum_required(VERSION 3.13)

project(VirtualMachine)

set(CMAKE_CXX_STANDARD 14)

include(cmake/clang-format.cmake)

add_subdirectory(src)