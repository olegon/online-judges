/*
Horas e Minutos
https://www.urionlinejudge.com.br/judge/pt/problems/view/1300
*/

#include <iostream>

using namespace std;

bool eh_possivel(int A);

int main(void) {
    ios::sync_with_stdio(false);

    int A;

    while (cin >> A) {
        if (eh_possivel(A)) cout << "Y\n";
        else cout << "N\n";
    }

    return 0;
}

bool eh_possivel(int A) {
    int r = A % 6;

    return (r == 0) ;
}
