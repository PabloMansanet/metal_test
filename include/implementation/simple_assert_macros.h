#ifndef SIMPLE_ASSERT_MACROS_H
#define SIMPLE_ASSERT_MACROS_H

#define METAL_ASSERT(value) { \
   int metal_evaluated_value = (long)(value); \
   if ( metal_evaluated_value == 0) {  \
      metal_print_string("Assertion failure at test: "); \
      metal_print_string(metal_current_test); \
      metal_print_string("\n"#value" evaluated as "); \
      metal_print_long(metal_evaluated_value); \
      metal_print_string("\nTest failed!\n"); \
      metal_crash(); \
   } \
}

#define METAL_ASSERT_EQ(expected, actual) { \
   long metal_evaluated_expected = (long)(expected); \
   long metal_evaluated_actual   = (long)(actual); \
   if (metal_evaluated_expected != metal_evaluated_actual) { \
      metal_print_string("Assertion failure at test: "); \
      metal_print_string(metal_current_test); \
      metal_print_string("\nExpected: "#expected", evaluated as "); \
      metal_print_long(metal_evaluated_expected); \
      metal_print_string("\nActual: "#actual", evaluated as "); \
      metal_print_long(metal_evaluated_actual); \
      metal_print_string("\nTest failed!\n"); \
      metal_crash(); \
   } \
}

#endif
