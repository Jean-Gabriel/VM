project(virtual_machine)

include_directories(vm)

ADD_LIBRARY(vm_lib STATIC
        vm/state.hpp
        vm/virtual_machine.hpp
        vm/virtual_machine.cpp
        vm/value.hpp
        vm/opcodes.hpp
        vm/executor/executor.cpp
        vm/executor/executor.hpp
        vm/executor/number_executables.cpp
        vm/value.cpp
        vm/executor/boolean_executables.cpp
        vm/executor/conditional_executables.cpp
        vm/executor/global_executables.cpp
        vm/function/function.hpp
        vm/function/function_declaration.hpp
        vm/executor/function_executables.cpp
        vm/executor/local_executables.cpp
        vm/function/function_declaration.cpp
        vm/function/function.cpp vm/memory/memory.cpp vm/memory/memory.hpp vm/memory/chunk.hpp vm/object/object.hpp vm/executor/string_executables.cpp vm/object/object_declaration.hpp vm/executor/object_executables.cpp vm/object/object_declaration.cpp)

add_executable(virtual_machine main.cpp)
target_link_libraries(virtual_machine vm_lib)