/*
The Longest Common Subsequence
https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

Studying Cormen's book!
*/

#include <bits/stdc++.h>

using namespace std;

int lcs_bottom_up_value(const vector<vector<int>> &mat, int i, int j) {
    if (i < 0 || j < 0) return 0;

    return mat[i][j];
}

vector<int> lcs_bottom_up(vector<int> &a, vector<int> &b) {
    auto mat = vector<vector<int>>(a.size(), vector<int>(b.size()));

    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) mat[i][j] = lcs_bottom_up_value(mat, i - 1, j - 1) + 1;
            else mat[i][j] = max(lcs_bottom_up_value(mat, i - 1, j), lcs_bottom_up_value(mat, i, j - 1));
        }
    }

    // for (size_t i = 0; i < a.size(); i++) {
    //     for (size_t j = 0; j < b.size(); j++) {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    int i = a.size() - 1;
    int j = b.size() - 1;
    int idx = mat.back().back() - 1;
    vector<int> result = vector<int>(idx + 1);

    while (i >= 0 && j >= 0) {
        // cout << "[debug]" << "; ";
        // cout << "i = " << i << "; ";
        // cout << "j = " << j << "; ";
        // cout << "a[i] = " << a[i] << "; ";
        // cout << "b[j] = " << b[j] << "; ";
        // cout << endl;

        if (a[i] == b[j]) {
            result[idx--] = a[i];
            i--;
            j--;
        }
        else {
            auto option01 = lcs_bottom_up_value(mat, i - 1, j);
            auto option02 = lcs_bottom_up_value(mat, i, j - 1);

            if (option01 > option02) i--;
            else j--;
        }
    }

    return result;
}



int _lcs_recursive(const vector<int> &a, const vector<int> &b, size_t i, size_t j, vector<vector<int>> &dp) {
    if (i >= a.size() || j >= b.size()) return 0;

    if (dp[i][j] == -1) {
        if (a[i] == b[j]) {
            dp[i][j] = _lcs_recursive(a, b, i + 1, j + 1, dp) + 1;
        }
        else {
            dp[i][j] = max(
                _lcs_recursive(a, b, i + 1, j, dp),
                _lcs_recursive(a, b, i, j + 1, dp)
            );
        }
    }

    // cout << "[debug]" << "; ";
    // cout << "i = " << i << "; ";
    // cout << "j = " << j << "; ";
    // cout << "dp[i][j] = " << dp[i][j] << "; ";
    // cout << endl;
    
    return dp[i][j];
}


vector<int> lcs_recursive(vector<int> a, vector<int> b) {
    auto dp = vector<vector<int>>(a.size(), vector<int>(b.size(), -1));

    _lcs_recursive(a, b, 0, 0, dp);

    // for (size_t i = 0; i < a.size(); i++) {
    //     for (size_t j = 0; j < b.size(); j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    size_t i = 0;
    size_t j = 0;
    vector<int> result;

    while (i < a.size() && j < b.size()) {
        // cout << "[debug]" << "; ";
        // cout << "i = " << i << "; ";
        // cout << "j = " << j << "; ";
        // cout << "a[i] = " << a[i] << "; ";
        // cout << "b[j] = " << b[j] << "; ";
        // cout << endl;

        if (a[i] == b[j]) {
            result.push_back(a[i]);
            i++;
            j++;
        }
        else {
            auto option01 = i + 1 < a.size()
                            ? dp[i + 1][j]
                            : -1;
            auto option02 = j + 1 < b.size()
                            ? dp[i][j + 1]
                            : -1;

            if (option01 > option02) i++;
            else j++;
        }
    }

    return result;
}

int main(void) {
    ios::sync_with_stdio(false);

    size_t ASIZE, BSIZE;

    cin >> ASIZE >> BSIZE;

    vector<int> A(ASIZE), B(BSIZE);

    for (size_t i = 0; i < ASIZE; i++) {
        cin >> A[i];
        // cout << A[i] << " ";
    }
    // cout << endl;

    for (size_t i = 0; i < BSIZE; i++) {
        cin >> B[i];
        // cout << B[i] << " ";
    }
    // cout << endl;

    vector<int> result = lcs_recursive(A, B);

    if (!result.empty()) {
        cout << result[0];

        for (size_t i = 1; i < result.size(); i++) cout << " " << result[i];
    }

    cout << endl;

    return EXIT_SUCCESS;
}
