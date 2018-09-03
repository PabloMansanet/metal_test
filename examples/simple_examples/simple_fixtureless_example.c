#include "metal_test.h"

METAL_FIXTURE_DEFINE {};
METAL_FIXTURE_DECLARE;
METAL_SETUP {};
METAL_TEARDOWN {};

METAL_SUITE_BEGIN
{
   METAL_TEST(example_passing_test)
   {
      int test_value = 1;
      METAL_ASSERT(test_value);
   }

   METAL_TEST(example_failing_test) 
   {
      int test_value = 0;
      METAL_ASSERT(test_value);
      METAL_ASSERT(test_value);
   }

   METAL_TEST(example_second_failing_test) 
   {
      int expected = -5;
      int actual = 0;
      METAL_ASSERT_EQ(expected, actual);
   }

   METAL_TEST(example_third_failing_test) 
   {
      int expected = 1;
      METAL_ASSERT_FALSE(expected);
   }
}
METAL_SUITE_END 
