/*
Leitura Múltipla
https://www.urionlinejudge.com.br/judge/pt/problems/view/1262
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int ciclos(string &rastro, int processos);
int ciclos(string &rastro, int processos, size_t i, int processosUsados);

int main(void) {
    ios::sync_with_stdio(false);

    string rastro;
    int processos;

    while (cin >> rastro >> processos >> ws) {
        cout << ciclos(rastro, processos) << endl;
    }

    return EXIT_SUCCESS;
}

int ciclos(string &rastro, int processos) {
    return ciclos(rastro, processos, 0, 0);
}

int ciclos(string &rastro, int processos, size_t i, int processosUsados) {
    if (i < rastro.size()) {
        // Escrita -> Mais um ciclo
        if (rastro[i] == 'W') return 1 + ciclos(rastro, processos, i + 1, 0);
        // Primeira leitra -> Mais um ciclo
        else if (processosUsados == 0) return 1 + ciclos(rastro, processos, i + 1, 1);
        // Se todos estiverem sendo usados, aguardar finalização e continuar
        else if (processosUsados == processos) return ciclos(rastro, processos, i, 0);
        // Senão paralelizar
        else return ciclos(rastro, processos, i + 1, processosUsados + 1);
    }
    else return 0;
}
