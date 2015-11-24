#include "metaltest.h"

METAL_FIXTURE_DEFINE {
   unsigned int fixture_element;
};

METAL_FIXTURE_SETUP {
   METAL_FIXTURE.fixture_element = 7;
};

METAL_FIXTURE_TEARDOWN {};

METAL_SUITE {
   METAL_TEST(simple_test) {
      METAL_ASSERT_EQ(METAL_FIXTURE.fixture_element, 8);
   };
};

