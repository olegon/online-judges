#include <iostream>
#include <vector>

using namespace std;

int main (void) {
    size_t  T,
            N, M;

    vector<size_t> blocos;

    cin >> T;

    while (T-- > 0) {
        cin >> N >> M;

        blocos.clear();

        for (size_t i = 0; i < N; i++) {
            int bloco;

            cin >> bloco;

            blocos.push_back(bloco);
        }

        int dp[M + 1];

        dp[0] = 0;

        for (size_t i = 1; i <= M; i++) {
            dp[i] = M + 1;

            for (size_t j = 0; j < blocos.size() && blocos[j] <= i; j++) {
                if (dp[i - blocos[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - blocos[j]] + 1;
                }
            }

            // cout << i << " -> " << dp[i] << " blocos" << endl;
        }

        cout << dp[M] << endl;
    }


    return 0;
}
