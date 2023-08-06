/*
112. Path Sum
https://leetcode.com/problems/path-sum
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
    bool hasPathSum(const TreeNode* root, int targetSum) const {
        if (root == nullptr) return false;
        else if (root->left == nullptr && root->right == nullptr) return targetSum == root->val;
        else return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
