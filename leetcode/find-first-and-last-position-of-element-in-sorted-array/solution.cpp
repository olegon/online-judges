/*
34. Find First and Last Position of Element in Sorted Array
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l, r, bestLeft, bestRight;

        l = 0;
        r = nums.size() - 1;
        bestLeft = bestRight = -1;

        int idx = bsearch(nums, l, r, target);

        if (idx != -1) {
            bestLeft = bestRight = idx;
            
            int bestLeftSoFar = bestLeft;
            int bestRightSoFar = bestRight;

            while (true) {
                bestLeftSoFar = bsearch(nums, l, bestLeftSoFar - 1, target);

                if (bestLeftSoFar == -1) break;
                else bestLeft = bestLeftSoFar;
            }

            while (true) {
                bestRightSoFar = bsearch(nums, bestRightSoFar + 1, r, target);

                if (bestRightSoFar == -1) break;
                else bestRight = bestRightSoFar;
            }
        }

        return { bestLeft, bestRight };
    }

    int bsearch(vector<int>& nums, int l, int r, int target) {
        if (l > r) return -1;

        int m = (l + r) / 2;

        if (nums[m] == target) return m;
        else if (nums[m] < target) return bsearch(nums, m + 1, r, target);
        else return bsearch(nums, l, m - 1, target);
    }
};
