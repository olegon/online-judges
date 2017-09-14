/*
A Biblioteca do Senhor Severino
https://www.urionlinejudge.com.br/judge/pt/problems/view/2137
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N >> ws) {
        vector<string> codigos(N);
        
        while (N-- > 0) {
            getline(cin, codigos[N]);
        }

        sort(codigos.begin(), codigos.end());

        for (auto codigo : codigos) {
            cout << codigo << '\n';
        }
    }

    return EXIT_SUCCESS;
}
