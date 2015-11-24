#include "metal_test.h"

METAL_FIXTURE_DEFINE {
   unsigned int fixture_element;
};

METAL_SETUP {
   METAL_FIXTURE.fixture_element = 7;
};

METAL_TEARDOWN {};

METAL_SUITE {
   METAL_TEST(simple_test) {
      int test_value = 4;
      METAL_ASSERT(test_value);

      int expected_value = 8;
      METAL_ASSERT_EQ(expected_value, METAL_FIXTURE.fixture_element);
   };
};

