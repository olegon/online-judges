/*
Batalha de Pomekons
https://www.urionlinejudge.com.br/judge/pt/problems/view/2221
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int T;

    cin >> T;

    while (T-- > 0) {
      int B,
          AX, DX, LX,
          AY, DY, LY;

      cin >> B;
      cin >> AX >> DX >> LX;
      cin >> AY >> DY >> LY;

      double RX = 1.0 * (AX + DX) / 2;
      if (LX % 2 == 0) RX += B;

      double RY = 1.0 * (AY + DY) / 2;
      if (LY % 2 == 0) RY += B;

      if (abs(RX - RY) < 0.001) cout << "Empate\n";
      else if (RX > RY) cout << "Dabriel\n";
      else cout << "Guarte\n";
    }

    return 0;
}
