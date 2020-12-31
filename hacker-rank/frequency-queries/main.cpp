/*
Frequency Queries
https://www.hackerrank.com/challenges/frequency-queries
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int Q;

    cin >> Q;

    unordered_map<int, int> counts;
    unordered_map<int, unordered_set<int>> countToNumbersMap;


    for (int i = 0; i < Q; i++) {
        int C, P;

        cin >> C >> P;

        if (C == 1) /* insert*/ {
            int currentCount = counts[P];
            int nextCount = currentCount + 1;

            countToNumbersMap[currentCount].erase(P);
            countToNumbersMap[nextCount].insert(P);

            counts[P] = nextCount;
        }
        else if (C == 2) /* erase */ {
            int currentCount = counts[P];
            int nextCount = currentCount - 1;

            if (currentCount == 0) {
                continue;
            }
            else {
                countToNumbersMap[currentCount].erase(P);
                countToNumbersMap[nextCount].insert(P);
            }

            counts[P] = nextCount;
        }
        else if (C == 3) /* print */ {
            if (countToNumbersMap[P].empty()) {
                cout << 0 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
    }

    return EXIT_SUCCESS;
}
 