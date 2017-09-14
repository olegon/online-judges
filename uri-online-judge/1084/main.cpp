/*
Apagando e Ganhando
https://www.urionlinejudge.com.br/judge/pt/problems/view/1084
*/

#include <iostream>
#include <cstdlib>
#include <deque>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N, D;    

    while (cin >> N >> D >> ws, N != 0 || D != 0) {
        string numero;        
        deque<char> digitos;
        int i, removidos;

        getline(cin, numero);

        for (i = 0, removidos = 0; i < N && removidos < D; i++) {
            char digito = numero[i];

            if (digitos.empty() || digito < digitos.back()) digitos.push_back(numero[i]);
            else {
                while (!digitos.empty() && digitos.back() < digito && removidos < D) {
                    digitos.pop_back();                    
                    removidos++;
                }    
                digitos.push_back(digito);         
            }
        }

        for (; i < N; i++) digitos.push_back(numero[i]);
        
        for (int i = 0, q = N - D; i < q; i++) {
            cout << digitos.front();
            digitos.pop_front();
        }
        cout << '\n';
    }    

    return EXIT_SUCCESS;
}
