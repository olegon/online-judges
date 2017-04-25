/*
Hello Galaxy
https://www.urionlinejudge.com.br/judge/pt/problems/view/1515
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Mensagem {
    string nomeDoPlaneta;
    int anoDeRecebimento;
    int tempoDeViagem;
    int anoDeOrigem;
};

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N, N != 0) {
        vector<Mensagem*> mensagens(N);

        for (int i = 0; i < N; i++) {
            Mensagem *mensagem = new Mensagem();

            cin >> mensagem->nomeDoPlaneta
                >> mensagem->anoDeRecebimento
                >> mensagem->tempoDeViagem;

            mensagem->anoDeOrigem = mensagem->anoDeRecebimento - mensagem->tempoDeViagem;

            mensagens[i] = mensagem;
        }

        sort(mensagens.begin(), mensagens.end(), [] (Mensagem *a, Mensagem *b) -> bool {
            return a->anoDeOrigem < b->anoDeOrigem;
        });

        cout << mensagens[0]->nomeDoPlaneta << endl;

        for (auto mensagem : mensagens) {
            delete mensagem;
        }        
    }    

    return EXIT_SUCCESS;
}
