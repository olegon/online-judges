/*
Voleibol
https://www.urionlinejudge.com.br/judge/pt/problems/view/2310
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N,
        TA = 0, TB = 0, TC = 0,
        CA = 0, CB = 0, CC = 0;

    cin >> N >> ws;

    for (int i = 0; i < N; i++) {
        string NAME;

        getline(cin, NAME);

        int ta, tb, tc,
            ca, cb, cc;

        cin >> ta >> tb >> tc >> ws;

        TA += ta;
        TB += tb;
        TC += tc;        

        cin >> ca >> cb >> cc >> ws;

        CA += ca;
        CB += cb;
        CC += cc;
    }
    
    cout << "Pontos de Saque: " << fixed << setprecision(2) << (100.0 * CA / TA) << " %." << '\n';
    cout << "Pontos de Bloqueio: " << fixed << setprecision(2) << (100.0 * CB / TB) << " %." << '\n';
    cout << "Pontos de Ataque: " << fixed << setprecision(2) << (100.0 * CC / TC) << " %." << endl;

    return EXIT_SUCCESS;
}
