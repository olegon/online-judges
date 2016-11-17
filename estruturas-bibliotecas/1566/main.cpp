#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int NC;

    cin >> NC;

    while (NC-- > 0) {
        int N;
        vector<int> v;

        cin >> N;

        while (N-- > 0) {
            int H;

            cin >> H;

            v.push_back(H);
        }

        sort(v.begin(), v.end());

        for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
            if (it == v.begin()) cout << *it;
            else cout << ' ' << *it;
        }
        cout << '\n';
    }

    return 0;
}
