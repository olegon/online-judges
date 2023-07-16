/*
34. Find First and Last Position of Element in Sorted Array
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left, right, bestLeft, bestRight, bestLeftSoFar, bestRightSoFar;

        left = 0;
        right = nums.size() - 1;

        bestLeft = bestRight = bestLeftSoFar = bestRightSoFar = bsearch(nums, left, right, target);

        while (bestLeftSoFar != -1) {
            bestLeftSoFar = bsearch(nums, left, bestLeftSoFar - 1, target);

            if (bestLeftSoFar != -1) bestLeft = bestLeftSoFar;
        }

        while (bestRightSoFar != -1) {
            bestRightSoFar = bsearch(nums, bestRightSoFar + 1, right, target);

            if (bestRightSoFar != -1) bestRight = bestRightSoFar;
        }

        return { bestLeft, bestRight };
    }

    int bsearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] == target) return m;
            else if (nums[m] < target) l = m + 1;
            else r = m - 1;
        }

        return -1;
    }
};
