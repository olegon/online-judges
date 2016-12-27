/*
Biblioteca Pascal
https://www.urionlinejudge.com.br/judge/pt/problems/view/1267
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N, D;
    while (cin >> N >> D, N != 0 || D != 0) {
        vector<int> alunos(N, 1);
        bool valido = false;

        for (int i = 0; i < D; i++) {
            for (int j = 0; j < N; j++) {
                int A;

                cin >> A;

                alunos[j] = alunos[j] & A;

                if (i == D - 1 && alunos[j] == 1) valido = true;
            }
        }

        if (valido) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
