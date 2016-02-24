#include "metal_test.h"

METAL_FIXTURE_DEFINE {};
METAL_FIXTURE_DECLARE;
METAL_SETUP {};
METAL_TEARDOWN {};

METAL_SUITE_BEGIN 
{
   METAL_TEST(comparing_chars)
   {
      char expected = 1;
      char actual   = 2;
      METAL_ASSERT_EQ(expected, actual);
   }

   METAL_TEST(comparing_long_longs)
   {
      long long expected = 1;
      long long actual   = 2;
      METAL_ASSERT_EQ(expected, actual);
   }

   METAL_TEST(comparing_unsigned_chars)
   {
      unsigned char expected = 1;
      unsigned char actual   = 2;
      METAL_ASSERT_EQ(expected, actual);
   }

   METAL_TEST(comparing_floats)
   {
      float expected = 1.0;
      float actual   = 2.0;
      METAL_ASSERT_EQ(expected, actual);
   }
   
   METAL_TEST(comparing_pointers)
   {
      void* expected = (void*)1;
      void* actual   = (void*)2;
      METAL_ASSERT_EQ(expected, actual);
   }
}
METAL_SUITE_END
