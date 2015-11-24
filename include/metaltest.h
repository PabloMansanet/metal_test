#ifndef TESTLITE_H
#define TESTLITE_H
      
#include "assert.h"
#include "fixture_management.h"



#define METAL_FIXTURE_DEFINE \
   static struct _fixture_type _fixture; \
   struct _fixture_type 

#define METAL_FIXTURE_SETUP \
   static void _fixture_setup(void) \

#define METAL_FIXTURE_TEARDOWN \
   static void _fixture_teardown(void) \

#define METAL_FIXTURE (_fixture)

#define METAL_SUITE \
   static char* _current_test = 0; \
   int main(void)

#define METAL_TEST(test_name) \
   _current_test = #test_name; \
   _fixture_teardown(); \
   _fixture_nuke(); \
   _fixture_setup();

#define METAL_ASSERT(value) assert(value)
#define METAL_ASSERT_EQ(x,y) assert((x) == (y))

#endif
