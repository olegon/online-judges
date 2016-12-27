/*
LED
https://www.urionlinejudge.com.br/judge/pt/problems/view/1168
*/

#include <stdio.h>

void processarLinha(void);
int processarCaractere(char caractere);

int main (void) {
  int quantidadeDeCasos, i;
  
  scanf("%d", &quantidadeDeCasos);
  
  for (i = 0; i < quantidadeDeCasos; i++) {
    processarLinha();
  }
  
  return 0;
}

void processarLinha() {
    char linha[128];
    int sum = 0,
        i = 0;
    
    scanf("%s", linha);
    
    while (linha[i] != '\0') {
      sum += processarCaractere(linha[i]);      
      i++;
    }
    
    printf("%d leds\n", sum);    
}

int processarCaractere(char caractere) {
  switch (caractere) {
    case '0': return 6;
    case '1': return 2;
    case '2': return 5;
    case '3': return 5;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 3;
    case '8': return 7;
    case '9': return 6;
    default: return 0;
  }
}
