cmake_minimum_required(VERSION 2.8)
project(metal_test_examples)

set(CMAKE_C_FLAGS "-g -Wall -Werror")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include_directories(../include)

set(EXAMPLES 
    simple_fixture_example
    types_example
    simple_fixtureless_example)

add_library(stdlib_metal_hooks stdlib_metal_hooks.c)

foreach (EXAMPLE ${EXAMPLES})
   add_executable(${EXAMPLE} ${EXAMPLE}.c)
   target_link_libraries(${EXAMPLE} stdlib_metal_hooks)
endforeach(EXAMPLE)

