#ifndef TESTLITE_H
#define TESTLITE_H

#include "assert.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"

#define METAL_FIXTURE_DEFINE \
   struct _fixture_type; \
   static struct _fixture_type *_fixture = 0; \
   struct _fixture_type \

#define METAL_FIXTURE_SETUP \
   static void _fixture_setup(void) \

#define METAL_FIXTURE_TEARDOWN \
   static void _fixture_teardown(void) \

#define METAL_FIXTURE (*_fixture)

#define METAL_SUITE \
   static char* _current_test = 0; \
   int main(void)

#define METAL_TEST(test_name) \
   _current_test = #test_name; \
   if (_fixture) _fixture_teardown(); \
   if (_fixture) free(_fixture); \
   _fixture = malloc (sizeof(struct _fixture_type)); \
   memset(_fixture, 0, sizeof(struct _fixture_type)); \
   _fixture_setup();

#define METAL_ASSERT(value) assert(value)
#define METAL_ASSERT_EQ(x,y) assert((x) == (y))

#endif
