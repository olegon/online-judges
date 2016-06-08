#include <stdio.h>

int main (void) {
  unsigned int a, b;

  while (scanf("%u %u", &a, &b) != EOF) {
    // xor
    printf("%u\n", a ^ b);
  }

  return 0;
}
