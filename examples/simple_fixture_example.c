#include "metal_test.h"

METAL_FIXTURE_DEFINE {
   unsigned int example_integer;
};

METAL_SETUP {
   METAL_FIXTURE.example_integer = 7;
};

METAL_TEARDOWN {};

METAL_SUITE {
   METAL_TEST(simple_passing_test) {
      METAL_ASSERT(METAL_FIXTURE.example_integer);

      int expected_value = 7;
      METAL_ASSERT_EQ(expected_value, METAL_FIXTURE.example_integer);
   };

   METAL_TEST(simple_failing_test) {
      int expected_value = 0;
      METAL_ASSERT_EQ(expected_value, METAL_FIXTURE.example_integer);
   }
};

