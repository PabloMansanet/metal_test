#include "metal_test.h"
#include "application.h"
#include "fixture.h"

METAL_FIXTURE_DECLARE;
METAL_SETUP {};
METAL_TEARDOWN {};

METAL_SUITE_BEGIN
{
   METAL_TEST(running_the_application_initializes_the_module)
   {
      // When
      ApplicationRun();

      // Then
      int expected = 1;
      METAL_ASSERT_EQ(expected, METAL_FIXTURE.timesModuleInitCalled);
   }

   METAL_TEST(failing_test_as_sanity_check_that_fixture_is_reset_between_tests)
   {
      // Will fail, this should've been reset
      int expected = 1;
      METAL_ASSERT_EQ(expected, METAL_FIXTURE.timesModuleInitCalled);

      // This assert is never reached
      expected = 0;
      METAL_ASSERT(expected);
   }

}
METAL_SUITE_END
