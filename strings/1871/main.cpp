#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N, M;

    while (cin >> N >> M, N != 0 || M != 0) {
        int R = N + M;
        stack<int> algs;

        while (R != 0) {
            algs.push(R % 10);
            R /= 10;
        }

        while (!algs.empty()) {
            int a = algs.top();

            if (a != 0) cout << a;

            algs.pop();
        }
        cout << '\n';
    }

    return 0;
}
