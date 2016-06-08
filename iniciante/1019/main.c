#include <stdio.h>

int main (void) {
  int segundos;
  int medidas[] = { 3600, 60, 1, 0 };
  int i = 0;
  
  scanf("%d", &segundos);
  
  while (medidas[i] != 0) {
    if (i != 0) printf(":");
    
    printf("%d", segundos / medidas[i]);
    segundos = segundos % medidas[i];
    
    i++;
  } 
  
  printf("\n");
  
  return 0;
}
