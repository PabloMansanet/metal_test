#ifndef TYPE_PUNNING_H
#define TYPE_PUNNING_H

//TODO: Check endianness 
#define METAL_FILL_UNION(union_name, lvalue) { \
   char* lvalue_byte_handle = (char*)&lvalue; \
   char* union_byte_handle = (char*)&union_name; \
   unsigned int i; \
     for (i = 0; i < sizeof(metal_punning_union); i++) \
     { \
        union_byte_handle[i] = 0x00; \
     } \
     for (i = 0; i < sizeof(lvalue); i++) \
     { \
        union_byte_handle[i] = lvalue_byte_handle[i]; \
     } \
   }

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
