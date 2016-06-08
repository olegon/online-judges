#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CASAS_SIZE 1000000

int compare(const void *a, const void *b);

typedef struct {
  int pessoas;
  int consumo;
  int media;
} CASA;

CASA casas[CASAS_SIZE];

int main (void) {
  int n, i = 0;
  int numeroCidade = 1;
  int pessoas, consumo;
  int j;
  int somaDeConsumo;
  int somaDePessoas;
  double mediaFinal, mediaFinalArredonda;
  
  CASA *casaEncontrada;
  
  scanf("%d", &n);
  while (n != 0) {
    if (i > 0) printf("\n");
    
    printf("Cidade# %d:\n", numeroCidade++);
    
    somaDeConsumo = somaDePessoas = 0;
    
    for (i = 0; i < n; i++) {
      scanf("%d %d", &casas[i].pessoas, &casas[i].consumo);    
      casas[i].media = casas[i].consumo / casas[i].pessoas;
      
      somaDeConsumo += casas[i].consumo;
      somaDePessoas += casas[i].pessoas;
      
      if ((casaEncontrada = bsearch(&casas[i], casas, i, sizeof(CASA), compare)) != NULL) {
        casaEncontrada->consumo += casas[i].consumo;
        casaEncontrada->pessoas += casas[i].pessoas;
        
        i--;
        n--;
        
      }
      else {
        qsort(casas, i + 1, sizeof(CASA), compare);
      }      
    }
    
    
    
    for (i = 0; i < n; i++) {
      if (i > 0) printf(" ");
      printf("%d-%d", casas[i].pessoas, casas[i].media);
    }    
    printf("\n");
    
    mediaFinal = (double)somaDeConsumo / somaDePessoas;
    mediaFinalArredonda = ((int)(mediaFinal * pow(10, 2))) / pow(10, 2);
    
    printf("Consumo medio: %.2f m3.\n", mediaFinalArredonda);
    
    
    scanf("%d", &n);
  }
  
  
  return 0;
}

int compare(const void *a, const void *b) {
  int mediaA = (*(CASA*)a).media;
  int mediaB = (*(CASA*)b).media;
  
  if (mediaA < mediaB)      return -1;
  else if (mediaA == mediaB) return 0;
  else                      return 1;
}