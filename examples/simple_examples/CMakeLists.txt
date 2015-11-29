set(EXAMPLES 
    simple_fixture_example
    simple_fixtureless_example
    simple_types_example)

foreach (EXAMPLE ${EXAMPLES})
   add_executable(${EXAMPLE} ${EXAMPLE}.c)
   target_link_libraries(${EXAMPLE} metal_test stdlib_metal_hooks)
endforeach(EXAMPLE)
