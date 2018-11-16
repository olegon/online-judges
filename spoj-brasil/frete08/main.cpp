/*
FRETE08 - Frete da Família Silva
https://br.spoj.com/problems/FRETE08/
*/

#include <bits/stdc++.h>

using namespace std;

struct edge {
    int from;
    int to;
    int distance;
};

int uf_find(vector<int> &id, int p);
void uf_union(vector<int> &id, vector<int> &sz, int p, int q);

int main(void) {
    ios::sync_with_stdio(false);

    int N, M,
        total = 0;

    cin >> N >> M;

    vector<int> id(N), sz(N);
    for (int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    vector<edge> edges(M);
    for (auto &e : edges) {
        cin >> e.from >> e.to >> e.distance;
    }

    sort(edges.begin(), edges.end(), [] (edge &a, edge &b) -> bool {
        return a.distance < b.distance;
    });

    for (auto &e : edges) {
        if (uf_find(id, e.from) != uf_find(id, e.to)) {
            uf_union(id, sz, e.from, e.to);
            total += e.distance;
        }
    }
    
    cout << total << endl;

    return EXIT_SUCCESS;
}

int uf_find(vector<int> &id, int p) {
    if (id[p] == p) return p;
    else return id[p] = uf_find(id, id[p]);
}

void uf_union(vector<int> &id, vector<int> &sz, int p, int q) {
    p = uf_find(id, p);
    q = uf_find(id, q);

    if (p == q) return;

    if (sz[p] > sz[q]) swap(p, q);

    id[p] = q;
    sz[q] += sz[p];
}
