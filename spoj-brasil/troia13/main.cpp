/*
TROIA13 - Famílias de Troia
https://br.spoj.com/problems/TROIA13/
*/

#include <bits/stdc++.h>

using namespace std;

int uf_find(vector<int> &id, int p);
void uf_union(vector<int> &id, vector<int> &sz, int p, int q, int &n);

int main(void) {
    ios::sync_with_stdio(false);

    int N, M,
        n;

    cin >> N >> M;
    n = N;

    vector<int> id(N), sz(N);

    for (int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < M; i++) {
        int P, Q;

        cin >> P >> Q;

        uf_union(id, sz, P - 1, Q - 1, n);
    }

    cout << n << endl;

    return EXIT_SUCCESS;
}

int uf_find(vector<int> &id, int p) {
    if (id[p] == p) return p;

    return id[p] = uf_find(id, id[p]);
}

void uf_union(vector<int> &id, vector<int> &sz, int p, int q, int &n) {
    p = uf_find(id, p);
    q = uf_find(id, q);

    if (p == q) return;

    n--;

    if (sz[p] > sz[q]) swap(p, q);

    id[p] = q;
    sz[q] += sz[p];
}
