#ifndef ASSERT_MACROS_H
#define ASSERT_MACROS_H

#define METAL_ASSERT(value) { \
   int metal_evaluated_value = (long)(value); \
   if ( metal_evaluated_value == 0) {  \
      metal_print_string("  *-- Assertion failure at "__FILE__":"); \
      metal_print_long(__LINE__); \
      metal_print_string("\n  |    \\---> "#value" evaluated as false."); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      metal_crash(); \
   } \
}

#define METAL_ASSERT_EQ(expected, actual) { \
   void* metal_evaluated_expected = (void*)(expected); \
   void* metal_evaluated_actual   = (void*) (actual); \
   if (metal_evaluated_expected != metal_evaluated_actual) { \
      metal_print_string("  *-- Assertion failure at "__FILE__":"); \
      metal_print_long(__LINE__); \
      metal_print_string("\n  |   |\\---> Expected: "#expected", evaluated as "); \
      metal_print_long(metal_evaluated_expected); \
      metal_print_string("\n  |   \\------> Actual: "#actual", evaluated as "); \
      metal_print_long(metal_evaluated_actual); \
      metal_print_string("\n  \\-> Test "); \
      metal_print_string(metal_current_test); \
      metal_print_string(" failed!\n"); \
      metal_crash(); \
   } \
}

#define METAL_MAIN_TRAMPOLINE() { \
   metal_skip = 1; \
   goto main; 

#endif
