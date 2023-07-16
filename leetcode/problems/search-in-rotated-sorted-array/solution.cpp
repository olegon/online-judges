/*
33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return findNumber(nums, 0, nums.size() - 1, target);
    }

    int findNumber(vector<int>& nums, int l, int r, int target) {
        int m = (l + r) / 2;

        if (l > r) return -1;

        if (nums[m] == target) return m;
        else if (nums[l] > nums[r]) {
            int left = findNumber(nums, l, m - 1, target);
            int right = findNumber(nums, m + 1, r, target);

            if (left != -1) return left;
            else if (right != -1) return right;
            return -1;
        }
        else if (nums[m] < target) return findNumber(nums, m + 1, r, target);
        else return findNumber(nums, l, m - 1, target);
    }
};
