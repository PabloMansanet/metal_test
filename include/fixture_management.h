#ifndef FIXTURE_MANAGEMENT_H
#define FIXTURE_MANAGEMENT_H

struct _fixture_type;

#define _fixture_nuke() \
   { \
      char* raw_fixture = (char*) &_fixture; \
      for (unsigned int i = 0; i < sizeof(struct _fixture_type); i++) { \
         raw_fixture[i] = 0x00; \
      } \
   } \

#endif
