#include "stdio.h"

void metal_print_string(const char *str) {
   printf("%s",str);
}

void metal_print_long(long value) {
   printf("%ld",value);
}

void metal_crash(void) {
   while (1);
}
