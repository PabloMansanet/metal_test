#include "metal_test.h"

typedef struct {
   void* pointer;
   char array[32];
   unsigned int number;
} UserDefinedType;

METAL_FIXTURE_DEFINE {
   UserDefinedType testVariableAlpha;
   UserDefinedType testVariableBeta;
};
METAL_FIXTURE_DECLARE;
METAL_SETUP {
   METAL_FIXTURE.testVariableAlpha.array[7] = 3;
   METAL_FIXTURE.testVariableBeta.number = 5;
};
METAL_TEARDOWN {};

METAL_SUITE_BEGIN
{
   METAL_TEST(passing_mem_eq_test)
   {
      METAL_ASSERT_MEM_EQ(METAL_FIXTURE.testVariableAlpha, 
                          METAL_FIXTURE.testVariableBeta, 
                          2);
   }
   
   METAL_TEST(failing_mem_eq_test)
   {
      METAL_ASSERT_MEM_EQ(METAL_FIXTURE.testVariableAlpha, 
                          METAL_FIXTURE.testVariableBeta, 
                          sizeof(UserDefinedType));
   }
}
METAL_SUITE_END 
