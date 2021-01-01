/*
Sorting: Bubble Sort
https://www.hackerrank.com/challenges/ctci-bubble-sort
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    vector<int> ARR(N);

    for (int i = 0; i < N; i++) {
        cin >> ARR[i];
    };

    int swaps = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (ARR[j] > ARR[j + 1]) {
                int aux = ARR[j];
                ARR[j] = ARR[j + 1];
                ARR[j + 1] = aux;
                swaps++;
            }
        }
    }

    cout << "Array is sorted in " << swaps << " swaps." << endl;
    cout << "First Element: " << ARR[0] << endl;
    cout << "Last Element: " << ARR[N - 1] << endl;
    
    return EXIT_SUCCESS;
}
