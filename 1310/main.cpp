/*
Lucro
https://www.urionlinejudge.com.br/judge/pt/problems/view/1310
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int DIAS, CUSTO_POR_DIA;

    while (cin >> DIAS >> CUSTO_POR_DIA) {
        int maiorLucro = 0,
            maiorLucroNoIntervalo = 0;
            
        for (int i = 0; i < DIAS; i++) {
            int receita, lucro;

            cin >> receita;
            lucro = receita - CUSTO_POR_DIA;            
            
            maiorLucroNoIntervalo = max(0, maiorLucroNoIntervalo + lucro);
            maiorLucro = max(maiorLucro, maiorLucroNoIntervalo);
        }

        cout << maiorLucro << endl;
    }

    return EXIT_SUCCESS;
}
