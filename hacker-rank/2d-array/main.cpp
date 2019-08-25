/*
2D Array - DS
https://www.hackerrank.com/challenges/2d-array/problem
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int ARR[6][6];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> ARR[i][j];
        }
    }

    int biggestSum = INT_MIN;
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            int sum = ARR[i - 1][j - 1] + ARR[i - 1][j] + ARR[i - 1][j + 1]
                                        + ARR[i][j]    
                   +  ARR[i + 1][j - 1] + ARR[i + 1][j] + ARR[i + 1][j + 1];

            biggestSum = max(sum, biggestSum);

            if (biggestSum == 63 /* == 7 * 9 */) goto RESULT;
        }
    }

RESULT:
    cout << biggestSum << endl;

    return EXIT_SUCCESS;
}
