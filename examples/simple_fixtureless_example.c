#include "metal_test.h"

METAL_FIXTURE_DEFINE {};
METAL_SETUP {};
METAL_TEARDOWN {};

METAL_SUITE {
   METAL_TEST(example_passing_test){
      int test_value = 1;
      METAL_ASSERT(test_value);
   }

   METAL_TEST(example_failing_test) {
      int test_value = 0;
      METAL_ASSERT(test_value);
      METAL_ASSERT(test_value);
   }

   METAL_TEST(example_second_failing_test) {
      METAL_ASSERT_EQ(5,0);
   }
};
