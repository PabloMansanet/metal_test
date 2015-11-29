cmake_minimum_required(VERSION 2.8)
project(metal_test_examples)

set(CMAKE_C_FLAGS "-g -Wall -Werror")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include_directories(../include)

add_library(stdlib_metal_hooks ../source/stdlib_metal_hooks.c)
add_library(metal_test ../source/metal_test.c)

add_subdirectory(simple_examples)
add_subdirectory(module_example)
