#ifndef TYPE_PUNNING_H
#define TYPE_PUNNING_H


#define METAL_PUN_STORE( expression, union_name ) \
metal_punning_union union_name = metal_generate_patterned_union(); \
union_name = (metal_punning_union)(expression); \

typedef union 
{
   float f;
   double d;
   int i;
   unsigned int ui;
   unsigned long ul;
   unsigned long long ull;
   long l;
   long long ll;
   char c;
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

void metal_report_possible_values(metal_punning_union* mpu) 
{
      metal_print_string("\n  |      \\->Interpretations: ");
      metal_print_string("\n  |           [Integer: ");
      metal_print_long_long(mpu->ll);
      metal_print_string("], ");
      metal_print_string("\n  |           [Floating Point: ");
      metal_print_double(mpu->f);
      metal_print_string("], ");
}


   
#endif
