#include "stdio.h"
#include "string.h"

void metal_print_string(const char *str) {
   printf("%s",str);
}

void metal_print_long(long value) {
   printf("%ld",value);
}

void metal_print_double(double value) {
   printf("%f",value);
}

int metal_strcmp (const char* str1, const char* str2) {
   return strcmp(str1, str2);
}
