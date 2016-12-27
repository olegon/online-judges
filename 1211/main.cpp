/*
Lista Telefônica Econômica
https://www.urionlinejudge.com.br/judge/pt/problems/view/1211
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;
    while (cin >> N) {
        cin.ignore(1);

        vector<string> numeros;

        for (int i = 0; i < N; i++) {
            string numero;
            getline(cin, numero);
            numeros.push_back(numero);
        }

        sort(numeros.begin(), numeros.end());

        int count = 0;

        for (int i = 1; i < N; i++) {
            for (size_t j = 0;
                j < numeros[i].length()
                && numeros[i - 1][j] == numeros[i][j]
                && (j == 0 || numeros[i - 1][j - 1] == numeros[i][j - 1]);
                j++) {
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}
