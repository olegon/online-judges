#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N,
        LA, LB,
        SA, SB;

    cin >> N;
    cin >> LA >> LB;
    cin >> SA >> SB;

    if (N >= LA && N <= LB && N >= SA && N <= SB) cout << "possivel\n";
    else cout << "impossivel\n";

    return 0;
}
