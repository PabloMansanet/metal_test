#include <stdio.h>

extern int tests_alpha(void);
extern int tests_beta(void);

int main(void)
{
  int total_tests_failed = 0;
  total_tests_failed += tests_alpha();
  total_tests_failed += tests_beta();

  printf("A total of %d tests have failed\n", total_tests_failed);
}
