#ifndef METAL_TEST_H
#define METAL_TEST_H

#include "metal_hooks.h"
#include "implementation/fixture_management.h"

#if defined (__LINE__) && defined (__FILE__)
   #include "implementation/simple_assert_macros.h"
#else
   #include "implementation/assert_macros.h"
#endif

#define METAL_FIXTURE_DEFINE \
   struct metal_fixture_type

#define METAL_FIXTURE_DECLARE \
   struct metal_fixture_type metal_fixture;

#define METAL_FIXTURE_EXTERN \
   extern struct metal_fixture_type metal_fixture;

#define METAL_SETUP \
   static void metal_setup(void) \

#define METAL_TEARDOWN \
   static void metal_teardown(void) \

#define METAL_FIXTURE metal_fixture
#define METAL_FIXTURE_TYPE metal_fixture_type

#define METAL_SUITE_BEGIN \
   static char* metal_current_test = 0; \
   static char metal_skip = 0; \
   static unsigned int metal_tests_ran = 0; \
   static unsigned int metal_tests_failed = 0; \
   int main(void) \
   { \
   metal_main: \
   (void)0;

#define METAL_SUITE_END \
   metal_print_string("=========================\n");  \
   metal_print_string("== Test Suite Finished == "); \
   metal_print_string(__FILE__"\n"); \
   if (metal_tests_failed == 0) \
      metal_print_string("==       Success!      == "); \
   else \
      metal_print_string("==       Failure!      == "); \
   metal_print_long_long(metal_tests_ran - metal_tests_failed); \
   metal_print_string("/"); \
   metal_print_long_long(metal_tests_ran); \
   metal_print_string(" tests passed \n"); \
   metal_print_string("=========================\n");  \
   if (metal_current_test) metal_teardown(); \
}  // End main

#define METAL_TEST( test_name ) \
   char entry_flag_##test_name = 1; \
   if (metal_skip) \
   {  \
      entry_flag_##test_name = 0; \
      if (metal_string_eq(metal_current_test, #test_name) ) \
      { \
         metal_skip = 0; \
      } \
   }  \
   if (entry_flag_##test_name) \
   { \
      if (metal_current_test) metal_teardown(); \
      metal_current_test = #test_name; \
      metal_print_string("------------------\n"  \
                         "-- Running test -- "); \
      metal_print_string(metal_current_test); \
      metal_print_string("\n------------------\n"); \
      metal_tests_ran++; \
      metal_fixture_nuke(); \
      metal_setup(); \
   } \
   if (entry_flag_##test_name) 

#endif
