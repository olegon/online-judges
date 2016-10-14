#include <iostream>
#include <climits>
#include <queue>

using namespace std;

#define MAX_N 500

#define CIDADE(n) ((n) - 1)

void limparConexoes(int conexoes[][MAX_N], int N);
int possuiConexaoDireta(int conexoes[][MAX_N], int o, int d);
int calcularTempoDeEntrega(int conexoes[][MAX_N], int o, int d, int N);

int main (void) {
    int N, E,
        X, Y, H,
        K,
        O, D;

    int conexoes[MAX_N][MAX_N];

    while (cin >> N >> E, N != 0 || E != 0) {
        limparConexoes(conexoes, N);

        for (int i = 0; i < E; i++) {
            cin >> X >> Y >> H;

            if (conexoes[CIDADE(Y)][CIDADE(X)] < INT_MAX) {
                conexoes[CIDADE(X)][CIDADE(Y)] = conexoes[CIDADE(Y)][CIDADE(X)] = 0;
            }
            else {
                conexoes[CIDADE(X)][CIDADE(Y)] = H;
            }
        }

        cin >> K;

        for (int i = 0; i < K; i++) {
            cin >> O >> D;

            int tempoParaSerEntregue = calcularTempoDeEntrega(conexoes, CIDADE(O), CIDADE(D), N);

            if (tempoParaSerEntregue == 0) {
                cout << "0" << endl;
            }
            else if (tempoParaSerEntregue == INT_MAX) {
                cout << "Nao e possivel entregar a carta" << endl;
            }
            else {
                cout << tempoParaSerEntregue << endl;
            }
        }

        cout << endl;
    }

    return 0;
}

void limparConexoes(int conexoes[][MAX_N], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            conexoes[i][j] = INT_MAX;
        }
    }
}

int calcularTempoDeEntrega(int conexoes[][MAX_N], int o, int d, int N) {
    if (conexoes[o][d] < INT_MAX) {
        return conexoes[o][d];
    }
    else {
        int cache[N];
        int visited[N];

        for (int i = 0; i < N; i++) {
            cache[i] = INT_MAX;
            visited[i] = 0;
        }

        queue<int> nodes;
        nodes.push(o);

        cache[o] = 0;
        visited[o] = 1;

        while (!nodes.empty()) {
            int from = nodes.front();
            nodes.pop();

            for (int to = 0; to < N; to++) {
                if (conexoes[from][to] < INT_MAX && !visited[to]) {
                    nodes.push(to);
                    visited[to] = 1;
                }
            }

        }

        return INT_MAX;
    }
}
