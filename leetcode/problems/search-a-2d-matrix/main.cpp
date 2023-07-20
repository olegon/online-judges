/*
74. Search a 2D Matrix
https://leetcode.com/problems/search-a-2d-matrix
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;

            const vector<int> &v = matrix[m];
            int firstElement = v[0];
            int lastElement = v[v.size() - 1];

            if (target >= firstElement && target <= lastElement) return bsearch(v, target) > -1;
            else if (target < firstElement) r = m - 1;
            else l = m + 1; 
        }

        return false;
    }

    int bsearch(const vector<int> &v, int target) {
        int l = 0;
        int r = v.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (target == v[m]) return m;
            else if (target < v[m]) r = m - 1;
            else l = m + 1;
        }

        return -1;
    }
};

// int main(void) {
//     ios::sync_with_stdio(false);

//     return EXIT_SUCCESS;
// }
