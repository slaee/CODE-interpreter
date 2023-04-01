cmake_minimum_required(VERSION 3.0)
project(code-interpreter)

set(CMAKE_BUILD_TYPE Debug)

include_directories(./include/internal)

# for debugging
# add_executable(
#     code-interpreter
#     src/main.c
#     src/parser/lexer.c
# )

# for testing
add_executable(
    code-interpreter
    test/test.c
    src/parser/lexer.c
)