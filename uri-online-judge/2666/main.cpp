/*
Imposto Real
https://www.urionlinejudge.com.br/judge/pt/problems/view/2666
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int uint64;

struct graph_node {
    int index;
    int weight;
};

uint64 menor_custo(int N, int C, vector<int> &impostos_devidos, vector< list<graph_node> > &adj);
uint64 menor_custo(int i, int N, int C, vector<int> &impostos_devidos, vector< list<graph_node> > &adj, vector<bool> &visitados, vector<uint64> &cofres);

int main(void) {
    ios::sync_with_stdio(false);

    int N, C,
        A, B, DIST;

    cin >> N >> C;

    vector<int> impostos_devidos(N);
    vector< list<graph_node> > adj(N);

    for (int i = 0; i < N; i++) cin >> impostos_devidos[i];

    while (cin >> A >> B >> DIST) {
        adj[A - 1].push_back({ B - 1, DIST });
        adj[B - 1].push_back({ A - 1, DIST });
    }

    cout << menor_custo(N, C, impostos_devidos, adj) << endl;

    return EXIT_SUCCESS;
}

uint64 menor_custo(int N, int C, vector<int> &impostos_devidos, vector< list<graph_node> > &adj) {
    vector<bool> visitados(N, false);
    vector<uint64> cofres(N, 0);

    for (int i = 0; i < N; i++) cofres[i] = impostos_devidos[i];

    return menor_custo(0, N, C, impostos_devidos, adj, visitados, cofres);
}

uint64 menor_custo(int i, int N, int C, vector<int> &impostos_devidos, vector< list<graph_node> > &adj,
    vector<bool> &visitados, vector<uint64> &cofres) {

    visitados[i] = true;
    uint64 total = 0;

    for (auto gn : adj[i]) {
        if (!visitados[gn.index]) {
            total += menor_custo(gn.index, N, C, impostos_devidos, adj, visitados, cofres);
            total += ceil(1.0 * cofres[gn.index] / C) * 2 * gn.weight;
            cofres[i] += cofres[gn.index];
        }
    }
    
    return total;
}