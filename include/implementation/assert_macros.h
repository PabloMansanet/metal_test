#ifndef ASSERT_MACROS_H

#include "type_punning.h"

#define METAL_ASSERT(value) { \
   int metal_value = (value); \
   if (metal_value == 0) {  \
      metal_print_string("  *Assertion failure at "__FILE__":", metal_no_color); \
      metal_print_long_long(__LINE__, metal_no_color); \
      metal_print_string("\n  |---> "#value" evaluated as false\n  \\---> ", metal_no_color); \
      metal_print_string(metal_current_test, metal_no_color); \
      metal_print_string(" failed!\n", metal_no_color); \
      METAL_MAIN_FAIL_TRAMPOLINE(); \
   } \
}

#define METAL_ASSERT_TRUE(value) METAL_ASSERT(value)

#define METAL_ASSERT_FALSE(value) { \
   int metal_value = (value); \
   if (metal_value != 0) {  \
      metal_print_string("  *Assertion failure at "__FILE__":", metal_no_color); \
      metal_print_long_long(__LINE__, metal_no_color); \
      metal_print_string("\n  |---> "#value" evaluated as true\n  \\---> ", metal_no_color); \
      metal_print_string(metal_current_test, metal_no_color); \
      metal_print_string(" failed!\n", metal_no_color); \
      METAL_MAIN_FAIL_TRAMPOLINE(); \
   } \
}

// Bitwise compare. It uses type punning to provide possible interpretations
// of the input types. Only accepts lvalues, so the "expected"/"actual" pattern
// is enforced.
#define METAL_ASSERT_EQ(expected, actual) { \
   metal_punning_union metal_expected_value; \
   METAL_FILL_UNION(metal_expected_value, expected); \
   metal_punning_union metal_actual_value; \
   METAL_FILL_UNION(metal_actual_value, actual); \
   if (!metal_bitwise_compare(&metal_expected_value, &metal_actual_value)) { \
      metal_print_string("  * Assertion failure at "__FILE__":", metal_no_color); \
      metal_print_long_long(__LINE__, metal_no_color); \
      metal_print_string("\n  |---> Expected: \""#expected"\", evaluated as: 0x", metal_no_color); \
      metal_print_hex(metal_expected_value.ll, metal_no_color); \
      metal_report_possible_values(&metal_expected_value); \
      metal_print_string("\n  |---> Actual: \""#actual"\", evaluated as: 0x", metal_no_color); \
      metal_print_hex(metal_actual_value.ll, metal_no_color); \
      metal_report_possible_values(&metal_actual_value); \
      metal_print_string("\n  \\--> Test ", metal_no_color); \
      metal_print_string(metal_current_test, metal_no_color); \
      metal_print_string(" failed!\n", metal_no_color); \
      METAL_MAIN_FAIL_TRAMPOLINE(); \
   } \
}

// Compare two blocks of memory based on a size parameter. Expects lvalues.
#define METAL_ASSERT_MEM_EQ(expected, actual, size) { \
   char metal_failure_reported = 0; \
   char* metal_expected_byte_handle = (char*)expected; \
   char* metal_actual_byte_handle = (char*)actual; \
   for (int i = 0; i < size; i++) \
   { \
      if (metal_expected_byte_handle[i] != metal_actual_byte_handle[i]) \
      { \
         if (!metal_failure_reported) \
         { \
            metal_print_string("  * Assertion failure at "__FILE__":", metal_no_color); \
            metal_print_long_long(__LINE__, metal_no_color); \
            metal_print_string("\n  |-----> Expected: "#expected"\"", metal_no_color); \
            metal_print_string("\n  |-----> Actual: "#actual"\"", metal_no_color); \
            metal_print_string("\n  |-----> Memory differs at the following byte indices:", metal_no_color); \
            metal_print_string("\n  \\---------> ", metal_no_color); \
            metal_failure_reported = 1; \
         } \
         metal_print_string("[", metal_no_color); \
         metal_print_long_long(i, metal_no_color); \
         metal_print_string("]", metal_no_color); \
      } \
   } \
   if (metal_failure_reported) \
      { \
      metal_print_string("\n", metal_no_color); \
      metal_print_string(metal_current_test, metal_no_color); \
      metal_print_string(" failed!\n", metal_no_color); \
      METAL_MAIN_FAIL_TRAMPOLINE(); \
      } \
}

int metal_strlen(const char* str);
int metal_string_eq(const char* str1, const char* str2);

#define METAL_ASSERT_STR_EQ(expected, actual) { \
   const char* evaluated_expected = (expected); \
   const char* evaluated_actual = (actual); \
   if (!metal_string_eq(evaluated_expected, evaluated_actual)) { \
      metal_print_string("  * Assertion failure at "__FILE__":", metal_no_color); \
      metal_print_long_long(__LINE__, metal_no_color); \
      metal_print_string("\n  |-----> Expected: "#expected", evaluated as: \"", metal_no_color); \
      metal_print_string(evaluated_expected, metal_no_color); \
      metal_print_string("\"\n  |-----> Actual: "#actual", evaluated as: \"", metal_no_color); \
      metal_print_string(evaluated_actual, metal_no_color); \
      metal_print_string("\"\n  \\--> Test ", metal_no_color); \
      metal_print_string(metal_current_test, metal_no_color); \
      metal_print_string(" failed!\n", metal_no_color); \
      METAL_MAIN_FAIL_TRAMPOLINE(); \
   } \
}

#define METAL_MAIN_FAIL_TRAMPOLINE() { \
   metal_skip = 1; \
   metal_tests_failed++; \
   goto metal_main; }

#endif
