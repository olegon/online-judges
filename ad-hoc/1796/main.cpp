#include <iostream>

using namespace std;

int main(void) {
    int Q,
        A = 0;

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int R;

        cin >> R;

        if (R == 0) A++;
    }

    if (A > Q / 2) {
        cout << "Y\n";
    }
    else {
        cout << "N\n";
    }

    return 0;
}
