/*
{name}
{url}
*/

#include <iostream>

using namespace std;

void imprimir(int hora, int minuto, int evento);

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;
    
    while (N-- > 0) {
        int hora,  minuto, evento;

        cin >> hora >> minuto >> evento;

        imprimir(hora, minuto, evento);
    }


    return 0;
}

void imprimir(int hora, int minuto, int evento) {
    if (hora < 10) cout << '0';

    cout << hora;

    cout << ":";

    if (minuto < 10) cout << '0';

    cout << minuto;

    cout << " - ";

    if (evento == 1) {
        cout << "A porta abriu!\n";
    }
    else {
        cout << "A porta fechou!\n";
    }
}
