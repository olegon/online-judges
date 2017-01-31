/*
Contando Carneirinhos
https://www.urionlinejudge.com.br/judge/pt/problems/view/1609
*/

#include <iostream>
#include <set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int T, N;

    cin >> T;

    while (T-- > 0) {
        set<int> s;

        cin >> N;

        while (N-- > 0) {
            int n;

            cin >> n;

            s.insert(n);
        }

        cout << s.size() << '\n';
    }

    return 0;
}
