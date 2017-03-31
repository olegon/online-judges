/*
Plano de Dieta
https://www.urionlinejudge.com.br/judge/pt/problems/view/1248
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

enum SITUACAO {
    NAO_PODE_COMER,
    PODE_COMER,
    COMEU
};

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N >> ws;

    while (N-- > 0) {
        vector<SITUACAO> comidas('Z' - 'A' + 1, NAO_PODE_COMER);
        string line;
        bool cheater = false;

        getline(cin, line);
        for (char c : line) {
            comidas[c - 'A'] = PODE_COMER;
        }

        getline(cin, line);
        for (char c : line) {
            if (comidas[c - 'A'] == PODE_COMER) comidas[c - 'A'] = COMEU;
            else cheater = true;
        }

        getline(cin, line);
        for (char c : line) {
            if (comidas[c - 'A'] == PODE_COMER) comidas[c - 'A'] = COMEU;
            else cheater = true;
        }

        if (cheater) {
            cout << "CHEATER\n";
        }
        else {
            for (size_t i = 0; i < comidas.size(); i++) {
                if (comidas[i] == PODE_COMER) cout << char('A' + i);
            }
            cout << '\n';
        }
    }



    return EXIT_SUCCESS;
}
