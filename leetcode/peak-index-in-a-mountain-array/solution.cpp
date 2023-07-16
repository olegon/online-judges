/*
852. Peak Index in a Mountain Array
https://leetcode.com/problems/peak-index-in-a-mountain-array/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (m == 0) m++;
            if (m == arr.size() - 1) m--;

            if (arr[m] > arr[m - 1] && arr[m] > arr[m + 1]) return m;
            else if (arr[m - 1] < arr[m]) l = m + 1;
            else r = m - 1;
        }

        return -1;
    }
};
