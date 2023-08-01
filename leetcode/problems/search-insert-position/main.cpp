/*
35. Search Insert Position
https://leetcode.com/problems/search-insert-position
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (left == right) {
                if (nums[mid] == target) return mid;
                else break; 
            }
            
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        if (nums[left] < target) return left + 1;
        else return left;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    Solution s;

    vector<int> v = { 1, 3, 5, 6 };

    cout << (s.searchInsert(v, 5) == 2) << endl;
    cout << (s.searchInsert(v, 2) == 1) << endl;
    cout << (s.searchInsert(v, 7) == 4) << endl;

    return EXIT_SUCCESS;
}
