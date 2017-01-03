/*
Galopeira
https://www.urionlinejudge.com.br/judge/pt/problems/view/2147
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int C;

    cin >> C;
    cin.ignore(1);

    while(C-- > 0) {
        string line;

        getline(cin, line);

        double t = line.length() * 0.01;

        cout << fixed << setprecision(2) << t << endl;
    }

    return 0;
}
