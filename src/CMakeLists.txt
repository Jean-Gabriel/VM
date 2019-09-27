project(virtual_machine)

include_directories(vm)

ADD_LIBRARY(vm_lib STATIC
        vm/state.hpp
        vm/virtual_machine.hpp
        vm/virtual_machine.cpp
        vm/type.hpp
        vm/opcodes.hpp vm/executor/executor.cpp vm/executor/executor.hpp vm/executor/number_executables.cpp vm/type.cpp)

add_executable(virtual_machine main.cpp)
target_link_libraries(virtual_machine vm_lib)