#include "metal_test.h"

METAL_FIXTURE_DEFINE {};
METAL_SETUP {};
METAL_TEARDOWN {};

METAL_SUITE {
   METAL_TEST(simple_failing_test) {
      METAL_ASSERT(0);
   }
};
