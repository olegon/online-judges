/*
69. Sqrt(x)
https://leetcode.com/problems/sqrtx
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        else if (x == 1) return 1;
        else {
            int l = 1;
            int r = x;
            int best = 1;

            while (l <= r) {
                int m = l + (r - l) / 2;

                if (m == x / m) return m;
                else if (m > x / m) r = m - 1;
                else {
                    best = m;
                    l = m + 1;
                }
            }

            return best;
        }
    }
};