/*
Pedra-papel-tesoura-lagarto-Spock
https://www.urionlinejudge.com.br/judge/pt/problems/view/1873
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum JOGADOR_GANHADOR {
    PRIMEIRO_JOGADOR,
    SEGUNDO_JOGADOR,
    NENHUM_GANHADOR
};

JOGADOR_GANHADOR quemGanha(string &primeiro, string segundo);

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    while(N-- > 0) {
        string a, b;
        cin >> a >> b;

        JOGADOR_GANHADOR ganhador = quemGanha(a, b);

        if (ganhador == PRIMEIRO_JOGADOR) cout << "rajesh\n";
        else if (ganhador == SEGUNDO_JOGADOR) cout << "sheldon\n";
        else cout << "empate\n";
    }

    return EXIT_SUCCESS;
}

/*
    Tesoura corta papel
    Papel cobre pedra
    Pedra derruba lagarto
    Lagarto adormece Spock
    Spock derrete tesoura
    Tesoura prende lagarto
    Lagarto come papel
    Papel refuta Spock
    Spock vaporiza pedra
    Pedra quebra tesoura
*/
JOGADOR_GANHADOR quemGanha(string &primeiro, string segundo) {
    if (primeiro == "tesoura" && segundo == "papel") return PRIMEIRO_JOGADOR;
    else if (segundo == "tesoura" && primeiro == "papel") return SEGUNDO_JOGADOR;

    if (primeiro == "papel" && segundo == "pedra") return PRIMEIRO_JOGADOR;
    else if (segundo == "papel" && primeiro == "pedra") return SEGUNDO_JOGADOR;

    if (primeiro == "pedra" && segundo == "lagarto") return PRIMEIRO_JOGADOR;
    else if (segundo == "pedra" && primeiro == "lagarto") return SEGUNDO_JOGADOR;

    if (primeiro == "lagarto" && segundo == "spock") return PRIMEIRO_JOGADOR;
    else if (segundo == "lagarto" && primeiro == "spock") return SEGUNDO_JOGADOR;

    if (primeiro == "spock" && segundo == "tesoura") return PRIMEIRO_JOGADOR;
    else if (segundo == "spock" && primeiro == "tesoura") return SEGUNDO_JOGADOR;

    if (primeiro == "tesoura" && segundo == "lagarto") return PRIMEIRO_JOGADOR;
    else if (segundo == "tesoura" && primeiro == "lagarto") return SEGUNDO_JOGADOR;

    if (primeiro == "lagarto" && segundo == "papel") return PRIMEIRO_JOGADOR;
    else if (segundo == "lagarto" && primeiro == "papel") return SEGUNDO_JOGADOR;

    if (primeiro == "papel" && segundo == "spock") return PRIMEIRO_JOGADOR;
    else if (segundo == "papel" && primeiro == "spock") return SEGUNDO_JOGADOR;

    if (primeiro == "spock" && segundo == "pedra") return PRIMEIRO_JOGADOR;
    else if (segundo == "spock" && primeiro == "pedra") return SEGUNDO_JOGADOR;

    if (primeiro == "pedra" && segundo == "tesoura") return PRIMEIRO_JOGADOR;
    else if (segundo == "pedra" && primeiro == "tesoura") return SEGUNDO_JOGADOR;
    
    return NENHUM_GANHADOR;
}
