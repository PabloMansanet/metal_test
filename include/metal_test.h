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
   static struct metal_fixture_type metal_fixture; \
   struct metal_fixture_type

#define METAL_SETUP \
   static void metal_setup(void) \

#define METAL_TEARDOWN \
   static void metal_teardown(void) \

#define METAL_FIXTURE (metal_fixture)

#define METAL_SUITE \
   static char* metal_current_test = 0; \
   static char metal_skip_flag = 0;
   int main(void) {

#define METAL_TEST(test_name) \
   char entry_flag_#test_name = 1; \
   if (metal_skip) \
   {  \
      entry_flag_#test_name = 0; \
      if (metal_current_test == #test_name) \
      { \
         metal_skip_flag = 0; \
      } \
   }  \
   if (entry_flag_#test_name) \
   { \
      if (metal_current_test) metal_teardown(); \
      metal_current_test = #test_name; \
      metal_print_string("------------------\n"  \
                         "-- Running test -- "); \
      metal_print_string(metal_current_test); \
      metal_print_string("\n------------------\n"); \
      metal_fixture_nuke(); \
      metal_setup(); \
   } \
   if (entry_flag_#test_name) \
#endif
