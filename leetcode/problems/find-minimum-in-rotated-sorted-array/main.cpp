/*
153. Find Minimum in Rotated Sorted Array
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;

            if (nums[l] > nums[r]) {
                if (m > 0 && nums[m] < nums[m - 1]) return nums[m];
                else if (nums[m] > nums[r]) l = m + 1;
                else r = m - 1;
            }
            else break;
        }

        return nums[l];
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
