#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 500

#define CIDADE(n) ((n) - 1)

void limparConexoes(int conexoes[][MAX_N], int N);
int obterNoComMenorDistancia(int *distancia, int *visitado, int N);
int calcularTempoDeEntrega(int conexoes[][MAX_N], int N, int origem, int destino);

int *cache[MAX_N];

int main (void) {
    int N, E,
        X, Y, H,
        K,
        O, D;

    int conexoes[MAX_N][MAX_N];

    while (scanf("%d %d", &N, &E), N != 0 || E != 0) {
        int i;

        limparConexoes(conexoes, N);

        for (i = 0; i < N; i++) {
            if (cache[i] != NULL) {
                free(cache[i]);
                cache[i] = NULL;
            }
        }

        for (i = 0; i < E; i++) {
            scanf("%d %d %d", &X, &Y, &H);

            if (conexoes[CIDADE(Y)][CIDADE(X)] < INT_MAX) {
                conexoes[CIDADE(X)][CIDADE(Y)] = conexoes[CIDADE(Y)][CIDADE(X)] = 0;
            }
            else {
                conexoes[CIDADE(X)][CIDADE(Y)] = H;
            }
        }

        scanf("%d", &K);

        for (i = 0; i < K; i++) {
            scanf("%d %d", &O, &D);

            int tempoParaSerEntregue = calcularTempoDeEntrega(conexoes, N, CIDADE(O), CIDADE(D));

            if (tempoParaSerEntregue == 0) {
                printf("0\n");
            }
            else if (tempoParaSerEntregue == INT_MAX) {
                printf("Nao e possivel entregar a carta\n");
            }
            else {
                printf("%d\n", tempoParaSerEntregue);
            }
        }

        printf("\n");
    }

    return 0;
}

void limparConexoes(int conexoes[][MAX_N], int N) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            conexoes[i][j] = INT_MAX;
        }
    }
}

int obterNoComMenorDistancia(int *distancia, int *visitado, int N) {
    int i,
        menorIndice = 0,
        menorValor = INT_MAX;

    for (i = 0; i < N; i++) {
      if (distancia[i] < menorValor && !visitado[i]) {
        menorIndice = i;
        menorValor = distancia[i];
      }
    }

    return menorIndice;
}



int calcularTempoDeEntrega(int conexoes[][MAX_N], int N, int origem, int destino) {
    if (conexoes[origem][destino] == 0) {
        return 0;
    }
    else if (cache[origem] != NULL) {
        return cache[origem][destino];
    }
    else {
        int i;

        int visitado[N];
        int *distancia = malloc(sizeof(int) * N);

        cache[origem] = distancia;

        for (i = 0; i < N; i++) {
          visitado[i] = 0;
          distancia[i] = INT_MAX;
        }

        distancia[origem] = 0;

        for (i = 0; i < N - 1; i++) {
          int noDestino,
              noOrigem = obterNoComMenorDistancia(distancia, visitado, N);

          visitado[noOrigem] = 1;

          for (noDestino = 0; noDestino < N; noDestino++) {
            if (!visitado[noDestino]
                && distancia[noOrigem] < INT_MAX
                && conexoes[noOrigem][noDestino] < INT_MAX
                && distancia[noOrigem] + conexoes[noOrigem][noDestino] < distancia[noDestino]) {
                  distancia[noDestino] = distancia[noOrigem] + conexoes[noOrigem][noDestino];
                }
          }
        }

        return distancia[destino];
    }
}
