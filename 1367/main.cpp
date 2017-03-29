/*
Ajude!
https://www.urionlinejudge.com.br/judge/pt/problems/view/1367
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

#define PENALIDADE 20

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N >> ws, N != 0) {
        int acertos = 0;
        int total = 0;
        vector<int> totalPenalidadePorProblema('Z' - 'A' + 1, 0);


        for (int i = 0; i < N; i++) {
            char problema;
            int tempo;
            string status;

            cin >> problema >> tempo >> status >> ws;

            if (status == "correct") {
                acertos += 1;
                total += tempo + totalPenalidadePorProblema[problema - 'A'];
                totalPenalidadePorProblema[problema - 'A'] = 0;
            }
            else totalPenalidadePorProblema[problema - 'A'] += PENALIDADE;
        }

        cout << acertos << " " << total << '\n';
    }

    return EXIT_SUCCESS;
}
