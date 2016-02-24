#include "module.h"
#include "metal_test.h"
#include "fixture.h"

void ModuleInit(void) 
{
   METAL_FIXTURE.timesModuleInitCalled++;
}
