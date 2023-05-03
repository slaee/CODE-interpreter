cmake_minimum_required(VERSION 3.0)
project(code-interpreter)

include_directories(./include/internal)
include_directories(./include/utils)

# Set source files based on environment
if(CMAKE_BUILD_TYPE MATCHES Debug)
  add_executable(
    code-scratch
    src/main.c
    src/parser/lexer.c
    src/parser/symtab.c
    src/parser/parser.c
    src/parser/types.c
    src/parser/symtab.c
    src/parser/ast.c
    src/code/visitor.c
  )
elseif(CMAKE_BUILD_TYPE MATCHES Test)
  add_executable(
    code-scratch
    test/test.c
    src/parser/lexer.c
    src/parser/symtab.c
    src/parser/parser.c
    src/parser/types.c
    src/parser/symtab.c
    src/parser/ast.c
    src/code/visitor.c
  )
endif()

# Set default build type to Debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Add custom build type Test
if(NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Test" CACHE STRING "" FORCE)
endif()

# Set compiler flags for Test build
# if(CMAKE_BUILD_TYPE MATCHES Test)
#   set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -Werror")
# endif()