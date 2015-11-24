
cmake_minimum_required(VERSION 2.8)
project(metaltest)

set(CMAKE_C_FLAGS "-g -Wall -Werror")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
include_directories(include)

set(METALTEST_LIBRARIES)

add_subdirectory(source)

add_library(metal_hooks metal_hooks.c)
add_executable(main main.c)

target_link_libraries(main metal_hooks)
