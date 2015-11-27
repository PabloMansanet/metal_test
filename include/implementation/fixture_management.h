#ifndef FIXTURE_MANAGEMENT_H
#define FIXTURE_MANAGEMENT_H

struct metal_fixture_type;

#define metal_fixture_nuke() \
   { \
      char* raw_fixture = (char*) &metal_fixture; \
      for (unsigned int i = 0; i < sizeof(struct metal_fixture_type); i++) { \
         raw_fixture[i] = 0x00; \
      } \
   } \

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

#endif
