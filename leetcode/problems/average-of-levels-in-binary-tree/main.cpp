/*
637. Average of Levels in Binary Tree
https://leetcode.com/problems/average-of-levels-in-binary-tree
*/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<double, size_t>> sumAndCountByLevel;

        averageOfLevels(root, 0, sumAndCountByLevel);
        
        vector<double> result;
        for (auto &pair : sumAndCountByLevel) {
            result.push_back(pair.first / pair.second);
        }

        return result;
    }

    void averageOfLevels(const TreeNode* root, size_t level, vector<pair<double, size_t>>& sumAndCountByLevel) {
        if (root == nullptr) return;

        if (level >= sumAndCountByLevel.size()) {
            sumAndCountByLevel.push_back(make_pair(0, 0));
        }

        sumAndCountByLevel[level].first += root->val;
        sumAndCountByLevel[level].second++;

        averageOfLevels(root->left, level + 1, sumAndCountByLevel);
        averageOfLevels(root->right, level + 1, sumAndCountByLevel);
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
