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

int metal_strlen(const char* str);
int metal_string_eq(const char* str1, const char* str2);

#endif
