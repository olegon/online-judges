#include <iostream>
#include <vector>

using namespace std;

void play(vector<int> &perm, int N);

int mergesort_swaps(vector<int> &v);
int merge(vector<int> &v, int l, int m, int h);
int sort(vector<int> &v, int l, int h);

int main(void) {
    ios::sync_with_stdio(false);

    while (true) {
        int N;

        cin >> N;

        if (N == 0) break;
        else {
            vector<int> perm;

            for (int i = 0; i < N; i++) {
                int X;

                cin >> X;

                perm.push_back(X);
            }

            play(perm, N);
        }
    }

    return 0;
}

void play(vector<int> &perm, int N) {
    bool vezDoMarcelo;

    int swaps = mergesort_swaps(perm);

    if (swaps % 2 == 1) cout << "Marcelo\n";
    else cout << "Carlos\n";
}

int mergesort_swaps(vector<int> &v) {
    return sort(v, 0, v.size() - 1);
}

int merge(vector<int> &v, int l, int m, int h) {
    vector<int> c;
    int swaps = 0;

    for (int i = l; i <= h; i++) {
        c.push_back(v[i]);
    }

    for (int i = 1; i < c.size(); i++) {
        if (c[i - 1] > c[i]) swaps++;
    }

    int ll = l;
    int mm = m + 1;
    int i = l;

    while (ll <= m && mm <= h) {
        if (c[ll - l] < c[mm - l]) v[i++] = c[ll++ - l];
        else v[i++] = c[mm++ - l];
    }

    while (ll <= m) {
        v[i++] = c[ll++ - l];
    }

    while (mm <= h) {
        v[i++] = c[mm++ - l];
    }

    return swaps;
}

int sort(vector<int> &v, int l, int h) {
    if (l >= h) return 0;

    int m = (l + h) / 2;

    int swaps_a = sort(v, l, m);
    int swaps_b = sort(v, m + 1, h);

    // Otimização
    if (v[m] <= v[m + 1]) return swaps_a + swaps_b;

    int swaps_c = merge(v, l, m, h);

    return swaps_a + swaps_b + swaps_c;
}
