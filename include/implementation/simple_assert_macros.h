#ifndef ASSERT_MACROS_H
#define ASSERT_MACROS_H

#include "type_punning.h"

#define METAL_ASSERT(value) { \
   int metal_evaluated_value = (value); \
   if ( metal_evaluated_value == 0) {  \
      metal_print_string("  * Assertion failure at test "); \
      metal_print_string(metal_current_test); \
      metal_print_string("\n  |---> \""#value"\" evaluated as false"); \
      metal_print_string("\n  \\--> Test "); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      METAL_MAIN_FAIL_TRAMPOLINE(); \
   } \
}

#define METAL_ASSERT_TRUE(value) METAL_ASSERT(value)

#define METAL_ASSERT_FALSE(value) { \
   int metal_value = (value); \
   if (metal_value != 0) {  \
      metal_print_string("  * Assertion failure at test "); \
      metal_print_string(metal_current_test); \
      metal_print_string("\n  |---> "#value" evaluated as true\n  \\---> "); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      METAL_MAIN_FAIL_TRAMPOLINE(); \
   } \
}


// Bitwise compare. It uses type punning to provide possible interpretations
// of the input types, so it will offer less useful output than the type 
// specific assertion macros. Use with care.
#define METAL_ASSERT_EQ(expected, actual) { \
   metal_punning_union evaluated_expected_value = (metal_punning_union)(expected); \
   metal_punning_union evaluated_actual_value = (metal_punning_union)(actual); \
   if (!metal_bitwise_compare(&evaluated_expected_value, &evaluated_actual_value)) { \
      metal_print_string("  * Assertion failure at test "); \
      metal_print_string(metal_current_test); \
      metal_print_string("\n  |---> Expected: \""#expected"\", evaluated as: 0x"); \
      metal_print_hex(evaluated_expected_value.ll); \
      metal_report_possible_values(&evaluated_expected_value); \
      metal_print_string("\n  |---> Actual: \""#actual"\", evaluated as: 0x"); \
      metal_print_hex(evaluated_actual_value.ll); \
      metal_report_possible_values(&evaluated_actual_value); \
      metal_print_string("\n  \\--> Test "); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      METAL_MAIN_FAIL_TRAMPOLINE(); \
   } \
}

int metal_strlen(const char* str);
int metal_string_eq(const char* str1, const char* str2);

#define METAL_ASSERT_STR_EQ(expected, actual) { \
   const char* evaluated_expected = (expected); \
   const char* evaluated_actual = (actual); \
   if (!metal_string_eq(evaluated_expected, evaluated_actual)) { \
      metal_print_string("  * Assertion failure at test "); \
      metal_print_string(metal_current_test); \
      metal_print_string("\n  |-----> Expected: "#expected", evaluated as: \""); \
      metal_print_string(evaluated_expected); \
      metal_print_string("\"\n  |-----> Actual: "#actual", evaluated as: \""); \
      metal_print_string(evaluated_actual); \
      metal_print_string("\"\n  \\--> Test "); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      METAL_MAIN_FAIL_TRAMPOLINE(); \
   } \
}

#define METAL_ASSERT_MEM_EQ(expected, actual, size) { \
   if (size > sizeof(actual) || size > sizeof(expected)) \
   { \
      metal_print_string("Out of bounds METAL_ASSERT_MEM_EQ access at test "); \
      metal_print_string(metal_current_test); \
      metal_print_string("\n"); \
   } \
   char metal_failure_reported = 0; \
   char* metal_expected_byte_handle = (char*)expected; \
   char* metal_actual_byte_handle = (char*)actual; \
   for (int i = 0; i < size; i++) \
   { \
      if (metal_expected_byte_handle[i] != metal_actual_byte_handle[i]) \
      { \
         if (!metal_failure_reported) \
         { \
      metal_print_string("  * Assertion failure at test "); \
      metal_print_string(metal_current_test); \
            metal_print_string("\n  |-----> Expected: "#expected"\""); \
            metal_print_string("\n  |-----> Actual: "#actual"\""); \
            metal_print_string("\n  |-----> Memory differs at the following byte indices:"); \
            metal_print_string("\n  \\---------> "); \
            metal_failure_reported = 1; \
         } \
         metal_print_string("["); \
         metal_print_long_long(i); \
         metal_print_string("]"); \
      } \
   } \
   if (metal_failure_reported) \
      { \
      metal_print_string("\n"); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      METAL_MAIN_FAIL_TRAMPOLINE(); \
      } \
}

#define METAL_MAIN_FAIL_TRAMPOLINE() { \
   metal_skip = 1; \
   metal_tests_failed++; \
   goto metal_main; }

#endif
