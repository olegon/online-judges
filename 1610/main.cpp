/*
Dudu Faz Serviço
https://www.urionlinejudge.com.br/judge/pt/problems/view/1610
*/

#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int T;

    cin >> T;
    while(T-- > 0) {
        int N, M;

        cin >> N >> M;

        for (int i = 0; i < M; i++) {
            int A, B;

            cin >> A >> B;

            cout << A << ' ' << B << '\n';
        }
    }

    return 0;
}
