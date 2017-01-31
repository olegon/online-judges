/*
Camisetas
https://www.urionlinejudge.com.br/judge/pt/problems/view/1258
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum cor {
    BRANCO = 0,
    VERMELHO = 1
};

enum tamanho {
    P = 0,
    M = 1,
    G = 2
};

struct Pessoa {
    string nome;
    cor corDaCamisa;
    tamanho tamanhoDaCamisa;
};

int main(void) {
    ios::sync_with_stdio(false);

    int N;
    bool notFirst = false;

    while (cin >> N >> ws, N != 0) {
        if (notFirst) {
            cout << '\n';
        }

        notFirst = true;

        vector<Pessoa*> pessoas;

        while (N-- > 0) {
            Pessoa *pessoaPtr = new Pessoa();
            string corStr;
            char tamanhoChar;

            getline(cin >> ws, pessoaPtr->nome);
            cin >> corStr >> tamanhoChar >> ws;

            if (corStr == "branco") pessoaPtr->corDaCamisa = BRANCO;
            else pessoaPtr->corDaCamisa = VERMELHO;

            if (tamanhoChar == 'P') pessoaPtr->tamanhoDaCamisa = P;
            else if (tamanhoChar == 'M') pessoaPtr->tamanhoDaCamisa = M;
            else pessoaPtr->tamanhoDaCamisa = G;

            pessoas.push_back(pessoaPtr);
        }

        sort(pessoas.begin(), pessoas.end(), [] (Pessoa *a, Pessoa *b) -> bool {
            if (a->corDaCamisa == b->corDaCamisa) {
                if (a->tamanhoDaCamisa == b->tamanhoDaCamisa) {
                    return a->nome < b->nome;
                }
                else return a->tamanhoDaCamisa < b->tamanhoDaCamisa;
            }
            else return a->corDaCamisa < b->corDaCamisa;
        });

        for (Pessoa *pessoaPtr : pessoas) {
            if (pessoaPtr->corDaCamisa == BRANCO) cout << "branco";
            else cout << "vermelho";

            cout << ' ';

            if (pessoaPtr->tamanhoDaCamisa == P) cout << 'P';
            else if (pessoaPtr->tamanhoDaCamisa == M) cout << 'M';
            else cout << 'G';

            cout << ' ';

            cout << pessoaPtr->nome << '\n';

            delete pessoaPtr;
        }
    }

    return 0;
}
