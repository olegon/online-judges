/*
A Lenda de Flavious Josephus
https://www.urionlinejudge.com.br/judge/pt/problems/view/1030
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
  int posicao;
  struct pessoa *prox;
} Pessoa;

Pessoa* criarCirculo (int n);
void matarVizinho (Pessoa *pessoa);
void imprimir (const Pessoa *pessoa);
int resolverJosephus (int n, int m);

int main (void) {
  int NC,
      i;

  scanf("%d", &NC);

  for (i = 1; i <= NC; i++) {
    int N, M;

    scanf("%d %d", &N, &M);

    printf("Case %d: %d\n", i, resolverJosephus(N, M));
  }

  return EXIT_SUCCESS;
}

Pessoa* criarCirculo (int n) {
  Pessoa *primeiraPessoa, *pessoaPtr;
  int i;

  i = 1;

  primeiraPessoa = malloc(sizeof(Pessoa));
  primeiraPessoa->posicao = i++;

  for (pessoaPtr = primeiraPessoa; i <= n; i++) {
    pessoaPtr->prox = malloc(sizeof(Pessoa));
    pessoaPtr->prox->posicao = i;

    pessoaPtr = pessoaPtr->prox;
  }

  pessoaPtr->prox = primeiraPessoa;

  return primeiraPessoa;
}


void matarVizinho (Pessoa *pessoa) {
  Pessoa *pessoaQueVaiMorrer = pessoa->prox;

  pessoa->prox = pessoaQueVaiMorrer->prox;

  free(pessoaQueVaiMorrer);
}

void imprimir (const Pessoa *pessoa) {
  printf("Pessoa %3d\n", pessoa->posicao);
}

int resolverJosephus (int n, int m) {
  Pessoa *pessoaPtr;
  int i;

  pessoaPtr = criarCirculo(n);

  while (pessoaPtr->prox != pessoaPtr) {
    for (i = 1; i < m - 1; i++) pessoaPtr = pessoaPtr->prox;

    matarVizinho(pessoaPtr);

    pessoaPtr = pessoaPtr->prox;
  }

  i = pessoaPtr->posicao;

  free(pessoaPtr);

  return i;
}
