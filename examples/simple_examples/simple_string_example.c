
#include "metal_test.h"

METAL_FIXTURE_DEFINE {
   const char* example_string;
};
METAL_FIXTURE_DECLARE;

METAL_SETUP {
   METAL_FIXTURE.example_string = "Hello";
};
METAL_TEARDOWN {};

METAL_SUITE_BEGIN
{
   METAL_TEST(example_string_passing_test)
   {
      METAL_ASSERT_STR_EQ("Hello", METAL_FIXTURE.example_string);
   }

   METAL_TEST(example_string_failing_test) 
   {
      METAL_ASSERT_STR_EQ("World", METAL_FIXTURE.example_string);
   }
}
METAL_SUITE_END 
