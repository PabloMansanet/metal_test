#ifndef ASSERT_MACROS_H
#define ASSERT_MACROS_H

#include "type_punning.h"

#define METAL_ASSERT(value) { \
   int metal_value = (value); \
   if (metal_value == 0) {  \
      metal_print_string("  *Assertion failure at "__FILE__":"); \
      metal_print_long_long(__LINE__); \
      metal_print_string("\n  |---> "#value" evaluated as false\n  \\---> "); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      METAL_MAIN_TRAMPOLINE(); \
   } \
}

#define METAL_ASSERT_TRUE(value) METAL_ASSERT(value)

#define METAL_ASSERT_FALSE(value) { \
   int metal_value = (value); \
   if (metal_value != 0) {  \
      metal_print_string("  *Assertion failure at "__FILE__":"); \
      metal_print_long_long(__LINE__); \
      metal_print_string("\n  |---> "#value" evaluated as true\n  \\---> "); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      METAL_MAIN_TRAMPOLINE(); \
   } \
}

// Bitwise compare. It uses type punning to provide possible interpretations
// of the input types. Only accepts lvalues, so the "expected"/"actual" pattern
// is enforced.
#define METAL_ASSERT_EQ(expected, actual) { \
   metal_punning_union expected_value; \
   METAL_FILL_UNION(expected_value, expected); \
   metal_punning_union actual_value; \
   METAL_FILL_UNION(actual_value, actual); \
   if (!metal_bitwise_compare(&expected_value, &actual_value)) { \
      metal_print_string("  * Assertion failure at "__FILE__":"); \
      metal_print_long_long(__LINE__); \
      metal_print_string("\n  |---> Expected: \""#expected"\", evaluated as: 0x"); \
      metal_print_hex(expected_value.ll); \
      metal_report_possible_values(&expected_value); \
      metal_print_string("\n  |---> Actual: \""#actual"\", evaluated as: 0x"); \
      metal_print_hex(actual_value.ll); \
      metal_report_possible_values(&actual_value); \
      metal_print_string("\n  \\--> Test "); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      METAL_MAIN_TRAMPOLINE(); \
   } \
}

// Compare two blocks of memory based on a size parameter. Expects lvalues.
#define METAL_ASSERT_MEM_EQ(expected, actual, size) { \
   if (size > sizeof(actual) || size > sizeof(expected)) \
   { \
      metal_print_string("Out of bounds METAL_ASSERT_MEM_EQ access at "__FILE__":"); \
      metal_print_long_long(__LINE__); \
      metal_print_string("\n"); \
   } \
   char failureReported = 0; \
   char* expectedByteHandle = (char*)expected; \
   char* actualByteHandle = (char*)actual; \
   for (int i = 0; i < size; i++) \
   { \
      if (expectedByteHandle[i] != actualByteHandle [i]) \
      { \
         if (!failureReported) \
         { \
            metal_print_string("  * Assertion failure at "__FILE__":"); \
            metal_print_long_long(__LINE__); \
            metal_print_string("\n  |-----> Expected: "#expected"\""); \
            metal_print_string("\n  |-----> Actual: "#actual"\""); \
            metal_print_string("\n  |-----> Memory differs at the following byte indices:"); \
            metal_print_string("\n  |---------> "); \
            failureReported = 1; \
         } \
         metal_print_string("["); \
         metal_print_long_long(i); \
         metal_print_string("]"); \
      } \
   } \
   if (failureReported) \
      { \
      metal_print_string("\n"); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      METAL_MAIN_TRAMPOLINE(); \
      } \
}
   

int metal_strlen(const char* str);
int metal_string_eq(const char* str1, const char* str2);

#define METAL_ASSERT_STREQ(expected, actual) { \
   const char* evaluated_expected = (expected); \
   const char* evaluated_actual = (actual); \
   if (!metal_string_eq(evaluated_expected, evaluated_actual)) { \
      metal_print_string("  * Assertion failure at "__FILE__":"); \
      metal_print_long_long(__LINE__); \
      metal_print_string("\n  |-----> Expected: "#expected", evaluated as: \""); \
      metal_print_string(evaluated_expected); \
      metal_print_string("\"\n  |-----> Actual: "#actual", evaluated as: \""); \
      metal_print_string(evaluated_actual); \
      metal_print_string("\"\n  \\--> Test "); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      METAL_MAIN_TRAMPOLINE(); \
   } \
}

#define METAL_MAIN_TRAMPOLINE() { \
   metal_skip = 1; \
   goto metal_main; }

#endif
