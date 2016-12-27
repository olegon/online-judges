/*
Ida à Feira
https://www.urionlinejudge.com.br/judge/pt/problems/view/1281
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main (void) {
    int quantidadeDeViagens,
        quantidadeDeFrutas,
        quantidadeDeItens;

    double  preco,
            total;

    string nomeDaFruta;

    cout.precision(2);

    cin >> quantidadeDeViagens;

    while (quantidadeDeViagens-- > 0) {
        map<string, double> precosDasFrutas;

        cin >> quantidadeDeFrutas;

        while (quantidadeDeFrutas-- > 0) {
            cin >> nomeDaFruta >> preco;

            precosDasFrutas[nomeDaFruta] = preco;
        }

        cin >> quantidadeDeFrutas;

        total = 0;
        while (quantidadeDeFrutas-- > 0) {
            cin >> nomeDaFruta >> quantidadeDeItens;

            total += precosDasFrutas[nomeDaFruta] * quantidadeDeItens;
        }

        cout << "R$ " << fixed << total << endl;
    }

    return 0;
}
