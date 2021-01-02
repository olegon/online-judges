/*
Fraudulent Activity Notifications
https://www.hackerrank.com/challenges/fraudulent-activity-notifications
*/

#include <bits/stdc++.h>

using namespace std;

int calculateThresholdFromTheLastDays(vector<int> &COUNTS, int D) {
    // for (int i = 0; i < 10; i++) {
    //     cout << i << " -> " << COUNTS[i] << "       ";
    // }
    // cout << endl;

    if (D % 2 == 1) {
        int half = D / 2 + 1;

        int count = 0;
        int median = 0;

        for (int i = 0; i < 201 && count < half; i++) {
            count += COUNTS[i];
            median = i;
        }

        return median * 2;
    }
    else {
        int halfLeft = D / 2;
        int halfRight = D / 2 + 1;

        int count = 0;
        int numberFromHalfLeft = 0;
        int numberFromHalfRight = 0;

        for (int i = 0; i < 201 && count < halfLeft; i++) {
            count += COUNTS[i];
            numberFromHalfLeft = i;
        }

        count = 0;
        for (int i = 0; i < 201 && count < halfRight; i++) {
            count += COUNTS[i];
            numberFromHalfRight = i;
        }

        // cout << numberFromHalfLeft << endl;
        // cout << numberFromHalfRight << endl;

        // median = 1.0 * (numberFromHalfLeft + numberFromHalfRight) / 2
        // threshold = media * 2;
        return 1.0 * (numberFromHalfLeft + numberFromHalfRight);
    }
}

int main(void) {
    ios::sync_with_stdio(false);

    int N, D;

    cin >> N >> D;

    vector<int> TRANSATIONS(N);

    for (int i = 0; i < N; i++) {
        cin >> TRANSATIONS[i];
    }

    vector<int> COUNTS(201, 0);

    for (int i = 0; i < D; i++) {
        COUNTS[TRANSATIONS[i]]++;
    }

    int notifications = 0;
    for (int i = D; i < N; i++) {
        int threshold = calculateThresholdFromTheLastDays(COUNTS, D);

        if (TRANSATIONS[i] >= threshold) {
            notifications++;
        }

        COUNTS[TRANSATIONS[i - D]]--;
        COUNTS[TRANSATIONS[i]]++;
    }

    cout << notifications << endl;


    return EXIT_SUCCESS;
}

