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
    int swaps = 0;

    for (int i = 0; i < N; i++) {
        while(perm[i] != i + 1) {
            int v = perm[i];
            perm[i] = perm[v - 1];
            perm[v - 1] = v;
            swaps++;
        }
    }

    if (swaps % 2 == 1) cout << "Marcelo\n";
    else cout << "Carlos\n";
}
