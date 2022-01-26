/*
1. Two Sum
https://leetcode.com/problems/two-sum/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // O(n * lg n)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ordered = nums;

        sort(ordered.begin(), ordered.end());
        vector<int> resp;
        
        auto current = ordered.begin();
        auto end = ordered.end();
        while (current != end) {
            int currentNumber = *current;
            int desired = target - currentNumber;

            if (binary_search(current + 1, end, desired)) {
                if (currentNumber == desired) {
                    size_t idx = indexOf(nums, currentNumber, 0);
                    resp.push_back(idx);
                    resp.push_back(indexOf(nums, desired, idx + 1));
                }
                else {
                    resp.push_back(indexOf(nums, currentNumber, 0));
                    resp.push_back(indexOf(nums, desired, 0));
                }
                
                break;
            }

            current++;
        }
     
        return resp;
    }

    size_t indexOf(vector<int> &nums, int value, size_t i) const {
        for (; i < nums.size(); i++) {
            if (nums[i] == value) break;
        }

        return i;
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
