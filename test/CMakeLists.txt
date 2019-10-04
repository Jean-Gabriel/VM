CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

enable_testing()

project(virtual_machine_run_test)

include_directories(../cmake-build-debug/googletest-src/googlemock/include)
include_directories(../cmake-build-debug/googletest-src/googletest/include)

set(
        SOURCE_FILES
        main.cpp
        test_virtual_machine.cpp
        test_numbers.cpp test_boolean.cpp mocks/mock_virtual_machine.hpp test_conditional.cpp test_globals.cpp test_value_parser.cpp test_locals.cpp test_memory.cpp mocks/mock_memory.hpp test_chunk.cpp test_string.cpp)

add_executable(virtual_machine_run_test ${SOURCE_FILES})
add_test(virtual_machine_run_test virtual_machine_run_test)

target_link_libraries(virtual_machine_run_test gtest gtest_main vm_lib)

