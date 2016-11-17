#include <iostream>
#include <vector>

using namespace std;

int hits(const vector<int> &alturas, const vector<char> &comandos, int N);

int main(void) {
    int N;

    cin >> N;

    while (N-- > 0) {
        int T;
        vector<int> alturas;
        vector<char> comandos;

        cin >> T;

        for (int i = 0; i < T; i++) {
            int H;

            cin >> H;

            alturas.push_back(H);
        }

        cin.ignore(1);

        for (int i = 0; i < T; i++) {
            char C;

            cin >> C;

            comandos.push_back(C);
        }

        cout << hits(alturas, comandos, T) << '\n';
    }

    return 0;
}

int hits(const vector<int> &alturas, const vector<char> &comandos, int T) {
    int count = 0;

    for (int i = 0; i < T; i++) {
        if (alturas[i] < 3 && comandos[i] == 'S') count++;
        else if (alturas[i] > 2 && comandos[i] == 'J') count++;
    }

    return count;
}
