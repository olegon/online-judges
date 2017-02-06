/*
Getline Three - Calçados
https://www.urionlinejudge.com.br/judge/pt/problems/view/1218
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int caso = 1,
        NUMERO;

    bool podePular = false;

    while (cin >> NUMERO) {
        if (podePular) cout << '\n';
        else podePular = true;

        string line;
        int numero,
            feminino = 0,
            masculino = 0;
        char genero;

        getline(cin >> ws, line);

        stringstream ss(line);

        cout << "Caso " << caso++ << ":\n";
        while (ss >> numero >> genero) {
            if (numero == NUMERO) {
                if (genero == 'F') feminino++;
                else masculino++;
            }
        }

        cout << "Pares Iguais: " << (feminino + masculino) << '\n';
        cout << "F: " << feminino << '\n';
        cout << "M: " << masculino << '\n';
    }



    return 0;
}
