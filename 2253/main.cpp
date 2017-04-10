/*
Validador de Senhas
https://www.urionlinejudge.com.br/judge/pt/problems/view/2253
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isSenhaValida(string &senha);

int main(void) {
    ios::sync_with_stdio(false);

    string senha;

    while (getline(cin, senha)) {
        if(isSenhaValida(senha)) cout << "Senha valida.\n";
        else cout << "Senha invalida.\n";
    }

    return EXIT_SUCCESS;
}

bool isSenhaValida(string &senha) {
    if (senha.length() < 6 || senha.length() > 32) return false;

    bool possuiMinuscula = false,
         possuiMaiuscula = false,
         possuiNumero  = false;

    for (auto c : senha) {
        if (c >= 'a' && c <= 'z') possuiMinuscula = true;
        else if (c >= 'A' && c <= 'Z') possuiMaiuscula = true;
        else if (c >= '0' && c <= '9') possuiNumero = true;
        else return false;
    }

    return possuiMinuscula && possuiMaiuscula && possuiNumero;
}
