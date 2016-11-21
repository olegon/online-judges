#include <iostream>
#include <vector>

using namespace std;

void play(vector<int> &perm, int N);

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

    for (int i = 1; i < N; i++) {
        for (int j = i; j > 0 && perm[j - 1] > perm[j]; j--) {
            vezDoMarcelo = !vezDoMarcelo;

            int c = perm[j - 1];
            perm[j - 1] = perm[j];
            perm[j] = c;
        }
    }

    if (vezDoMarcelo) cout << "Marcelo\n";
    else cout << "Carlos\n";
}
