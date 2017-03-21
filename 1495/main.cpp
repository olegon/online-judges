/*
Futebol
https://www.urionlinejudge.com.br/judge/pt/problems/view/1495
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct partida {
    int marcados;
    int sofridos;
    int diferenca;
};

int main(void) {
    ios::sync_with_stdio(false);

    int N, G;

    while (cin >> N >> G) {
        vector<partida*> partidas;

        for (int i = 0; i < N; i++) {
            partida* p = new partida();

            cin >> p->marcados >> p->sofridos;
            p->diferenca = p->marcados - p->sofridos;

            partidas.push_back(p);
        }

        sort(partidas.begin(), partidas.end(), [] (const partida *a, const partida *b) -> bool {
            return a->diferenca > b->diferenca;
        });

        int pontos = 0;

        for (partida *p : partidas) {
            if (p->diferenca > 0) pontos += 3;
            else if (p->diferenca == 0) /* Empate -> Vencer */{
                if (G == 0) pontos += 1;
                else {
                    pontos += 3;
                    G -= 1;
                }
            }
            else if (G + p->diferenca > 0) /* Derrota -> Vencer */ {
                G += p->diferenca - 1;
                pontos += 3;
            }
            else if (G + p->diferenca == 0) /* Derrota -> Empatar */ {                
                pontos += 1;
                G = 0;
            }
        }

        cout << pontos << '\n';
    }

    return EXIT_SUCCESS;
}
