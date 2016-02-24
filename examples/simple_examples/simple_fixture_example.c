#include "metal_test.h"

METAL_FIXTURE_DEFINE 
{
   int example_integer;
   float example_float;
};
METAL_FIXTURE_DECLARE;

METAL_SETUP 
{
   METAL_FIXTURE.example_integer = 7;
   METAL_FIXTURE.example_float = 5.5;
};

METAL_TEARDOWN {};

METAL_SUITE_BEGIN
{
   METAL_TEST(example_passing_test_with_fixture) 
   {
      METAL_ASSERT(METAL_FIXTURE.example_integer);

      volatile int expected_value = 7;
      METAL_ASSERT_EQ(expected_value, METAL_FIXTURE.example_integer);
      METAL_FIXTURE.example_integer = 0; //Irrelevant, since the fixture will be recreated between tests.
   };

   METAL_TEST(example_float_test) 
   {
      float expected_value = 8.8;
      METAL_ASSERT_EQ(expected_value, METAL_FIXTURE.example_float);
   }
   
   METAL_TEST(example_failing_test_with_fixture) 
   {
      int expected_value = 0;
      METAL_ASSERT_EQ(expected_value, METAL_FIXTURE.example_integer);
   }
} 
METAL_SUITE_END
