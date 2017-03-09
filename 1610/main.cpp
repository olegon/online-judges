/*
Dudu Faz Serviço
https://www.urionlinejudge.com.br/judge/pt/problems/view/1610
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool checarCiclos(vector<list<int>> &adj);
bool checarCiclos(int origem, vector<list<int>> &adj, vector<bool> &visitado, vector<bool> &visitadoNoCaminho);

int main(void) {
    ios::sync_with_stdio(false);

    int T;

    cin >> T;
    while(T-- > 0) {
        int N, M;

        cin >> N >> M;

        vector<list<int>> adj(N);

        for (int i = 0; i < M; i++) {
            int A, B;

            cin >> A >> B;

            adj[A - 1].push_back(B - 1);
        }

        if (checarCiclos(adj)) {
            cout << "SIM\n";
        }
        else {
            cout << "NAO\n";
        }
    }

    return 0;
}

bool checarCiclos(vector<list<int>> &adj) {
    int N = adj.size();
    vector<bool> visitado(N);
    vector<bool> visitadoNoCaminho(N);
    
    for (int i = 0; i < N; i++) {
        if (checarCiclos(i, adj, visitado, visitadoNoCaminho)) return true;
    }

    return false;
}

bool checarCiclos(int origem, vector<list<int>> &adj, vector<bool> &visitado, vector<bool> &visitadoNoCaminho) {
    if (!visitado[origem]) {
        visitado[origem] = true;
        visitadoNoCaminho[origem] = true;

        for (auto destino : adj[origem]) {
            if (!visitado[destino] && checarCiclos(destino, adj, visitado, visitadoNoCaminho)) return true;
            else if (visitadoNoCaminho[destino]) return true;
        }      

        visitadoNoCaminho[origem] = false;
    }
    
    return false;
}