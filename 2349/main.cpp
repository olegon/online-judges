/*
Farm Robot
https://www.urionlinejudge.com.br/judge/pt/problems/view/2349
*/

#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N, C, S;
    int count = 0;

    cin >> N >> C >> S;

    int pos = 1;

    if (pos == S) count++;

    for (int i = 0; i < C; i++) {
        int command;

        cin >> command;

        pos += command;

        if (pos > N) pos = 1;
        else if (pos < 1) pos = N;

        if (pos == S) count++;
    }

    cout << count << endl;

    return 0;
}
