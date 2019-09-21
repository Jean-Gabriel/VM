project(virtual_machine)

include_directories(vm)

add_executable(virtual_machine
        main.cpp
        vm/state.hpp
        vm/virtual_machine.hpp
        vm/virtual_machine.cpp
        vm/type.hpp
        )