#include <stdio.h>

int main (void) {
  double n1, n2, n3, n4;
  double media;
  
  scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
  
  media = n1 * 0.2 + n2 * 0.3 + n3 * 0.4 + n4 * 0.1;
  
  printf("Media: %.1f\n", media);
  
  if (media < 5.0) {
    printf("Aluno reprovado.\n");
  }
  else if (media < 7.0) {
    printf("Aluno em exame.\n");
    fflush(stdout);
    double exame;
    double mediaFinal;
    scanf("%lf", &exame);
    
    printf("Nota do exame: %.1f\n", exame);
    
    mediaFinal = media * 0.5 + exame * 0.5;
    
    if (mediaFinal < 5.0) {
      printf("Aluno reprovado.\n");
      printf("Media final: %.1f\n", mediaFinal);
    }
    else {
      printf("Aluno aprovado.\n");
      printf("Media final: %.1f\n", mediaFinal);
    }

  }
  else {
    printf("Aluno aprovado.\n");
  }
  
  
  return 0;
}
