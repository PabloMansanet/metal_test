#include <stdio.h>
#include "metal_hooks.h"

static const char* metal_color_code(metal_color color) {
	switch(color) {
   	case metal_red:		return "\033[0;31m";
    case metal_green: 	return "\033[0;32m";
    case metal_yellow: 	return "\033[0;33m";
   	default: 			return "\033[0;0m";
	}
}

void metal_print_string(const char *str, metal_color color) { 
   	printf("%s%s\033[0;0m", metal_color_code(color), str);
}

void metal_print_long_long(long long value, metal_color color) {
   	printf("%s%lld\033[0;0m", metal_color_code(color), value);
}

void metal_print_long_double(long double value, metal_color color) {
   	printf("%s%Lf\033[0;0m", metal_color_code(color), value);
}

void metal_print_hex(unsigned long long value, metal_color color) {
   	printf("%s%Lx\033[0;0m", metal_color_code(color), value);
}