#include "stdio.h"
#include "string.h"

void metal_print_string(const char *str) {
   printf("%s",str);
}

void metal_print_long_long(long long value) {
   printf("%lld",value);
}

void metal_print_unsigned_long_long(unsigned long long value) {
}

void metal_print_long_double(long double value) {
   printf("%Lf",value);
}

void metal_print_hex(unsigned long long value) {
   printf("%llx",value);
}

int metal_strcmp (const char* str1, const char* str2) {
   return strcmp(str1, str2);
}
