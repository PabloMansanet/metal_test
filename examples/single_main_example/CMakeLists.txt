set(EXAMPLES 
    test_file_alpha
    test_file_beta)

foreach (EXAMPLE ${EXAMPLES})
   add_library(${EXAMPLE} ${EXAMPLE}.c)
endforeach(EXAMPLE)

add_executable(single_main_example main.c)
target_link_libraries(single_main_example ${EXAMPLES} metal_test stdlib_metal_hooks)
