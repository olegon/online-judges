/*
113. Path Sum II
https://leetcode.com/problems/path-sum-ii
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
private:
    void pathSum(TreeNode* node, int targetSum, vector<int> &currentPath, vector<vector<int>> &paths) {
        currentPath.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr && node->val == targetSum) paths.push_back(currentPath);
        if (node->left != nullptr) pathSum(node->left, targetSum - node->val, currentPath, paths);
        if (node->right != nullptr) pathSum(node->right, targetSum - node->val, currentPath, paths);

        currentPath.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;

        if (root != nullptr) {
            vector<int> currentPath;
            pathSum(root, targetSum, currentPath, paths);
        }
      
        return paths;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
