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
   void* p;
} metal_punning_union;

int  metal_bitwise_compare(metal_punning_union* mpu1, metal_punning_union* mpu2);
void metal_interpret_and_print_ll(const char* prefix, long long value);
void metal_interpret_and_print_ld(const char* prefix, long double value);
void metal_report_possible_values(metal_punning_union* mpu);

   
#endif
