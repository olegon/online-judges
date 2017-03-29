/*
Escultura à Laser
https://www.urionlinejudge.com.br/judge/pt/problems/view/1107
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int ligacoes(int A, int C, vector<int> &alturas);

int main(void) {
    ios::sync_with_stdio(false);

    int A, C;
    
    while (cin >> A >> C, A != 0 || C != 0) {
        vector<int> alturas(C);

        for (int i = 0; i < C; i++) cin >> alturas[i];

        cout << ligacoes(A, C, alturas) << '\n';
    }

    return EXIT_SUCCESS;
}

int ligacoes(int A, int C, vector<int> &alturas) {
    int h = A;
    int ligou = 0;

    for (int i = 0; i < C; i++) {
        // Se a altura atual (altura[i]) for menor que a última altura (h),
        // então significa que a máquina terá um trabalho a mais para perfurar
        // igual a (h - alturas[i])
        if (alturas[i] < h) {
            ligou += h - alturas[i];
        }

        h = alturas[i];
    }
    
    return ligou;
}