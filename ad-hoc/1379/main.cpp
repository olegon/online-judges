/*
Problema com Mediana e Média
https://www.urionlinejudge.com.br/judge/pt/problems/view/1379
*/

#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int A, B;

    while (cin >> A >> B, A != 0 || B != 0) {
        if (A > B) {
            int c = A;
            A = B;
            B = c;
        }

        int C = 3 * A - A - B;

        cout << C << endl;
    }

    return 0;
}
