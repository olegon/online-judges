#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int X, Y, Z,
        A, B, C,
        S;

    cin >> X >> Y >> Z;
    // scanf("%d %d %d", &X, &Y, &Z);

    A = 0 * X + 2 * Y + 4 * Z;
    B = 2 * X + 0 * Y + 2 * Z;
    C = 4 * X + 2 * Y + 0 * Z;
    S = min(min(A, B), C);
    // No C++, a função min já vem definida em <algorithm>
    // #define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

    cout << S << endl;
    // printf("%d\n", S);

    return EXIT_SUCCESS;
    // return 0;
    // Ok, ai já é demais...
}
