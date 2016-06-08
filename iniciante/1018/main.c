#include <stdio.h>

int main (void) {
  int valor;
  int notas[] = { 100, 50, 20, 10, 5, 2, 1, 0};
  int notaIndex = 0;
  
  int quantidadeNotas;  
  
  scanf("%d", &valor);
  
  printf("%d\n", valor);
  
  while (notas[notaIndex] != 0) {
    quantidadeNotas = valor / notas[notaIndex];
    printf("%d nota(s) de R$ %d,00\n", quantidadeNotas, notas[notaIndex]);
    valor = valor % notas[notaIndex];
    
    notaIndex++;
  }
  
  return 0;
}
