/*
Imposto Real
https://www.urionlinejudge.com.br/judge/pt/problems/view/2666
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int uint64;

uint64 menor_custo(int N, int C, vector<int> &impostos_devidos, vector< vector<int> > &adj);
uint64 menor_custo(int i, int N, int C, vector<int> &impostos_devidos, vector< vector<int> > &adj, vector<bool> &visitados, vector<uint64> &cofres);

int main(void) {
    ios::sync_with_stdio(false);

    int N, C,
        A, B, DIST;

    cin >> N >> C;

    vector<int> impostos_devidos(N);
    vector< vector<int> > adj(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) cin >> impostos_devidos[i];

    while (cin >> A >> B >> DIST) {
        adj[A - 1][B - 1] = adj[B - 1][A - 1] = DIST;
    }

    cout << menor_custo(N, C, impostos_devidos, adj) << endl;

    return EXIT_SUCCESS;
}

uint64 menor_custo(int N, int C, vector<int> &impostos_devidos, vector< vector<int> > &adj) {
    vector<bool> visitados(N, false);
    vector<uint64> cofres(N, 0);

    for (int i = 0; i < N; i++) cofres[i] = impostos_devidos[i];

    return menor_custo(0, N, C, impostos_devidos, adj, visitados, cofres);
}

uint64 menor_custo(int i, int N, int C, vector<int> &impostos_devidos, vector< vector<int> > &adj, vector<bool> &visitados, vector<uint64> &cofres) {
    visitados[i] = true;
    uint64 total = 0;

    for (int j = 0; j < N; j++) {
        if (adj[i][j] > 0 && !visitados[j]) {
            total += menor_custo(j, N, C, impostos_devidos, adj, visitados, cofres);
            cofres[i] += cofres[j];
            total += ceil(1.0 * cofres[j] / C) * 2 * adj[i][j];
        }
    }
    
    return total;
}