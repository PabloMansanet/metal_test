#ifndef ASSERT_MACROS_H
#define ASSERT_MACROS_H

#include "metal_hooks.h"

#define METAL_ASSERT(value) { \
   int metal_evaluated_value = (int)(value); \
   if ( metal_evaluated_value != 0) {  \
      metal_print_string("Assertion failure at "__FILE__":"); \
      metal_print_integer(__LINE__); \
      metal_print_string("\n"#value" evaluated as "); \
      metal_print_integer(metal_evaluated_value); \
      metal_print_string("\n"); \
   } \
}

//#define METAL_ASSERT_EQ(x,y) assert((x) == (y))

#endif
