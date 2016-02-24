#include "metal_test.h"

METAL_FIXTURE_DEFINE {};
METAL_FIXTURE_DECLARE;
METAL_SETUP {};
METAL_TEARDOWN {};

METAL_TESTS_BEGIN(tests_beta)
{
  METAL_TEST(failing_test_in_file_beta)
  {
    METAL_ASSERT_TRUE(0);
  }
}
METAL_TESTS_END 
