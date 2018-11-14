/*
REDOTICA - Rede ótica
https://br.spoj.com/problems/REDOTICA/
*/

#include <bits/stdc++.h>

using namespace std;

struct edge {
    int from;
    int to;
    int distance;
};

vector<edge> generate_mst(int N, int M, vector<edge> &edges);
int uf_find(vector<int> &id, int p);
void uf_union(vector<int> &id, vector<int> &sz, int p, int q);

int main(void) {
    ios::sync_with_stdio(false);

    int N, M,
        i = 1;

    while (cin >> N >> M, N != 0) {
        vector<edge> edges;

        cout << "Teste " << i++ << '\n';

        for (int i = 0; i < M; i++) {
            int X, Y, Z;

            cin >> X >> Y >> Z;

            edges.push_back({ X, Y, Z });
        }

        auto mst = generate_mst(N, M, edges);

        for (auto &e : mst) {
            if (e.from < e.to) cout << e.from << ' ' << e.to << '\n';
            else cout << e.to << ' ' << e.from << '\n';
        }

        cout << '\n';
    }

    return EXIT_SUCCESS;
}

vector<edge> generate_mst(int N, int M, vector<edge> &edges) {
    vector<edge> mst;

    sort(edges.begin(), edges.end(), [] (edge &a, edge &b) {
        return a.distance < b.distance;
    });

    vector<int> id(N + 1), sz(N + 1);

    for (int i = 0; i < N + 1; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    for (auto &e : edges) {
        // cout << e.from << " " << e.to << " " << e.distance << endl;
        if (uf_find(id, e.from) != uf_find(id, e.to)) {
            uf_union(id, sz, e.from, e.to);
            mst.push_back(e);
        }
    }

    return mst;
}

int uf_find(vector<int> &id, int p) {
    if (id[p] == p) return p;
    return id[p] = uf_find(id, id[p]);
}

void uf_union(vector<int> &id, vector<int> &sz, int p, int q) {
    p = uf_find(id, p);
    q = uf_find(id, q);

    if (p == q) return;

    if (sz[p] > sz[q]) swap(p, q);
    
    id[p] = q;
    sz[q] += sz[p];
}