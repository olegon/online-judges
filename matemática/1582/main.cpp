#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool tripla_pitagoria(int CA, int CB, int H);
bool tripla_pitagoria_primitiva(int CA, int CB, int H);

int main(void) {
    ios::sync_with_stdio(false);

    int L[3];

    while (cin >> L[0] >> L[1] >> L[2]) {
        sort(L, L + 3);

        if (tripla_pitagoria(L[0], L[1], L[2])) {
            if (tripla_pitagoria_primitiva(L[0], L[1], L[2])) {
                cout << "tripla pitagorica primitiva\n";
            }
            else {
                cout << "tripla pitagorica\n";
            }
        }
        else {
            cout << "tripla\n";
        }
    }

    return 0;
}

bool tripla_pitagoria(int CA, int CB, int H) {
    return CA * CA + CB * CB == H * H;
}

bool tripla_pitagoria_primitiva(int CA, int CB, int H) {
    int limit = sqrt(H);

    if (CA % 2 == 0 && CB % 2 == 0 && H % 2 == 0) return false;

    for (int i = 3; i <= limit; i += 2) {
        if (CA % i == 0 && CB % i == 0 && H % i == 0) return false;
    }

    return true;
}
