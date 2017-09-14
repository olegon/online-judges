/*
DFSr - Hierarquia de Profundidade
https://www.urionlinejudge.com.br/judge/pt/problems/view/1081
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>

using namespace std;

void printProfundide(int size);
void printGraph(vector<set<int>> &adj);
void printGraph(int origem, vector<set<int>> &adj, vector<bool> &visitado, int profundidade);

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cout << "Caso " << i << ":\n";

        int V, E;
        
        cin >> V >> E;

        vector<set<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int A, B;

            cin >> A >> B;

            adj[A].insert(B);
        }



        printGraph(adj);
    }

    return EXIT_SUCCESS;
}

void printGraph(vector<set<int>> &adj) {
    vector<bool> visitado(adj.size(), false);

    for (int i = 0; i < adj.size(); i++) {
        if (!visitado[i] && !adj[i].empty()) {
            printGraph(i, adj, visitado, 0);       
            cout << '\n';
        }
    }
}

void printGraph(int origem, vector<set<int>> &adj, vector<bool> &visitado, int profundidade) {
    if (!visitado[origem]) {
        visitado[origem] = true;

        for (int destino : adj[origem]) {
            printProfundide(profundidade);
            if (!visitado[destino]) cout << origem << "-" << destino << " pathR(G," << destino << ")\n";
            else cout << origem << "-" << destino << "\n";
            printGraph(destino, adj, visitado, profundidade + 1);
        }       
    }
}

void printProfundide(int size) {
    cout << "  ";
    if (size > 0) printProfundide(size - 1);
}