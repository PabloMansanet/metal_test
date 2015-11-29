#include "module.h"
#include "metal_test.h"
#include "fixture.h"

METAL_FIXTURE_EXTERN;

void ModuleInit(void) 
{
   METAL_FIXTURE.timesModuleInitCalled++;
}
