#ifndef TYPE_PUNNING_H
#define TYPE_PUNNING_H


#define METAL_PUN_STORE( expression, union_name ) \
metal_punning_union union_name = metal_generate_patterned_union(); \
union_name = (metal_punning_union)(expression); \

typedef union 
{
   float f;
   double d;
   long double ld;
   int i;
   unsigned int ui;
   unsigned long ul;
   unsigned long long ull;
   long l;
   long long ll;
   char c;
   unsigned char uc;
} metal_punning_union;

int metal_bitwise_compare(metal_punning_union* mpu1, metal_punning_union* mpu2)
{
   char* byte_handle_1 = (char*) mpu1;
   char* byte_handle_2 = (char*) mpu2;

   int are_equal = 1;   
   for (int i = 0; i< sizeof(metal_punning_union); i++) {
      if (*byte_handle_1 != *byte_handle_2) 
         are_equal = 0;
   }

   return are_equal;
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


   
#endif
