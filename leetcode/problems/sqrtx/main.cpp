/*
69. Sqrt(x)
https://leetcode.com/problems/sqrtx
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long uint64;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int bestGuess = 0;

        while (l <= r) {
            uint64 guess = (l + r) / 2;
            uint64 result = guess * guess;

            if (result <= x) bestGuess = guess;

            if (result == x) break;
            else if (result < x) l = guess + 1;
            else r = guess - 1;
        }

        return bestGuess; 
    }
};

// int main(void) {
//     ios::sync_with_stdio(false);

//     Solution s;

//     for (size_t i = 0; i < 1025; i++) {
//         int result = s.mySqrt(i);
//         cout << i << " => " << result << endl;
//     }

//     cout << 2147395599 << " => " << s.mySqrt(2147395599) << endl;

//     return EXIT_SUCCESS;
// }
