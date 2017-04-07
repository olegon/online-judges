/*
Ir e Vir
https://www.urionlinejudge.com.br/judge/pt/problems/view/1128
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>

using namespace std;

bool conectividade(vector< vector<int> > &adj);

int main(void) {
    ios::sync_with_stdio(false);

    int N, M;
    
    while (cin >> N >> M, N != 0 || M != 0) {
        vector< vector<int> > adj(N);

        for (int i = 0; i < M; i++) {
            int V, W, P;

            cin >> V >> W >> P;

            switch (P) {
                case 2:
                    adj[W - 1].push_back(V - 1);
                case 1:
                     adj[V - 1].push_back(W - 1);
            }
        }

        // for (auto V : adj) {
        //     for (auto v : V) {
        //         cout << (v + 1) << " ";
        //     }
        //     cout << endl;
        // }

        // break;

        if (conectividade(adj)) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }

    return EXIT_SUCCESS;
}

bool conectividade(vector< vector<int> > &adj) {

    return true;
}
