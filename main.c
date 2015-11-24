#include "metaltest.h"

METAL_FIXTURE_DEFINE {
   unsigned int fixture_element;
};

METAL_FIXTURE_SETUP {
   TL_FIXTURE.fixture_element = 7;
};

METAL_FIXTURE_TEARDOWN {};

METAL_SUITE {
   TL_TEST(simple_test) {
      TL_ASSERT_EQ(TL_FIXTURE.fixture_element, 8);
   };
};

