/*
Minimum Swaps 2
https://www.hackerrank.com/challenges/minimum-swaps-2
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    vector<int> arr(N);
    unordered_map<int, int> numberIndexMap;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        numberIndexMap[arr[i]] = i;
    }

    int swaps = 0;

    for (int currentIndex = 0; currentIndex < N; currentIndex++) {
        int expectedNumber = currentIndex + 1;
        
        if (arr[currentIndex] != expectedNumber) {
            int expectedNumberIndex = numberIndexMap[expectedNumber];

            
            numberIndexMap[arr[currentIndex]] = expectedNumberIndex;
            numberIndexMap[expectedNumber] = currentIndex;

            arr[expectedNumberIndex] = arr[currentIndex];
            arr[currentIndex] = expectedNumber;

            swaps++;
        }
    }

    cout << swaps << endl;


    return EXIT_SUCCESS;
}
