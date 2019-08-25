/*
Jumping on the Clouds
https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
*/

#include <bits/stdc++.h>

using namespace std;

size_t jumpingOnClouds(vector<int> &C) {
    size_t jumps = 0,
        index = 0;

    while (index < C.size() - 1) {
        if (index + 2 < C.size() && C[index + 2] == 0) {
            index += 2;
        }
        else {
            index += 1;
        }

        jumps += 1;
    }

    return jumps;
}


int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    vector<int> C(N);

    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    cout << jumpingOnClouds(C) << endl;

    return EXIT_SUCCESS;
}
