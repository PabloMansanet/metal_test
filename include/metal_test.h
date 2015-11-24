#ifndef METAL_TEST_H
#define METAL_TEST_H

#include "metal_hooks.h"
#include "implementation/fixture_management.h"

#if defined (__LINE__) && defined (__FILE__)
   #include "implementation/assert_macros.h"
#else
   #include "implementation/simple_assert_macros.h"
#endif

#define METAL_FIXTURE_DEFINE \
   static struct _fixture_type _fixture; \
   struct _fixture_type

#define METAL_SETUP \
   static void _metal_setup(void) \

#define METAL_TEARDOWN \
   static void _metal_teardown(void) \

#define METAL_FIXTURE (_fixture)

#define METAL_SUITE \
   static char* _current_test = 0; \
   int main(void)

#define METAL_TEST(test_name) \
   _current_test = #test_name; \
   metal_print_string("---------------\n"  \
                      "--Running test: "); \
   metal_print_string(_current_test); \
   metal_print_string("\n---------------\n"); \
   _metal_teardown(); \
   _fixture_nuke(); \
   _metal_setup(); \

#endif
