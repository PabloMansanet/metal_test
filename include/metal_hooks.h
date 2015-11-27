#ifndef METAL_HOOKS_H
#define METAL_HOOKS_H

void metal_print_string(const char *str);
void metal_print_long_double(long double value);
void metal_print_long_long(long long value);
void metal_print_unsigned_long_long(unsigned long long value);
void metal_print_hex(long long value);

int metal_strcmp (const char* str1, const char* str2);

#endif
