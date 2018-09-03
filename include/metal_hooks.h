#ifndef METAL_HOOKS_H
#define METAL_HOOKS_H

typedef enum metal_color {
   metal_no_color,
   metal_red,
   metal_yellow,
   metal_green
} metal_color;

void metal_print_string(const char *str, metal_color color);
void metal_print_long_double(long double value, metal_color color);
void metal_print_long_long(long long value, metal_color color);
void metal_print_hex(unsigned long long value, metal_color color);

#endif
