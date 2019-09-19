CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

enable_testing()

project(virutal_machine_test)

include_directories(../cmake-build-debug/googletest-src/googlemock/include)
include_directories(../cmake-build-debug/googletest-src/googletest/include)

set(SOURCE_FILES main.cpp)
add_executable(virtual_machine_test ${SOURCE_FILES})
add_test(virtual_machine_test virutal_machine_test)

target_link_libraries(virtual_machine_test gtest gtest_main)

