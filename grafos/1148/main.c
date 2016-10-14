#include <stdio.h>
#include <limits.h>

#define MAX_N 500

#define CIDADE(n) ((n) - 1)

typedef struct {
    int VALUES[MAX_N];
    int capacity;
    int head;
    int tail;
} FILA;

void limparConexoes(int conexoes[][MAX_N], int N);
int possuiConexaoDireta(int conexoes[][MAX_N], int o, int d);
int minDistance(int dist[], int visited[], int N);
int calcularTempoDeEntrega(int conexoes[][MAX_N], int N, int o, int d);

int main (void) {
    int N, E,
        X, Y, H,
        K,
        O, D;

    int conexoes[MAX_N][MAX_N];

    while (scanf("%d %d", &N, &E), N != 0 || E != 0) {
        int i;

        limparConexoes(conexoes, N);

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

int minDistance(int dist[], int visited[], int N) {
    int min = INT_MAX,
        min_index,
        v;

    for (v = 0; v < N; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

int calcularTempoDeEntrega(int conexoes[][MAX_N], int N, int o, int d) {
    if (conexoes[o][d] == 0) {
        return 0;
    }
    else {
        int dist[N],
            visited[N],
            i;

        for (i = 0; i < N; i++) {
            dist[i] = INT_MAX;
            visited[i] = 0;
        }

        dist[o] = 0;

        for (i = 0; i < N - 1; i++) {
            int u, v;

            u = minDistance(dist, visited, N);

            visited[u] = 1;

            for (v = 0; v < N; v++) {
                if (!visited[v]
                    && conexoes[u][v] != INT_MAX
                    && dist[u] != INT_MAX
                    && dist[u] + conexoes[u][v] < dist[v])
                   dist[v] = dist[u] + conexoes[u][v];
            }
        }

        return dist[d];
    }
}
