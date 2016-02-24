#include "metal_test.h"

METAL_FIXTURE_DEFINE {};
METAL_FIXTURE_DECLARE;
METAL_SETUP {};
METAL_TEARDOWN {};

METAL_TESTS_BEGIN(tests_alpha)
{
  METAL_TEST(passing_test_in_file_alpha)
  {
    METAL_ASSERT_TRUE(true);
  }
}
METAL_SUITE_END 
