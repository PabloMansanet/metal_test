#ifndef ASSERT_MACROS_H
#define ASSERT_MACROS_H

#include "type_punning.h"

#define METAL_ASSERT(value) { \
   int metal_evaluated_value = (value); \
   if ( metal_evaluated_value == 0) {  \
      metal_print_string("  *-- Assertion failure at "__FILE__":"); \
      metal_print_long(__LINE__); \
      metal_print_string("\n       \\---> "#value" evaluated as false."); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      METAL_MAIN_TRAMPOLINE(); \
   } \
}

#define METAL_ASSERT_EQ(expected, actual) { \
   metal_punning_union evaluated_expected_value = (metal_punning_union)(expected); \
   metal_punning_union evaluated_actual_value = (metal_punning_union)(actual); \
   if (!metal_bitwise_compare(&evaluated_expected_value, &evaluated_actual_value)) { \
      metal_print_string("  *-- Assertion failure at "__FILE__":"); \
      metal_print_long(__LINE__); \
      metal_print_string("\n  |   |\\---> Expected: "#expected", evaluated as "); \
      metal_report_possible_values(&evaluated_expected_value); \
      metal_print_string("\n  |   \\---->   Actual: "#actual", evaluated as "); \
      metal_report_possible_values(&evaluated_actual_value); \
      metal_print_string("\n  \\-> Test "); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      METAL_MAIN_TRAMPOLINE(); \
   } \
}

#define METAL_MAIN_TRAMPOLINE() { \
   metal_skip = 1; \
   goto metal_main; }

#endif
