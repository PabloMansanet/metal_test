#include "metal_test.h"

int metal_strlen(const char* str)
{
	const char *s;
	for (s = str; *s; ++s);
	return (s - str);
}

int metal_string_eq(const char* str1, const char* str2)
{
   int size = metal_strlen(str1);
   if (size != metal_strlen(str2))
      return 0;

   for (int i = 0; i < size; i++) {
      if (str1[i] != str2[i]) 
         return 0;
   }

   return 1;
}

int metal_bitwise_compare(metal_punning_union* mpu1, metal_punning_union* mpu2)
{
   char* byte_handle_1 = (char*) mpu1;
   char* byte_handle_2 = (char*) mpu2;

   for (int i = 0; i< sizeof(metal_punning_union); i++) {
      if (byte_handle_1[i] != byte_handle_2[i]) 
         return 0;
   }
   return 1;
}

void metal_interpret_and_print_ll(const char* prefix, long long value) 
{
   metal_print_string(prefix);
   metal_print_long_long(value);
   metal_print_string("]");
}

void metal_interpret_and_print_ld(const char* prefix, long double value)
{
   metal_print_string(prefix);
   metal_print_long_double(value);
   metal_print_string("]");
}

void metal_report_possible_values(metal_punning_union* mpu) 
{
   metal_print_string(          "\n  |      \\->Interpretations: ");
   metal_interpret_and_print_ll("\n  |           [char:               ",mpu->c);
   metal_interpret_and_print_ll("\n  |           [int:                ",mpu->i);
   metal_interpret_and_print_ll("\n  |           [long:               ",mpu->l);
   metal_interpret_and_print_ll("\n  |           [long long:          ",mpu->ll);
   metal_interpret_and_print_ll("\n  |           [unsigned char:      ",mpu->uc);
   metal_interpret_and_print_ll("\n  |           [unsigned int:       ",mpu->ui);
   metal_interpret_and_print_ll("\n  |           [unsigned long:      ",mpu->ul);
   metal_interpret_and_print_ld("\n  |           [float:              ",mpu->f);
   metal_interpret_and_print_ld("\n  |           [double:             ",mpu->d);
   metal_interpret_and_print_ld("\n  |           [long double:        ",mpu->ld);
}
