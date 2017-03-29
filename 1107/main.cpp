/*
Escultura à Laser
https://www.urionlinejudge.com.br/judge/pt/problems/view/1107
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int ligacoes(int A, int C, vector<int> &alturas);
int ligacoes(int A, int C, vector<int> &alturas, int h);

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
    return ligacoes(A, C, alturas, A);
}

int ligacoes(int A, int C, vector<int> &alturas, int h) {
    if (h > 0) {
        int ligou = 0;
        int ligado = false;

        for (int i = 0; i < C; i++) {
            if (alturas[i] >= h) ligado = false;
            else if (!ligado) {
                ligado = true;
                ligou += 1;
            }
        }

        if (ligou == 0) return 0;
        else return ligou + ligacoes(A, C, alturas, h - 1);
    }
    else return 0;
}