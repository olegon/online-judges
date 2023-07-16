/*
1. Two Sum
https://leetcode.com/problems/two-sum
*/

#include <bits/stdc++.h>

using namespace std;

// O(n * lg n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) const {
         vector<int> resp;
        
        if (target % 2 == 0) {
            int half = target / 2;

            for (size_t i = 0; i < nums.size(); i++) {
                if (nums[i] == half) {
                    resp.push_back(i);
                }

                if (resp.size() == 2) return resp;
            }
        }
        resp.clear();

        vector<int> ordered = nums;

        sort(ordered.begin(), ordered.end());
       
        auto current = ordered.begin();
        auto end = ordered.end();
        while (current != end) {
            int currentNumber = *current;
            int desired = target - currentNumber;

            if (binary_search(current + 1, end, desired)) {
                resp.push_back(indexOf(nums, currentNumber));
                resp.push_back(indexOf(nums, desired));
                
                break;
            }

            current++;
        }
     
        return resp;
    }

    size_t indexOf(vector<int> &nums, int value) const {
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == value) return i;
        }

        return nums.size();
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    int target;
    cin >> target;

    int count;
    cin >> count;

    vector<int> nums;
    while (count-- != 0) {
        int num;

        cin >> num;

        nums.push_back(num);
    }

    Solution s;
    vector<int> resp = s.twoSum(nums, target);

    for (int num : resp) {
        cout << num << endl;
    }

    return EXIT_SUCCESS;
}
