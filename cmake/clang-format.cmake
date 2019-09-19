file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.hpp)

add_custom_target(
        clang-format
        COMMAND clang-format
        -style=file
        -i
        ${ALL_SOURCE_FILES}
)