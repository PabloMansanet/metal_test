include_directories(module_include application_include ./)

add_library(mock_module mocks/mock_module.c)
add_library(application application_source/application.c)
add_executable(tests_module tests_module.c)

target_link_libraries(tests_module 
                      application
                      mock_module
                      metal_test 
                      stdlib_metal_hooks)
