/*
704. Binary Search
https://leetcode.com/problems/binary-search
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        // esse valor pode ficar negativo, o que é um problema se a variável fosse size_t
        int right = nums.size() - 1;
        
        while (left <= right) {
            // isso pode dar overflow! (:
            // int mid = (left + right) / 2

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        return -1;
    }
};
