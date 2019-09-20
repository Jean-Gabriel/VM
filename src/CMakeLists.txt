project(virtual_machine)

include_directories(vm)

add_executable(virtual_machine
        main.cpp
        vm/state.hpp
        vm/virtualmachine.hpp
        vm/virtualmachine.cpp
        )