#include "stdio.h"

void metal_print_string(const char *str) {
   printf("%s",str);
}

void metal_print_long_long(long long value) {
   long conv = (long)value;
   printf("%ld",conv);
}

void metal_print_long_double(long double value) {
double conv = (double)value;
   printf("%f",conv);
}

void metal_print_hex(unsigned long long value) {
	long conv = (long)value;
    printf("%lx",conv);
}

