#include <stdio.h>

int main (void) {
  int nc, i;
  int n, k;
  
  scanf("%d", &nc);
  
  for (i = 0; i < nc; i++) {      
    scanf("%d %d", &n, &k);

    printf("Case %d: %d\n", i + 1, calc(n, k));
    fflush(stdout);
  } 

  return 0;
}

int calc(int n, int k)
{
  if (n == 1)
    return 1;
  else
    return ((calc(n - 1, k) + k - 1) % n) + 1;
}
