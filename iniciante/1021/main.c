#include <stdio.h>

int main (void) {
  double valor;
  int i;
  
  int reais;
  int centavos;
  
  int cedulas[] = { 100, 50, 20, 10, 5, 2, 0 };
  int moedas[] = { 100, 50, 25, 10, 5, 1, 0 };
  
  scanf("%lf", &valor);
  
  reais = (int)valor;
  centavos = (valor - reais) * 100;

  
  printf("NOTAS:\n");
  i = 0;
  while (cedulas[i] != 0) {
    printf("%d nota(s) de R$ %d.00\n", reais / cedulas[i], cedulas[i]);
    
    reais = reais % cedulas[i];
    
    i++;
  }
  
  centavos += reais * 100;
  printf("MOEDAS:\n");
  i = 0;
  while (moedas[i] != 0) {
    printf("%d moeda(s) de R$ %.2f\n", centavos / moedas[i], moedas[i] / 100.0);
    
    centavos = centavos % moedas[i];
    
    i++;
  }
  
  return 0;
}
