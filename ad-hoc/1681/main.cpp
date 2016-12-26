#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    while (N-- > 0) {
        int AX, AY,
            BX, BY,
            CX, CY,
            DX, DY,
            RX, RY;

        cin >> AX >> AY >> BX >> BY >> CX >> CY >> DX >> DY >> RX >> RY;

        if (RX >= AX && RX <= BX
            && RY >= AY && RY <= DY) cout << 1;
        else cout << 0;

        cout << '\n';
    }

    return 0;
}
