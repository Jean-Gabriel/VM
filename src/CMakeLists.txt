project(virtual_machine)

include_directories(domain)

add_executable(virtual_machine
        main.cpp
        domain/state.hpp
        domain/virtualmachine.hpp
        domain/virtualmachine.cpp
        )