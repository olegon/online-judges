/*
Assigning Teams
https://www.urionlinejudge.com.br/judge/pt/problems/view/2345
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    vector<int> v;

    for (int i = 0; i < 4; i++) {
        int s;

        cin >> s;

        v.push_back(s);
    }

    sort(v.begin(), v.end());

    cout << abs((v[0] + v[3]) - (v[1] + v[2])) << endl;

    return 0;
}
