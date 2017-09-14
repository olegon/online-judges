/*
Dudu Faz Serviço
https://www.urionlinejudge.com.br/judge/pt/problems/view/1610
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

bool possuiCiclo(int origem, const vector< vector<int> > &adj, vector<bool> &visitados_globalmente,
    vector<bool> &visitados_locamente);

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    while (N-- > 0) {
        int M, N;
        
        cin >> M >> N;

        vector< vector<int> > adj(M);
        vector<bool> visitados_globalmente(M, false), visitados_localmente(M, false);

        for (int i = 0; i < N; i++) {
            int origem, destino;

            cin >> origem >> destino;

            adj[origem - 1].push_back(destino - 1);
        }

        bool cicloEncontrado = false;
        for (int origem = 0; !cicloEncontrado && origem < M; origem++) {
            cicloEncontrado = possuiCiclo(origem, adj, visitados_globalmente, visitados_localmente);
        }

        if (cicloEncontrado) cout << "SIM" << endl;
        else cout << "NAO" << endl;
    }

    return EXIT_SUCCESS;
}

bool possuiCiclo(int origem, const vector< vector<int> > &adj, vector<bool> &visitados_globalmente, vector<bool> &visitados_localmente) {
    if (visitados_localmente[origem]) return true;
    if (visitados_globalmente[origem]) return false;

    visitados_globalmente[origem] = true;
    visitados_localmente[origem] = true;

    for (auto destino : adj[origem]) {
        if (possuiCiclo(destino, adj, visitados_globalmente, visitados_localmente)) return true;
    }

    visitados_localmente[origem] = false;

    return false;
}
